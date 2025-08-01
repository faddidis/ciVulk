#version 450

layout(location = 0) in vec3 fragColor;
layout(location = 0) out vec4 outColor;

void main() {
    // Белый цвет для линий каркаса
    outColor = vec4(1.0, 1.0, 1.0, 1.0);
} 