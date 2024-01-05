#include"Camera.h"



Camera::Camera(int width, int height, glm::vec3 position)
{
	Camera::width = width;
	Camera::height = height;
	Position = position;
}

void Camera::updateMatrix(float FOVdeg, float nearPlane, float farPlane)
{
	// Initializes matrices since otherwise they will be the null matrix
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 projection = glm::mat4(1.0f);

	// Makes camera look in the right direction from the right position
	view = glm::lookAt(Position, Position + Orientation, Up);
	// Adds perspective to the scene
	projection = glm::perspective(glm::radians(FOVdeg), (float)width / height, nearPlane, farPlane);

	// Sets new camera matrix
	cameraMatrix = projection * view;
}

void Camera::Matrix(Shader& shader, const char* uniform)
{
	// Exports camera matrix
	glUniformMatrix4fv(glGetUniformLocation(shader.ID, uniform), 1, GL_FALSE, glm::value_ptr(cameraMatrix));
}

void Camera::PrintPosition() const
{
    std::cout << "Camera Position: (" << Position.x << ", " << Position.y << ", " << Position.z << ")\n";
}


void Camera::Inputs(GLFWwindow* window)
{
    // Handles key inputs
    if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS)
    {
        // La apăsarea tastei 'P', afișează coordonatele camerei
        PrintPosition();
    }

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    {
        glm::vec3 newPosition = Position + speed * glm::normalize(glm::vec3(Orientation.x, 0.0f, Orientation.z));
        glm::vec3 lastValidPosition = Position;

        // Verificare limită pe axa Z (partea negativă)
        if (newPosition.z > -8.05f)
        {
            Position = newPosition;
        }
        else
        {
            Position.z = -8.05f;
        }

        // Verificare limită pe axa Z (partea pozitivă)

        if (Position.z > 13.82f && Position.z < 19.0f)
        {
            if (Position.x > -7.81f && Position.x < -6.61f)
                Position.x = newPosition.x;
            else
                Position.x = lastValidPosition.x;
        }

        if (Position.x > -7.81f && Position.x < -6.41f)
        {
            if (Position.z > 19.0f)
            {
                Position.z = 19.0f;
            }
        }
        else if (Position.z > 13.82f)
        {
            // Dacă x nu este în interval, setează limita lui z la 13.82f
            Position.z = 13.82f;
        }
    

        // Verificare limită pe axa X
        if (Position.x > 7.71f)
        {
            Position.x = 7.71f;
        }
        else if (Position.x < -8.5f && Position.z < 6.53f)
        {
            Position = lastValidPosition;
        }

        if (Position.z > 6.62f && Position.z < 13.93f && Position.x < -10.38f)
        {
            Position.x = -10.38f;
        }
    }

    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    {
        glm::vec3 newPosition = Position + speed * -glm::normalize(glm::cross(Orientation, Up));

        glm::vec3 lastValidPosition = Position;

        // Verificare limită pe axa Z
        if (newPosition.z > -8.05f)
        {
            Position = newPosition;
        }
        else
        {
            Position.z = -8.05f;
        }

        if (Position.z > 13.82f && Position.z < 19.0f)
        {
            if (Position.x > -7.81f && Position.x < -6.61f)
                Position.x = newPosition.x;
            else
                Position.x = lastValidPosition.x;
        }

        if (Position.x > -7.81f && Position.x < -6.41f)
        {
            if (Position.z > 19.0f)
            {
                Position.z = 19.0f;
            }
        }
        else if (Position.z > 13.82f)
        {
            // Dacă x nu este în interval, setează limita lui z la 13.82f
            Position.z = 13.82f;
        }

        // Verificare limită pe axa X
        if (Position.x > 7.71f)
        {
            Position.x = 7.71f;
        }
        else if (Position.x < -8.5f && Position.z < 6.53f)
        {
            Position = lastValidPosition;
        }

        if (Position.z > 6.62f && Position.z < 13.93f && Position.x < -10.38f)
        {
            Position.x = -10.38f;
        }
    }

    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    {
        glm::vec3 newPosition = Position - speed * glm::normalize(glm::vec3(Orientation.x, 0.0f, Orientation.z));

        glm::vec3 lastValidPosition = Position;

        // Verificare limită pe axa Z
        if (newPosition.z > -8.05f)
        {
            Position = newPosition;
        }
        else
        {
            Position.z = -8.05f;
        }

        if (Position.z > 13.82f && Position.z < 19.0f)
        {
            if (Position.x > -7.81f && Position.x < -6.61f)
                Position.x = newPosition.x;
            else
                Position.x = lastValidPosition.x;
        }

        if (Position.x > -7.81f && Position.x < -6.41f)
        {
            if (Position.z > 19.0f)
            {
                Position.z = 19.0f;
            }
        }
        else if (Position.z > 13.82f)
        {
            // Dacă x nu este în interval, setează limita lui z la 13.82f
            Position.z = 13.82f;
        }

        // Verificare limită pe axa X
        if (Position.x > 7.71f)
        {
            Position.x = 7.71f;
        }
        else if (Position.x < -8.5f && Position.z < 6.53f)
        {
            Position = lastValidPosition;
        }

        if (Position.z > 6.62f && Position.z < 13.93f && Position.x < -10.38f)
        {
            Position.x = -10.38f;
        }
    }

    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    {
        glm::vec3 newPosition = Position + speed * glm::normalize(glm::cross(Orientation, Up));

        glm::vec3 lastValidPosition = Position;

        // Verificare limită pe axa Z
        if (newPosition.z > -8.05f)
        {
            Position = newPosition;
        }
        else
        {
            Position.z = -8.05f;
        }

        if (Position.z > 13.82f && Position.z < 19.0f)
        {
            if (Position.x > -7.81f && Position.x < -6.61f)
                Position.x = newPosition.x;
            else
                Position.x = lastValidPosition.x;
        }

        if (Position.x > -7.81f && Position.x < -6.41f)
        {
            if (Position.z > 19.0f)
            {
                Position.z = 19.0f;
            }
        }
        else if (Position.z > 13.82f)
        {
            // Dacă x nu este în interval, setează limita lui z la 13.82f
            Position.z = 13.82f;
        }

        // Verificare limită pe axa X
        if (Position.x > 7.71f)
        {
            Position.x = 7.71f;
        }
        else if (Position.x < -8.5f && Position.z < 6.53f)
        {
            Position = lastValidPosition;
        }
        if (Position.z > 6.62f && Position.z < 13.93f && Position.x < -10.38f)
        {
            Position.x = -10.38f;
        }

    }

    // Fixează coordonata y la 1.4f
    Position.y = 1.4f;
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
    {
        Position += speed * Up;
    }
    if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
    {
        Position += speed * -Up;
    }
    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
    {
        speed = 0.1f;
    }
    else if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_RELEASE)
    {
        speed = 0.011f;
    }

    // Handles mouse inputs
    // Hides mouse cursor
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

    // Stores the coordinates of the cursor
    double mouseX;
    double mouseY;
    // Fetches the coordinates of the cursor
    glfwGetCursorPos(window, &mouseX, &mouseY);

    // Normalizes and shifts the coordinates of the cursor such that they begin in the middle of the screen
    // and then "transforms" them into degrees 
    float rotX = sensitivity * (float)(mouseY - (height / 2)) / height;
    float rotY = sensitivity * (float)(mouseX - (width / 2)) / width;

    // Calculates upcoming vertical change in the Orientation
    glm::vec3 newOrientation = glm::rotate(Orientation, glm::radians(-rotX), glm::normalize(glm::cross(Orientation, Up)));

    // Decides whether or not the next vertical Orientation is legal or not
    if (abs(glm::angle(newOrientation, Up) - glm::radians(90.0f)) <= glm::radians(85.0f))
    {
        Orientation = newOrientation;
    }

    // Rotates the Orientation left and right
    Orientation = glm::rotate(Orientation, glm::radians(-rotY), Up);

    // Sets mouse cursor to the middle of the screen so that it doesn't end up roaming around
    glfwSetCursorPos(window, (width / 2), (height / 2));
}
