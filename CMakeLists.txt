cmake_minimum_required(VERSION 3.16)
project(ciVulkCube)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Vulkan REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glm CONFIG REQUIRED)

# Находим glslc для компиляции шейдеров
find_program(GLSLC_EXECUTABLE glslc)
if(NOT GLSLC_EXECUTABLE)
    message(FATAL_ERROR "glslc not found. Please install Vulkan SDK.")
endif()

# Компилируем шейдеры
file(GLOB SHADER_FILES "shaders/*.glsl")
foreach(SHADER_FILE ${SHADER_FILES})
    get_filename_component(SHADER_NAME ${SHADER_FILE} NAME_WE)
    get_filename_component(SHADER_EXT ${SHADER_FILE} EXT)
    
    # Определяем тип шейдера по имени файла
    if(SHADER_NAME STREQUAL "vertex")
        set(SHADER_STAGE "vert")
    elseif(SHADER_NAME STREQUAL "fragment")
        set(SHADER_STAGE "frag")
    elseif(SHADER_NAME STREQUAL "fragment_lines")
        set(SHADER_STAGE "frag")
    else()
        set(SHADER_STAGE "vert") # По умолчанию
    endif()
    
    add_custom_command(
        OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/shaders/${SHADER_NAME}.spv"
        COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_CURRENT_BINARY_DIR}/shaders"
        COMMAND ${GLSLC_EXECUTABLE} -fshader-stage=${SHADER_STAGE} -o "${CMAKE_CURRENT_BINARY_DIR}/shaders/${SHADER_NAME}.spv" ${SHADER_FILE}
        DEPENDS ${SHADER_FILE}
        COMMENT "Compiling ${SHADER_FILE}"
    )
    list(APPEND SHADER_SPV_FILES "${CMAKE_CURRENT_BINARY_DIR}/shaders/${SHADER_NAME}.spv")
endforeach()

add_executable(ciVulkCube
    main.cpp
    cube.cpp
    sphere.cpp
    cube_app.cpp
    camera.cpp
    vulkan_helpers.cpp
)

target_include_directories(ciVulkCube PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(ciVulkCube PRIVATE Vulkan::Vulkan glfw glm::glm)

# Копируем скомпилированные шейдеры в папку с исполняемым файлом
add_custom_target(copy_shaders ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${CMAKE_CURRENT_BINARY_DIR}/shaders"
    "$<TARGET_FILE_DIR:ciVulkCube>/shaders"
    DEPENDS ${SHADER_SPV_FILES}
)
