#include <glm/glm.hpp>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include "cube_app.hpp"

int main() {
    CubeApp app;
    
    try {
        app.run();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}
