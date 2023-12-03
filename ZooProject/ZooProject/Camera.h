#ifndef CAMERA_H
#define CAMERA_H

#include <stdlib.h> // necesare pentru citirea shader-elor
#include <stdio.h>
#include <math.h>

#include <GL/glew.h>

#include <GLM.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

#include <glfw3.h>

#include <iostream>

#pragma comment (lib, "glfw3dll.lib")
#pragma comment (lib, "glew32.lib")
#pragma comment (lib, "OpenGL32.lib")

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

class Camera
{

public:

    

    Camera(const int width, const int height, const glm::vec3& position);

    void MoveBackward(float distance);

    void MoveForward(float distance);

    void MoveLeft(float distance);

    void MoveRight(float distance);

    void MoveUp(float distance);

    void MoveDown(float distance);

    void UpdateViewMatrix();
    
    void Set(const int width, const int height, const glm::vec3& position);

    void Reset();

    const glm::mat4& GetViewMatrix() const;

    const glm::mat4 GetProjectionMatrix() const;

    void Reshape(int windowWidth, int windowHeight);

    void UpdateCameraVectors();

private:
    // Default camera values
    const float zNEAR = 0.1f;
    const float zFAR = 500.f;
    const float YAW = -90.0f;
    const float PITCH = 0.0f;
    const float FOV = 45.0f;
    glm::vec3 startPosition;
    glm::mat4 view;

protected:
    const float cameraSpeedFactor = 2.5f;
    const float mouseSensitivity = 0.1f;

    // Perspective properties
    float zNear;
    float zFar;
    float FoVy;
    int width;
    int height;
    bool isPerspective;

    glm::vec3 position;
    glm::vec3 forward;
    glm::vec3 right;
    glm::vec3 up;
    glm::vec3 worldUp;

    // Euler Angles
    float yaw;
    float pitch;

    bool bFirstMouseMove = true;
    float lastX = 0.f, lastY = 0.f;
};

#endif // CAMERA_H
