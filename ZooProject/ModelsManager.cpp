#include "ModelsManager.h"
//------- Ignore this ----------
#include<filesystem>
namespace fs = std::filesystem;
//------------------------------

ModelsManager::ModelsManager()
{
}

void ModelsManager::drawBear(Camera camera)
{
	// Generates Shader objects
	Shader shaderProgram("default.vert", "default.frag");
	Shader skyboxShader("skybox.vert", "skybox.frag");

	std::string parentDir = (fs::current_path().fs::path::parent_path()).string();
	std::string modelPath3 = "/models/bear/bear.gltf";
	Model model3((parentDir + modelPath3).c_str());

	glm::mat4 modelMatrix = glm::mat4(1.0f);  // Start with the identity matrix

	// Define translation, rotation, and scaling vectors
	glm::vec3 translationVector = glm::vec3(0.0f, 0.0f, 0.0f);  // Replace with your values
	glm::vec3 rotationAxis = glm::vec3(1.0f, 0.0f, 0.0f);       // Example: rotation around X-axis
	//float rotationAngle = glm::radians(45.0f);                  // 45 degrees in radians
	glm::vec3 scalingVector = glm::vec3(0.01f, 0.01f, 0.01f);      // Uniform scaling

	// Apply transformations
	modelMatrix = glm::translate(modelMatrix, translationVector);  // Translate
	modelMatrix = glm::rotate(modelMatrix, 0.0f, rotationAxis);  // Rotate
	modelMatrix = glm::scale(modelMatrix, scalingVector);  // Scale


	// Set the model matrix uniform in the shader
	shaderProgram.Activate();
	glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix));

	// Draw the model with the applied transformation
	model3.Draw(shaderProgram, camera);



	modelMatrix = glm::mat4(1.0f);  // Start with the identity matrix

	// Define translation, rotation, and scaling vectors
	translationVector = glm::vec3(0.0f, 0.0f, 1.8f);  // Replace with your values
	rotationAxis = glm::vec3(1.0f, 0.0f, 0.0f);       // Example: rotation around X-axis
	//float rotationAngle = glm::radians(45.0f);                  // 45 degrees in radians
	scalingVector = glm::vec3(0.01f, 0.01f, 0.01f);      // Uniform scaling

	// Apply transformations
	modelMatrix = glm::translate(modelMatrix, translationVector);  // Translate
	modelMatrix = glm::rotate(modelMatrix, 0.0f, rotationAxis);  // Rotate
	modelMatrix = glm::scale(modelMatrix, scalingVector);  // Scale

	// Set the model matrix uniform in the shader
	shaderProgram.Activate();
	glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix));
	model3.Draw(shaderProgram, camera);
}
