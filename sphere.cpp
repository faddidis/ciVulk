#include "sphere.hpp"
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

void generateSphereMesh(std::vector<Vertex>& vertices, std::vector<uint32_t>& indices, float radius, int latBands, int lonBands) {
    vertices.clear();
    indices.clear();
    
    // Генерируем вершины сферы
    for (int lat = 0; lat <= latBands; lat++) {
        float theta = lat * M_PI / latBands;
        float sinTheta = sin(theta);
        float cosTheta = cos(theta);
        
        for (int lon = 0; lon <= lonBands; lon++) {
            float phi = lon * 2.0f * M_PI / lonBands;
            float sinPhi = sin(phi);
            float cosPhi = cos(phi);
            
            float x = cosPhi * sinTheta;
            float y = cosTheta;
            float z = sinPhi * sinTheta;
            
            Vertex v;
            v.pos = glm::vec3(x * radius, y * radius, z * radius);
            vertices.push_back(v);
        }
    }
    
    // Генерируем индексы для линий каркаса (меридианы и параллели)
    std::vector<uint32_t> lineIndices;
    
    // Меридианы (вертикальные линии)
    for (int lon = 0; lon <= lonBands; lon++) {
        for (int lat = 0; lat < latBands; lat++) {
            uint32_t current = lat * (lonBands + 1) + lon;
            uint32_t next = (lat + 1) * (lonBands + 1) + lon;
            lineIndices.push_back(current);
            lineIndices.push_back(next);
        }
    }
    
    // Параллели (горизонтальные линии)
    for (int lat = 0; lat <= latBands; lat++) {
        for (int lon = 0; lon < lonBands; lon++) {
            uint32_t current = lat * (lonBands + 1) + lon;
            uint32_t next = lat * (lonBands + 1) + (lon + 1);
            lineIndices.push_back(current);
            lineIndices.push_back(next);
        }
    }
    
    indices = lineIndices;
} 