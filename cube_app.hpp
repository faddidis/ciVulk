#pragma once
#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <memory>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "cube.hpp"
#include "sphere.hpp"
#include "camera.hpp"
#include "vulkan_helpers.hpp"

struct UniformBufferObject {
    alignas(16) glm::mat4 model;
    alignas(16) glm::mat4 view;
    alignas(16) glm::mat4 proj;
};

class CubeApp {
public:
    CubeApp();
    ~CubeApp();
    
    void run();

private:
    void initVulkan();
    void mainLoop();
    void cleanup();
    void createInstance();
    void createSurface();
    void pickPhysicalDevice();
    void createLogicalDevice();
    void createSwapChain();
    void createImageViews();
    void createRenderPass();
    void createDescriptorSetLayout();
    void createGraphicsPipeline();
    void createWireframePipeline();
    void createFramebuffers();
    void createCommandPool();
    void createVertexBuffer();
    void createIndexBuffer();
    void createWireframeBuffers();
    void createUniformBuffers();
    void createDescriptorPool();
    void createDescriptorSets();
    void createCommandBuffers();
    void createSyncObjects();
    void drawFrame();
    void updateUniformBuffer(uint32_t currentImage);
    
    bool isDeviceSuitable(VkPhysicalDevice device);
    bool checkDeviceExtensionSupport(VkPhysicalDevice device);
    std::vector<const char*> getRequiredExtensions();
    VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
    VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
    VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);
    VkShaderModule createShaderModule(const std::vector<char>& code);
    
    static void mouseCallback(GLFWwindow* window, double xpos, double ypos);
    
    GLFWwindow* window;
    VkInstance instance;
    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
    VkDevice device;
    VkQueue graphicsQueue;
    VkQueue presentQueue;
    VkSurfaceKHR surface;
    VkSwapchainKHR swapChain;
    std::vector<VkImage> swapChainImages;
    VkFormat swapChainImageFormat;
    VkExtent2D swapChainExtent;
    std::vector<VkImageView> swapChainImageViews;
    VkRenderPass renderPass;
    VkDescriptorSetLayout descriptorSetLayout;
    VkPipelineLayout pipelineLayout;
    VkPipeline graphicsPipeline;
    VkPipeline wireframePipeline;
    std::vector<VkFramebuffer> swapChainFramebuffers;
    VkCommandPool commandPool;
    std::vector<VkCommandBuffer> commandBuffers;
    std::vector<VkSemaphore> imageAvailableSemaphores;
    std::vector<VkSemaphore> renderFinishedSemaphores;
    std::vector<VkFence> inFlightFences;
    size_t currentFrame = 0;
    
    // Буферы для куба
    VkBuffer cubeVertexBuffer;
    VkDeviceMemory cubeVertexBufferMemory;
    VkBuffer cubeIndexBuffer;
    VkDeviceMemory cubeIndexBufferMemory;
    
    // Буферы для сферы
    VkBuffer sphereVertexBuffer;
    VkDeviceMemory sphereVertexBufferMemory;
    VkBuffer sphereIndexBuffer;
    VkDeviceMemory sphereIndexBufferMemory;
    
    std::vector<VkBuffer> uniformBuffers;
    std::vector<VkDeviceMemory> uniformBuffersMemory;
    std::vector<void*> uniformBuffersMapped;
    
    VkDescriptorPool descriptorPool;
    std::vector<VkDescriptorSet> descriptorSets;
    
    // Данные куба
    std::vector<Vertex> cubeVertices;
    std::vector<uint32_t> cubeIndices;
    
    // Данные сферы
    std::vector<Vertex> sphereVertices;
    std::vector<uint32_t> sphereIndices;
    
    // Данные wireframe сферы
    std::vector<Vertex> sphereWireframeVertices;
    std::vector<uint32_t> sphereWireframeIndices;
    VkBuffer sphereWireframeVertexBuffer;
    VkDeviceMemory sphereWireframeVertexBufferMemory;
    VkBuffer sphereWireframeIndexBuffer;
    VkDeviceMemory sphereWireframeIndexBufferMemory;
    
    Camera camera;
    
    bool framebufferResized = false;
    
    static const int MAX_FRAMES_IN_FLIGHT = 2;
    static CubeApp* appInstance;
}; 