#include "cube.hpp"
#include <cmath>

void generateCubeMesh(std::vector<Vertex>& vertices, std::vector<uint32_t>& indices, float size) {
    vertices.clear();
    indices.clear();
    
    float halfSize = size * 0.5f;
    
    // Вершины куба
    std::vector<glm::vec3> cubeVertices = {
        // Передняя грань
        {-halfSize, -halfSize,  halfSize}, // 0
        { halfSize, -halfSize,  halfSize}, // 1
        { halfSize,  halfSize,  halfSize}, // 2
        {-halfSize,  halfSize,  halfSize}, // 3
        
        // Задняя грань
        {-halfSize, -halfSize, -halfSize}, // 4
        { halfSize, -halfSize, -halfSize}, // 5
        { halfSize,  halfSize, -halfSize}, // 6
        {-halfSize,  halfSize, -halfSize}, // 7
    };
    
    // Добавляем вершины
    for (const auto& pos : cubeVertices) {
        Vertex v;
        v.pos = pos;
        vertices.push_back(v);
    }
    
    // Индексы для линий (ребра куба)
    std::vector<uint32_t> lineIndices = {
        // Передняя грань
        0, 1, 1, 2, 2, 3, 3, 0,
        // Задняя грань
        4, 5, 5, 6, 6, 7, 7, 4,
        // Соединяющие ребра
        0, 4, 1, 5, 2, 6, 3, 7
    };
    
    indices = lineIndices;
} 