#pragma once
#include <vector>
#include <array>
#include <glm/glm.hpp>
#include <vulkan/vulkan.h>
#include "cube.hpp" // Используем ту же структуру Vertex

void generateSphereMesh(std::vector<Vertex>& vertices, std::vector<uint32_t>& indices, float radius = 0.3f, int latBands = 16, int lonBands = 16); 