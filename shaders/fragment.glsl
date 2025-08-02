#version 450

layout(location = 0) in vec3 fragColor;
layout(location = 0) out vec4 outColor;

void main() {
    // Черный цвет для заполненной сферы (как фон)
    outColor = vec4(0.0, 0.0, 0.0, 1.0);
} 