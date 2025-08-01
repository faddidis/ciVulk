#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <GLFW/glfw3.h>

class Camera {
public:
    Camera(float fov = 45.0f, float aspectRatio = 16.0f/9.0f, float nearPlane = 0.1f, float farPlane = 100.0f);
    
    void update(float deltaTime);
    void processInput(GLFWwindow* window, float deltaTime);
    void processMouse(GLFWwindow* window, double xpos, double ypos);
    
    glm::mat4 getViewMatrix() const;
    glm::mat4 getProjectionMatrix() const;
    glm::vec3 getPosition() const { return position; }
    glm::vec3 getFront() const { return front; }
    glm::vec3 getUp() const { return up; }
    
    void setPosition(const glm::vec3& pos) { position = pos; }
    void setAspectRatio(float aspect) { aspectRatio = aspect; }
    
private:
    void updateCameraVectors();
    
    glm::vec3 position;
    glm::vec3 front;
    glm::vec3 up;
    glm::vec3 right;
    glm::vec3 worldUp;
    
    float yaw;
    float pitch;
    
    float fov;
    float aspectRatio;
    float nearPlane;
    float farPlane;
    
    float movementSpeed;
    float mouseSensitivity;
    
    bool firstMouse;
    float lastX;
    float lastY;
}; 