#include<filesystem>
namespace fs = std::filesystem;

#include"Model.h"
#include"ModelsManager.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

const unsigned int width = 1920;
const unsigned int height = 1080;



float skyboxVertices[] =
{
	-1.0f, -1.0f,  1.0f,
	 1.0f, -1.0f,  1.0f,
	 1.0f, -1.0f, -1.0f,
	-1.0f, -1.0f, -1.0f,
	-1.0f,  1.0f,  1.0f,
	 1.0f,  1.0f,  1.0f,
	 1.0f,  1.0f, -1.0f,
	-1.0f,  1.0f, -1.0f
};

unsigned int skyboxIndices[] =
{
	// Right
	1, 2, 6,
	6, 5, 1,
	// Left
	0, 4, 7,
	7, 3, 0,
	// Top
	4, 5, 6,
	6, 7, 4,
	// Bottom
	0, 3, 2,
	2, 1, 0,
	// Back
	0, 1, 5,
	5, 4, 0,
	// Front
	3, 7, 6,
	6, 2, 3
};

int main()
{
	// Initialize GLFW
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create a GLFWwindow object of 800 by 800 pixels, naming it "YoutubeOpenGL"
	GLFWwindow* window = glfwCreateWindow(width, height, "ZOO", NULL, NULL);
	// Error check if the window fails to create
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	// Introduce the window into the current context
	glfwMakeContextCurrent(window);

	//Load GLAD so it configures OpenGL
	gladLoadGL();
	// Specify the viewport of OpenGL in the Window
	// In this case the viewport goes from x = 0, y = 0, to x = 800, y = 800
	glViewport(0, 0, width, height);

	// Generates Shader objects
	Shader shaderProgram("default.vert", "default.frag");
	Shader skyboxShader("skybox.vert", "skybox.frag");

	// Take care of all the light related things
	glm::vec4 lightColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	glm::vec3 lightPos = glm::vec3(0.5f, 0.5f, 0.5f);

	shaderProgram.Activate();
	glUniform4f(glGetUniformLocation(shaderProgram.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	glUniform3f(glGetUniformLocation(shaderProgram.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);
	skyboxShader.Activate();
	glUniform1i(glGetUniformLocation(skyboxShader.ID, "skybox"), 0);

	// Enables the Depth Buffer
	glEnable(GL_DEPTH_TEST);

	// Enables Cull Facing
	glEnable(GL_CULL_FACE);
	// Keeps front faces
	glCullFace(GL_FRONT);
	// Uses counter clock-wise standard
	glFrontFace(GL_CCW);

	Camera camera(width, height, glm::vec3(-7.2f, 1.5f, 19.0f));

	std::string parentDir = (fs::current_path().fs::path::parent_path()).string();
	std::string planePath = "/models/airplane/scene.gltf";
	std::string foundationPath = "/models/fundatie/gr2.gltf";
	std::string roadPath = "/models/path/path.gltf";
	std::string darkFencePath = "/models/darkfence/fence.gltf";
	std::string cabinPath = "/models/booth/cabin.gltf";
	std::string signPath = "/models/darkfence/sign.gltf";
	std::string fence4Path = "/models/fence3/fence4.gltf";
	std::string benchPath = "/models/bench/bench.gltf";
	std::string treePath = "/models/acacia/tree6.gltf";
	std::string catPath = "/models/cat/cat.gltf";
	std::string hedgePath = "/models/hedge/hedge.gltf";
	std::string welcomeSignPath = "/models/welcome/welcomeSign.gltf";
	std::string waterPath = "/models/water/water.gltf";
	std::string reedPath = "/models/reed/reed.gltf";
	std::string deer1Path = "/models/deer/deer.gltf";
	std::string deer2Path = "/models/deer/deer2.gltf";
	std::string horsePath = "/models/horse/horse.gltf";
	std::string birdPath = "/models/bird/bird.gltf";
	std::string mangerPath = "/models/manger/manger.gltf";
	std::string duckPath = "/models/duck/duck.gltf";
	std::string monkeyPath = "/models/monke/monkey.gltf";
	std::string tamarinPath = "/models/tamarin/tamarin.gltf";
	std::string mainTreePath = "/models/maintree/mainTree.gltf";
	std::string foundation2Path = "/models/foundation2/foundation2.gltf";
	std::string tigerPath = "/models/tiger/lion.gltf";
	std::string lionPath = "/models/lion/lion.gltf";
	std::string bearPath = "/models/bear/bear.gltf";
	std::string camelPath = "/models/camel/camel.gltf";

	// Load in models
	Model airplane((parentDir + planePath).c_str());
	Model foundation((parentDir + foundationPath).c_str());
	Model road((parentDir + roadPath).c_str());
	Model darkFence((parentDir + darkFencePath).c_str());
	Model cabin((parentDir + cabinPath).c_str());
	Model sign((parentDir + signPath).c_str());
	Model fence4((parentDir + fence4Path).c_str());
	Model bench((parentDir + benchPath).c_str());
	Model tree((parentDir + treePath).c_str());
	Model cat((parentDir + catPath).c_str());
	Model hedge((parentDir + hedgePath).c_str());
	Model welcomeSign((parentDir + welcomeSignPath).c_str());
	Model water((parentDir + waterPath).c_str());
	Model reed((parentDir + reedPath).c_str());
	Model deer1((parentDir + deer1Path).c_str());
	Model deer2((parentDir + deer2Path).c_str());
	Model horse((parentDir + horsePath).c_str());
	Model bird((parentDir + birdPath).c_str());
	Model manger((parentDir + mangerPath).c_str());
	Model duck((parentDir + duckPath).c_str());
	Model monkey((parentDir + monkeyPath).c_str());
	Model mainTree((parentDir + mainTreePath).c_str());
	Model foundation2((parentDir + foundation2Path).c_str());
	Model tamarin((parentDir + tamarinPath).c_str());
	Model tiger((parentDir + tigerPath).c_str());
	Model lion((parentDir + lionPath).c_str());
	Model bear((parentDir + bearPath).c_str());
	Model camel((parentDir + camelPath).c_str());

	// Variables to create periodic event for FPS displaying
	double prevTime = 0.0;
	double crntTime = 0.0;
	double timeDiff;
	// Keeps track of the amount of frames in timeDiff
	unsigned int counter = 0;

	// Use this to disable VSync (not advized)
	//glfwSwapInterval(0);

	// Create VAO, VBO, and EBO for the skybox
	unsigned int skyboxVAO, skyboxVBO, skyboxEBO;
	glGenVertexArrays(1, &skyboxVAO);
	glGenBuffers(1, &skyboxVBO);
	glGenBuffers(1, &skyboxEBO);
	glBindVertexArray(skyboxVAO);
	glBindBuffer(GL_ARRAY_BUFFER, skyboxVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices), &skyboxVertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, skyboxEBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(skyboxIndices), &skyboxIndices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	// All the faces of the cubemap (make sure they are in this exact order)
	std::string facesCubemap[6] =
	{
		parentDir + "/skybox/TropicalSunnyDayFront.jpg",
		parentDir + "/skybox/TropicalSunnyDayBack.jpg",
		parentDir + "/skybox/TropicalSunnyDayUp.jpg",
		parentDir + "/skybox/TropicalSunnyDayDown.jpg",
		parentDir + "/skybox/TropicalSunnyDayRight.jpg",
		parentDir + "/skybox/TropicalSunnyDayLeft.jpg"
	};

	// Creates the cubemap texture object
	unsigned int cubemapTexture;
	glGenTextures(1, &cubemapTexture);
	glBindTexture(GL_TEXTURE_CUBE_MAP, cubemapTexture);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	// These are very important to prevent seams
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
	// This might help with seams on some systems
	//glEnable(GL_TEXTURE_CUBE_MAP_SEAMLESS);

	// Cycles through all the textures and attaches them to the cubemap object
	for (unsigned int i = 0; i < 6; i++)
	{
		int width, height, nrChannels;
		unsigned char* data = stbi_load(facesCubemap[i].c_str(), &width, &height, &nrChannels, 0);
		if (data)
		{
			stbi_set_flip_vertically_on_load(false);
			glTexImage2D
			(
				GL_TEXTURE_CUBE_MAP_POSITIVE_X + i,
				0,
				GL_RGB,
				width,
				height,
				0,
				GL_RGB,
				GL_UNSIGNED_BYTE,
				data
			);
			stbi_image_free(data);
		}
		else
		{
			std::cout << "Failed to load texture: " << facesCubemap[i] << std::endl;
			stbi_image_free(data);
		}
	}



	// Main while loop
	while (!glfwWindowShouldClose(window))
	{
		// Specify the color of the background
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		// Clean the back buffer and depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Handles camera inputs (delete this if you have disabled VSync)
		camera.Inputs(window);
		// Updates and exports the camera matrix to the Vertex Shader
		camera.updateMatrix(45.0f, 0.1f, 100.0f);

		// Activate shader and set common uniforms
		shaderProgram.Activate();

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		glm::mat4 modelMatrix2 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		glm::vec3 scalingVector2 = glm::vec3(14.0f, 0.001f, -14.0f); // Adjust as needed for correct proportions
		modelMatrix2 = glm::scale(modelMatrix2, scalingVector2);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix2));
		foundation.Draw(shaderProgram, camera); //fundatia

		glm::mat4 modelMatrix = glm::mat4(1.0f);
		glm::vec3 translationVector = glm::vec3(-13.0f, 17.0f, -13.0f);
		glm::vec3 rotationAxis = glm::vec3(1.0f, 0.0f, 0.0f);
		//float rotationAngle = glm::radians(45.0f);
		glm::vec3 scalingVector = glm::vec3(1.0f, 1.0f, 1.0f);
		modelMatrix = glm::translate(modelMatrix, translationVector);  // Translate
		modelMatrix = glm::rotate(modelMatrix, 0.0f, rotationAxis);  // Rotate
		modelMatrix = glm::scale(modelMatrix, scalingVector);  // Scale
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix));
		airplane.Draw(shaderProgram, camera); // Draw the airplane


		glm::mat4 modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		glm::vec3 translationVector3 = glm::vec3(-9.0f, 0.0f, 0.454f);
		glm::vec3 scalingVector3 = glm::vec3(0.8f, 0.01f, 13.7f); // Adjust as needed for correct proportions
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		road.Draw(shaderProgram, camera); // Draw the road

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.8f, 0.01f, 10.7f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(8.0f, 0.2f, 0.30f);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		road.Draw(shaderProgram, camera); // Draw the road

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.8f, 0.005f, 6.4f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(8.36f, 1.0f, 0.0f);
		rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		float rotationAngle = glm::radians(90.0f);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		road.Draw(shaderProgram, camera); // Draw the road

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.8f, 0.005f, 6.4f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-6.0f, 1.0f, 0.0f);
		rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		rotationAngle = glm::radians(90.0f);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		road.Draw(shaderProgram, camera); // Draw the road

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.017f, 0.017f, 0.017f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-6.43f, 0.0f, 12.9);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		darkFence.Draw(shaderProgram, camera); // Draw the fence

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.017f, 0.017f, 0.017f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-6.43f, 0.0f, 10.9f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		darkFence.Draw(shaderProgram, camera); // Draw the fence

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.017f, 0.017f, 0.017f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-6.43f, 0.0f, 8.9f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		darkFence.Draw(shaderProgram, camera); // Draw the fence

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.017f, 0.017f, 0.019f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-6.43f, 0.0f, 6.75f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		darkFence.Draw(shaderProgram, camera); // Draw the fence

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.017f, 0.017f, 0.017f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-5.4f, 0.0f, 5.6f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		rotationAxis = glm::vec3(1.0f, 0.0f, 0.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		darkFence.Draw(shaderProgram, camera); // Draw the fence

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.017f, 0.017f, 0.017f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-3.4f, 0.0f, 5.6f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		rotationAxis = glm::vec3(1.0f, 0.0f, 0.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		darkFence.Draw(shaderProgram, camera); // Draw the fence

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.017f, 0.017f, 0.017f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-1.4f, 0.0f, 5.6f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		rotationAxis = glm::vec3(1.0f, 0.0f, 0.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		darkFence.Draw(shaderProgram, camera); // Draw the fence

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.017f, 0.017f, 0.017f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(0.6f, 0.0f, 5.6f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		rotationAxis = glm::vec3(1.0f, 0.0f, 0.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		darkFence.Draw(shaderProgram, camera); // Draw the fence

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.017f, 0.017f, 0.017f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(2.6f, 0.0f, 5.6f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		rotationAxis = glm::vec3(1.0f, 0.0f, 0.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		darkFence.Draw(shaderProgram, camera); // Draw the fence

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.017f, 0.017f, 0.017f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(4.6f, 0.0f, 5.6f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		rotationAxis = glm::vec3(1.0f, 0.0f, 0.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		darkFence.Draw(shaderProgram, camera); // Draw the fence

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.017f, 0.017f, 0.017f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(5.6f, 0.0f, 6.6f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		//rotationAxis = glm::vec3(1.0f, 0.0f, 0.0f);
		//rotationAngle = glm::radians(-90.0f);
		//modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		darkFence.Draw(shaderProgram, camera); // Draw the fence

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.017f, 0.017f, 0.017f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(5.6f, 0.0f, 8.6f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		//rotationAxis = glm::vec3(1.0f, 0.0f, 0.0f);
		//rotationAngle = glm::radians(-90.0f);
		//modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		darkFence.Draw(shaderProgram, camera); // Draw the fence
		
		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.017f, 0.017f, 0.017f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(5.6f, 0.0f, 10.6f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		//rotationAxis = glm::vec3(1.0f, 0.0f, 0.0f);
		//rotationAngle = glm::radians(-90.0f);
		//modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		darkFence.Draw(shaderProgram, camera); // Draw the fence		
		
		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.017f, 0.017f, 0.019f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(5.6f, 0.0f, 12.8f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		//rotationAxis = glm::vec3(1.0f, 0.0f, 0.0f);
		//rotationAngle = glm::radians(-90.0f);
		//modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		darkFence.Draw(shaderProgram, camera); // Draw the fence






		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.017f, 0.017f, 0.017f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-6.43f, 0.0f, 2.9f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		darkFence.Draw(shaderProgram, camera); // Draw the fence

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.017f, 0.017f, 0.017f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-6.43f, 0.0f, 0.9f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		darkFence.Draw(shaderProgram, camera); // Draw the fence

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.017f, 0.017f, 0.017f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-6.43f, 0.0f, -2.91f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		darkFence.Draw(shaderProgram, camera); // Draw the fence

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.017f, 0.017f, 0.017f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-6.43f, 0.0f, -4.91f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		darkFence.Draw(shaderProgram, camera); // Draw the fence

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.017f, 0.017f, 0.017f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-5.43f, 0.0f, -5.91f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		rotationAxis = glm::vec3(1.0f, 0.0f, 0.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		darkFence.Draw(shaderProgram, camera); // Draw the fence

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.017f, 0.017f, 0.017f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-3.43f, 0.0f, -5.91f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		rotationAxis = glm::vec3(1.0f, 0.0f, 0.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		darkFence.Draw(shaderProgram, camera); // Draw the fence

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.017f, 0.017f, 0.017f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-1.43f, 0.0f, -5.91f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		rotationAxis = glm::vec3(1.0f, 0.0f, 0.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		darkFence.Draw(shaderProgram, camera); // Draw the fence

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.017f, 0.017f, 0.017f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(0.57f, 0.0f, -5.91f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		rotationAxis = glm::vec3(1.0f, 0.0f, 0.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		darkFence.Draw(shaderProgram, camera); // Draw the fence

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.017f, 0.017f, 0.017f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(2.57f, 0.0f, -5.91f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		rotationAxis = glm::vec3(1.0f, 0.0f, 0.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		darkFence.Draw(shaderProgram, camera); // Draw the fence

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.017f, 0.017f, 0.017f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(4.60f, 0.0f, -5.89f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		rotationAxis = glm::vec3(1.0f, 0.0f, 0.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		darkFence.Draw(shaderProgram, camera); // Draw the fence

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.017f, 0.017f, 0.017f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(5.60f, 0.0f, -4.89f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		rotationAxis = glm::vec3(1.0f, 0.0f, 0.0f);
		rotationAngle = glm::radians(-180.0f);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		darkFence.Draw(shaderProgram, camera); // Draw the fence

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.017f, 0.017f, 0.017f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(5.60f, 0.0f, -2.89f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		rotationAxis = glm::vec3(1.0f, 0.0f, 0.0f);
		rotationAngle = glm::radians(-180.0f);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		darkFence.Draw(shaderProgram, camera); // Draw the fence

		



		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.017f, 0.017f, 0.017f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(5.60f, 0.0f, 1.11f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		rotationAxis = glm::vec3(1.0f, 0.0f, 0.0f);
		rotationAngle = glm::radians(-180.0f);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		darkFence.Draw(shaderProgram, camera); // Draw the fence

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.017f, 0.017f, 0.0155f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(5.60f, 0.0f, 3.05f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		rotationAxis = glm::vec3(1.0f, 0.0f, 0.0f);
		rotationAngle = glm::radians(-180.0f);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		darkFence.Draw(shaderProgram, camera); // Draw the fence

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.017f, 0.017f, 0.017f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(4.58f, 0.0f, 3.97f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		rotationAxis = glm::vec3(1.0f, 0.0f, 0.0f);
		rotationAngle = glm::radians(90.0f);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		darkFence.Draw(shaderProgram, camera); // Draw the fence

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.017f, 0.017f, 0.017f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(2.58f, 0.0f, 3.97f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		rotationAxis = glm::vec3(1.0f, 0.0f, 0.0f);
		rotationAngle = glm::radians(90.0f);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		darkFence.Draw(shaderProgram, camera); // Draw the fence

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.017f, 0.017f, 0.017f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(0.58f, 0.0f, 3.97f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		rotationAxis = glm::vec3(1.0f, 0.0f, 0.0f);
		rotationAngle = glm::radians(90.0f);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		darkFence.Draw(shaderProgram, camera); // Draw the fence

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.017f, 0.017f, 0.017f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-1.42f, 0.0f, 3.97f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		rotationAxis = glm::vec3(1.0f, 0.0f, 0.0f);
		rotationAngle = glm::radians(90.0f);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		darkFence.Draw(shaderProgram, camera); // Draw the fence

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.017f, 0.017f, 0.017f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-3.42f, 0.0f, 3.97f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		rotationAxis = glm::vec3(1.0f, 0.0f, 0.0f);
		rotationAngle = glm::radians(90.0f);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		darkFence.Draw(shaderProgram, camera); // Draw the fence

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.017f, 0.017f, 0.017f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-5.42f, 0.0f, 3.97f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		rotationAxis = glm::vec3(1.0f, 0.0f, 0.0f);
		rotationAngle = glm::radians(90.0f);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		darkFence.Draw(shaderProgram, camera); // Draw the fence

		


		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.5f, 0.65f, 1.0f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-12.0f, -0.55f, 10.3f);
		//rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		//rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		//modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		cabin.Draw(shaderProgram, camera); // Draw the cabin

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.004f, 0.004f, 0.004f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-10.35f, 0.0f, 11.8f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		rotationAxis = glm::vec3(1.0f, 0.0f, 0.0f);
		rotationAngle = glm::radians(-10.0f);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		sign.Draw(shaderProgram, camera); // Draw the tickets sign

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.006f, 0.003f, 0.006f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-8.5f, 0.0f, 4.0f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		fence4.Draw(shaderProgram, camera); // Draw the metallic fence

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.006f, 0.003f, 0.006f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-8.6f, 0.0f, 6.58f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		rotationAxis = glm::vec3(1.0f, 0.0f, 0.0f);
		rotationAngle = glm::radians(90.0f);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		fence4.Draw(shaderProgram, camera); // Draw the metallic fence

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.006f, 0.003f, 0.007f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-11.03f, 0.0f, 6.58f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		rotationAxis = glm::vec3(1.0f, 0.0f, 0.0f);
		rotationAngle = glm::radians(90.0f);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		fence4.Draw(shaderProgram, camera); // Draw the metallic fence

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.006f, 0.003f, 0.006f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-8.5f, 0.0f, 1.57f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		fence4.Draw(shaderProgram, camera); // Draw the metallic fence

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.006f, 0.003f, 0.006f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-8.5f, 0.0f, -0.86f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		fence4.Draw(shaderProgram, camera); // Draw the metallic fence

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.006f, 0.003f, 0.006f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-8.5f, 0.0f, -3.29f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		fence4.Draw(shaderProgram, camera); // Draw the metallic fence
		
		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.006f, 0.003f, 0.006f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-11.1f, 0.0f, -3.29f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		rotationAxis = glm::vec3(1.0f, 0.0f, 0.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		fence4.Draw(shaderProgram, camera); // Draw the metallic fence		
		
		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.006f, 0.003f, 0.0067f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-13.9f, 0.0f, -3.29f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		rotationAxis = glm::vec3(1.0f, 0.0f, 0.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		fence4.Draw(shaderProgram, camera); // Draw the metallic fence

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.006f, 0.003f, 0.006f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-8.5f, 0.0f, -5.72f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		fence4.Draw(shaderProgram, camera); // Draw the metallic fence

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.006f, 0.003f, 0.006f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-8.5f, 0.0f, -8.15f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		fence4.Draw(shaderProgram, camera); // Draw the metallic fence

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.006f, 0.003f, 0.006f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-8.5f, 0.0f, -10.58f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		fence4.Draw(shaderProgram, camera); // Draw the metallic fence

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.006f, 0.003f, 0.008f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-8.5f, 0.0f, -13.95f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		fence4.Draw(shaderProgram, camera); // Draw the metallic fence

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.006f, 0.003f, 0.006f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-1.2f, 0.0f, -10.58f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		fence4.Draw(shaderProgram, camera); // Draw the metallic fence

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.006f, 0.003f, 0.008f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-1.2f, 0.0f, -13.9f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		fence4.Draw(shaderProgram, camera); // Draw the metallic fence

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.006f, 0.003f, 0.006f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(6.2f, 0.0f, -10.58f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		fence4.Draw(shaderProgram, camera); // Draw the metallic fence

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.006f, 0.003f, 0.008f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(6.2f, 0.0f, -13.9f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		fence4.Draw(shaderProgram, camera); // Draw the metallic fence




		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.006f, 0.003f, 0.006f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-6.0f, 0.0f, -8.05f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		rotationAxis = glm::vec3(1.0f, 0.0f, 0.0f);
		rotationAngle = glm::radians(90.0f);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		fence4.Draw(shaderProgram, camera); // Draw the metallic fence

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.006f, 0.003f, 0.006f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-3.57f, 0.0f, -8.05f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		rotationAxis = glm::vec3(1.0f, 0.0f, 0.0f);
		rotationAngle = glm::radians(90.0f);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		fence4.Draw(shaderProgram, camera); // Draw the metallic fence

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.006f, 0.003f, 0.006f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-1.14f, 0.0f, -8.05f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		rotationAxis = glm::vec3(1.0f, 0.0f, 0.0f);
		rotationAngle = glm::radians(90.0f);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		fence4.Draw(shaderProgram, camera); // Draw the metallic fence

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.006f, 0.003f, 0.006f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(1.29f, 0.0f, -8.05f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		rotationAxis = glm::vec3(1.0f, 0.0f, 0.0f);
		rotationAngle = glm::radians(90.0f);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		fence4.Draw(shaderProgram, camera); // Draw the metallic fence

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.006f, 0.003f, 0.006f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(3.72f, 0.0f, -8.05f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		rotationAxis = glm::vec3(1.0f, 0.0f, 0.0f);
		rotationAngle = glm::radians(90.0f);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		fence4.Draw(shaderProgram, camera); // Draw the metallic fence

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.006f, 0.003f, 0.006f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(6.15f, 0.0f, -8.05f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		rotationAxis = glm::vec3(1.0f, 0.0f, 0.0f);
		rotationAngle = glm::radians(90.0f);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		fence4.Draw(shaderProgram, camera); // Draw the metallic fence

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.006f, 0.003f, 0.004f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(7.78f, 0.0f, -8.05f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		rotationAxis = glm::vec3(1.0f, 0.0f, 0.0f);
		rotationAngle = glm::radians(90.0f);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		fence4.Draw(shaderProgram, camera); // Draw the metallic fence

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.006f, 0.003f, 0.006f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(7.78f, 0.0f, -5.52f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		rotationAxis = glm::vec3(1.0f, 0.0f, 0.0f);
		rotationAngle = glm::radians(180.0f);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		fence4.Draw(shaderProgram, camera); // Draw the metallic fence

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.006f, 0.003f, 0.006f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(7.78f, 0.0f, -3.09f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		rotationAxis = glm::vec3(1.0f, 0.0f, 0.0f);
		rotationAngle = glm::radians(180.0f);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		fence4.Draw(shaderProgram, camera); // Draw the metallic fence


		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.006f, 0.003f, 0.006f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(10.35f, 0.0f, -3.1f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		rotationAxis = glm::vec3(1.0f, 0.0f, 0.0f);
		rotationAngle = glm::radians(90.0f);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		fence4.Draw(shaderProgram, camera); // Draw the metallic fence

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.006f, 0.003f, 0.0085f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(13.85f, 0.0f, -3.1f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		rotationAxis = glm::vec3(1.0f, 0.0f, 0.0f);
		rotationAngle = glm::radians(90.0f);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		fence4.Draw(shaderProgram, camera); // Draw the metallic fence


		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.006f, 0.003f, 0.006f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(7.78f, 0.0f, -0.66f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		rotationAxis = glm::vec3(1.0f, 0.0f, 0.0f);
		rotationAngle = glm::radians(180.0f);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		fence4.Draw(shaderProgram, camera); // Draw the metallic fence

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.006f, 0.003f, 0.006f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(7.78f, 0.0f, 1.77f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		rotationAxis = glm::vec3(1.0f, 0.0f, 0.0f);
		rotationAngle = glm::radians(180.0f);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		fence4.Draw(shaderProgram, camera); // Draw the metallic fence

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.006f, 0.003f, 0.006f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(7.78f, 0.0f, 4.2f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		rotationAxis = glm::vec3(1.0f, 0.0f, 0.0f);
		rotationAngle = glm::radians(180.0f);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		fence4.Draw(shaderProgram, camera); // Draw the metallic fence

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.006f, 0.003f, 0.006f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(10.3f, 0.0f, 4.3f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		rotationAxis = glm::vec3(1.0f, 0.0f, 0.0f);
		rotationAngle = glm::radians(90.0f);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		fence4.Draw(shaderProgram, camera); // Draw the metallic fence

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.006f, 0.003f, 0.0085f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(13.8f, 0.0f, 4.3f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		rotationAxis = glm::vec3(1.0f, 0.0f, 0.0f);
		rotationAngle = glm::radians(90.0f);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		fence4.Draw(shaderProgram, camera); // Draw the metallic fence

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.006f, 0.003f, 0.006f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(7.78f, 0.0f, 6.63f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		rotationAxis = glm::vec3(1.0f, 0.0f, 0.0f);
		rotationAngle = glm::radians(180.0f);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		fence4.Draw(shaderProgram, camera); // Draw the metallic fence

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.006f, 0.003f, 0.006f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(7.78f, 0.0f, 9.06f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		rotationAxis = glm::vec3(1.0f, 0.0f, 0.0f);
		rotationAngle = glm::radians(180.0f);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		fence4.Draw(shaderProgram, camera); // Draw the metallic fence

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.006f, 0.003f, 0.006f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(7.78f, 0.0f, 11.49f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		rotationAxis = glm::vec3(1.0f, 0.0f, 0.0f);
		rotationAngle = glm::radians(180.0f);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		fence4.Draw(shaderProgram, camera); // Draw the metallic fence

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.006f, 0.003f, 0.006f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(7.78f, 0.0f, 13.92f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		rotationAxis = glm::vec3(1.0f, 0.0f, 0.0f);
		rotationAngle = glm::radians(180.0f);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		fence4.Draw(shaderProgram, camera); // Draw the metallic fence




		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.015f, 0.012f, 0.009f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-10.0f, 0.0f, 8.5f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		rotationAxis = glm::vec3(1.0f, 0.0f, 0.0f);
		rotationAngle = glm::radians(180.0f);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		bench.Draw(shaderProgram, camera); // Draw bench

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.015f, 0.012f, 0.009f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(1.5f, 0.0f, 3.2f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		rotationAxis = glm::vec3(1.0f, 0.0f, 0.0f);
		rotationAngle = glm::radians(90.0f);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		bench.Draw(shaderProgram, camera); // Draw bench

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.015f, 0.012f, 0.009f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-2.5f, 0.0f, 3.2f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		rotationAxis = glm::vec3(1.0f, 0.0f, 0.0f);
		rotationAngle = glm::radians(90.0f);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		bench.Draw(shaderProgram, camera); // Draw bench

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.015f, 0.012f, 0.009f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-2.5f, 0.0f, -5.0f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		rotationAxis = glm::vec3(1.0f, 0.0f, 0.0f);
		rotationAngle = glm::radians(270.0f);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		bench.Draw(shaderProgram, camera); // Draw bench

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.015f, 0.012f, 0.009f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(1.5f, 0.0f, -5.0f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		rotationAxis = glm::vec3(1.0f, 0.0f, 0.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		bench.Draw(shaderProgram, camera); // Draw bench




		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.03f, 0.035f, 0.03f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-1.0f, -0.1f, -1.0f);
		rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		rotationAngle = glm::radians(-45.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		mainTree.Draw(shaderProgram, camera); // Draw mainTree

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.01f, 0.01f, 0.007f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(11.0f, 0.0f, 11.0f);
		rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		mainTree.Draw(shaderProgram, camera); // Draw oak tree

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.008f, 0.01f, 0.007f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(12.0f, 0.0f, -6.0f);
		rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		mainTree.Draw(shaderProgram, camera); // Draw oak tree

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.008f, 0.01f, 0.007f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(7.0f, 0.0f, -10.0f);
		rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		mainTree.Draw(shaderProgram, camera); // Draw oak tree

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.008f, 0.01f, 0.007f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(3.0f, 0.0f, -12.5f);
		rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		rotationAngle = glm::radians(0.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		mainTree.Draw(shaderProgram, camera); // Draw oak tree

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.008f, 0.01f, 0.007f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-5.0f, 0.0f, -12.0f);
		rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		rotationAngle = glm::radians(0.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		mainTree.Draw(shaderProgram, camera); // Draw oak tree

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.01f, 0.01f, 0.007f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(2.0f, 0.0f, 8.0f);
		rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		rotationAngle = glm::radians(65.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		mainTree.Draw(shaderProgram, camera); // Draw oak tree

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.005f, 0.006f, 0.003f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-4.0f, 0.0f, 8.0f);
		rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		rotationAngle = glm::radians(65.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		mainTree.Draw(shaderProgram, camera); // Draw oak tree

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.01f, 0.01f, 0.007f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-2.5f, 0.0f, 11.5f);
		rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		rotationAngle = glm::radians(155.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		mainTree.Draw(shaderProgram, camera); // Draw oak tree

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.005f, 0.005f, 0.005f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-5.5f, -0.3f, 3.0f);
		//rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		//rotationAngle = glm::radians(155.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		//modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		tree.Draw(shaderProgram, camera); // Draw tree

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.005f, 0.005f, 0.005f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(4.7f, -0.3f, 3.0f);
		//rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		//rotationAngle = glm::radians(155.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		//modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		tree.Draw(shaderProgram, camera); // Draw tree

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.005f, 0.005f, 0.005f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-5.5f, -0.3f, -5.0f);
		//rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		//rotationAngle = glm::radians(155.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		//modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		tree.Draw(shaderProgram, camera); // Draw tree

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.005f, 0.005f, 0.005f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(4.7f, -0.3f, -5.0f);
		//rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		//rotationAngle = glm::radians(155.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		//modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		tree.Draw(shaderProgram, camera); // Draw tree

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.013f, 0.013f, 0.013f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-2.0f, 0.0f, -4.0f);
		//rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		//rotationAngle = glm::radians(155.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		//modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		cat.Draw(shaderProgram, camera); // Draw cat
		
		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.013f, 0.01f, 0.04f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-14.4f, -0.1f, 9.6f);
		//rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		//rotationAngle = glm::radians(155.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		//modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		hedge.Draw(shaderProgram, camera); // Draw hedge

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.013f, 0.01f, 0.04f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-14.4f, -0.1f, 3.6f);
		//rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		//rotationAngle = glm::radians(155.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		//modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		hedge.Draw(shaderProgram, camera); // Draw hedge

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.013f, 0.01f, 0.04f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-14.4f, -0.1f, -3.4f);
		//rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		//rotationAngle = glm::radians(155.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		//modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		hedge.Draw(shaderProgram, camera); // Draw hedge

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.013f, 0.01f, 0.04f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-14.4f, -0.1f, -10.4f);
		//rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		//rotationAngle = glm::radians(155.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		//modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		hedge.Draw(shaderProgram, camera); // Draw hedge

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.013f, 0.01f, 0.04f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-10.4f, -0.1f, -14.4f);
		rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		rotationAngle = glm::radians(90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		hedge.Draw(shaderProgram, camera); // Draw hedge

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.013f, 0.01f, 0.04f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-5.4f, -0.1f, -14.4f);
		rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		rotationAngle = glm::radians(90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		hedge.Draw(shaderProgram, camera); // Draw hedge

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.013f, 0.01f, 0.04f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(1.2f, -0.1f, -14.4f);
		rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		rotationAngle = glm::radians(90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		hedge.Draw(shaderProgram, camera); // Draw hedge

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.013f, 0.01f, 0.06f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(8.7f, -0.1f, -14.4f);
		rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		rotationAngle = glm::radians(90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		hedge.Draw(shaderProgram, camera); // Draw hedge

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.013f, 0.01f, 0.06f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(14.4f, -0.1f, -7.4f);
		rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		rotationAngle = glm::radians(180.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		hedge.Draw(shaderProgram, camera); // Draw hedge

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.013f, 0.01f, 0.1f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(14.4f, -0.1f, 4.0f);
		rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		rotationAngle = glm::radians(180.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		hedge.Draw(shaderProgram, camera); // Draw hedge

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.013f, 0.01f, 0.08f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(6.4f, -0.1f, 14.4f);
		rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		hedge.Draw(shaderProgram, camera); // Draw hedge

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.013f, 0.01f, 0.06f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(0.3f, -0.1f, 14.4f);
		rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		hedge.Draw(shaderProgram, camera); // Draw hedge

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.013f, 0.01f, 0.03f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-11.3f, -0.1f, 14.4f);
		rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		hedge.Draw(shaderProgram, camera); // Draw hedge

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.013f, 0.01f, 0.03f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-8.4f, -0.1f, 17.4f);
		//rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		//rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		//modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		hedge.Draw(shaderProgram, camera); // Draw hedge

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.013f, 0.01f, 0.03f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-6.0f, -0.1f, 17.4f);
		//rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		//rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		//modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		hedge.Draw(shaderProgram, camera); // Draw hedge

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.013f, 0.01f, 0.01f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-7.0f, -0.1f, 20.2f);
		rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		hedge.Draw(shaderProgram, camera); // Draw hedge


		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(2.5f, 2.5f, 2.5f); // Reflect along the x-axis
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		translationVector3 = glm::vec3(-3.4f, 0.0f, 5.2f);
		rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		rotationAngle = glm::radians(-33.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		welcomeSign.Draw(shaderProgram, camera); // Draw welcomeSign
		
		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(3.5f, 0.1f, 3.5f); // Reflect along the x-axis
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		translationVector3 = glm::vec3(3.0f, 0.0f, -3.0f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-180.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		rotationAngle = glm::radians(90.0f);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		water.Draw(shaderProgram, camera); // Draw water



		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(2.5f, 2.5f, 2.5f); // Reflect along the x-axis
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		translationVector3 = glm::vec3(3.7f, -0.3f, -4.7f);
		//rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		//rotationAngle = glm::radians(-180.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		//modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		reed.Draw(shaderProgram, camera); // Draw reed

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(3.5f, 3.0f, 2.5f); // Reflect along the x-axis
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		translationVector3 = glm::vec3(2.6f, -0.3f, -4.8f);
		//rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		//rotationAngle = glm::radians(-180.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		//modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		reed.Draw(shaderProgram, camera); // Draw reed

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(1.0f, 1.0f, 1.0f); // Reflect along the x-axis
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		translationVector3 = glm::vec3(1.6f, -0.6f, -2.8f);
		//rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		//rotationAngle = glm::radians(-180.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		//modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		reed.Draw(shaderProgram, camera); // Draw reed

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(8.0f, 1.0f, 8.0f); // Reflect along the x-axis
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		translationVector3 = glm::vec3(0.6f, -0.5f, -1.6f);
		//rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		//rotationAngle = glm::radians(-180.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		//modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		reed.Draw(shaderProgram, camera); // Draw reed

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(8.0f, 1.0f, 8.0f); // Reflect along the x-axis
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		translationVector3 = glm::vec3(0.5f, -0.7f, -0.5f);
		//rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		//rotationAngle = glm::radians(-180.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		//modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		reed.Draw(shaderProgram, camera); // Draw reed

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(8.0f, 1.0f, 8.0f); // Reflect along the x-axis
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		translationVector3 = glm::vec3(0.2f, -0.7f, 1.5f);
		//rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		//rotationAngle = glm::radians(-180.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		//modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		reed.Draw(shaderProgram, camera); // Draw reed

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(8.0f, 1.0f, 8.0f); // Reflect along the x-axis
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		translationVector3 = glm::vec3(0.5f, -0.7f, 0.1f);
		//rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		//rotationAngle = glm::radians(-180.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		//modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		reed.Draw(shaderProgram, camera); // Draw reed

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(8.0f, 1.0f, 8.0f); // Reflect along the x-axis
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		translationVector3 = glm::vec3(-0.5f, -0.7f, 0.1f);
		//rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		//rotationAngle = glm::radians(-180.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		//modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		reed.Draw(shaderProgram, camera); // Draw reed

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(8.0f, 1.0f, 8.0f); // Reflect along the x-axis
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		translationVector3 = glm::vec3(-0.6f, -0.7f, -0.2f);
		//rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		//rotationAngle = glm::radians(-180.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		//modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		reed.Draw(shaderProgram, camera); // Draw reed

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(8.0f, 1.0f, 8.0f); // Reflect along the x-axis
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		translationVector3 = glm::vec3(-0.6f, -0.7f, 0.8f);
		//rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		//rotationAngle = glm::radians(-180.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		//modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		reed.Draw(shaderProgram, camera); // Draw reed

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(8.0f, 1.0f, 8.0f); // Reflect along the x-axis
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		translationVector3 = glm::vec3(-0.6f, -0.7f, -0.8f);
		//rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		//rotationAngle = glm::radians(-180.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		//modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		reed.Draw(shaderProgram, camera); // Draw reed

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(8.0f, 1.0f, 8.0f); // Reflect along the x-axis
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		translationVector3 = glm::vec3(-0.6f, -0.7f, -1.2f);
		//rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		//rotationAngle = glm::radians(-180.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		//modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		reed.Draw(shaderProgram, camera); // Draw reed

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(8.0f, 1.0f, 8.0f); // Reflect along the x-axis
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		translationVector3 = glm::vec3(-0.1f, -0.7f, -0.8f);
		//rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		//rotationAngle = glm::radians(-180.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		//modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		reed.Draw(shaderProgram, camera); // Draw reed

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(8.0f, 1.0f, 8.0f); // Reflect along the x-axis
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		translationVector3 = glm::vec3(-0.9f, -0.7f, -1.4f);
		//rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		//rotationAngle = glm::radians(-180.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		//modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		reed.Draw(shaderProgram, camera); // Draw reed

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(8.0f, 1.0f, 8.0f); // Reflect along the x-axis
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		translationVector3 = glm::vec3(-1.2f, -0.8f, 1.4f);
		//rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		//rotationAngle = glm::radians(-180.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		//modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		reed.Draw(shaderProgram, camera); // Draw reed

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(8.0f, 1.0f, 8.0f); // Reflect along the x-axis
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		translationVector3 = glm::vec3(-1.2f, -0.7f, 1.2f);
		//rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		//rotationAngle = glm::radians(-180.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		//modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		reed.Draw(shaderProgram, camera); // Draw reed

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(8.0f, 1.0f, 8.0f); // Reflect along the x-axis
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		translationVector3 = glm::vec3(-1.2f, -0.9f, 1.0f);
		//rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		//rotationAngle = glm::radians(-180.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		//modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		reed.Draw(shaderProgram, camera); // Draw reed

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(8.0f, 1.0f, 8.0f); // Reflect along the x-axis
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		translationVector3 = glm::vec3(1.2f, -0.6f, -1.2f);
		//rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		//rotationAngle = glm::radians(-180.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		//modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		reed.Draw(shaderProgram, camera); // Draw reed

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(8.0f, 1.0f, 8.0f); // Reflect along the x-axis
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		translationVector3 = glm::vec3(1.1f, -0.7f, -1.4f);
		//rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		//rotationAngle = glm::radians(-180.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		//modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		reed.Draw(shaderProgram, camera); // Draw reed

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(8.0f, 1.0f, 8.0f); // Reflect along the x-axis
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		translationVector3 = glm::vec3(1.3f, -0.6f, -1.0f);
		//rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		//rotationAngle = glm::radians(-180.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		//modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		reed.Draw(shaderProgram, camera); // Draw reed

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(8.0f, 1.0f, 8.0f); // Reflect along the x-axis
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		translationVector3 = glm::vec3(1.5f, -0.7f, -0.6f);
		//rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		//rotationAngle = glm::radians(-180.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		//modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		reed.Draw(shaderProgram, camera); // Draw reed

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(8.0f, 1.0f, 8.0f); // Reflect along the x-axis
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		translationVector3 = glm::vec3(1.1f, -0.6f, 0.2f);
		//rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		//rotationAngle = glm::radians(-180.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		//modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		reed.Draw(shaderProgram, camera); // Draw reed

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(8.0f, 1.0f, 8.0f); // Reflect along the x-axis
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		translationVector3 = glm::vec3(1.3f, -0.6f, 0.5f);
		//rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		//rotationAngle = glm::radians(-180.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		//modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		reed.Draw(shaderProgram, camera); // Draw reed

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(8.0f, 1.0f, 8.0f); // Reflect along the x-axis
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		translationVector3 = glm::vec3(1.5f, -0.6f, 0.8f);
		//rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		//rotationAngle = glm::radians(-180.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		//modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		reed.Draw(shaderProgram, camera); // Draw reed

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(8.0f, 1.0f, 8.0f); // Reflect along the x-axis
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		translationVector3 = glm::vec3(1.1f, -0.6f, -0.2f);
		//rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		//rotationAngle = glm::radians(-180.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		//modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		reed.Draw(shaderProgram, camera); // Draw reed

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(8.0f, 1.0f, 8.0f); // Reflect along the x-axis
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		translationVector3 = glm::vec3(1.2f, -0.7f, 0.1f);
		//rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		//rotationAngle = glm::radians(-180.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		//modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		reed.Draw(shaderProgram, camera); // Draw reed

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(8.0f, 1.0f, 8.0f); // Reflect along the x-axis
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		translationVector3 = glm::vec3(1.6f, -0.6f, 0.3f);
		//rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		//rotationAngle = glm::radians(-180.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		//modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		reed.Draw(shaderProgram, camera); // Draw reed



		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.001f, 0.001f, 0.001f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(4.0f, 0.0f, 10.2f);
		rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		horse.Draw(shaderProgram, camera); // Draw horse

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.0005f, 0.0005f, 0.0005f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(4.7f, 0.0f, 10.9f);
		rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		rotationAngle = glm::radians(-180.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		horse.Draw(shaderProgram, camera); // Draw horse

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.001f, 0.001f, 0.001f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(0.0f, 0.0f, 11.2f);
		rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		rotationAngle = glm::radians(107.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		horse.Draw(shaderProgram, camera); // Draw horse

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.02f, 0.02f, 0.02f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-5.0f, 0.0f, 11.2f);
		rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		rotationAngle = glm::radians(-75.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		deer1.Draw(shaderProgram, camera); // Draw deer

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.02f, 0.02f, 0.02f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-4.0f, 0.0f, 10.0f);
		rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		rotationAngle = glm::radians(-37.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		deer2.Draw(shaderProgram, camera); // Draw deer

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.03f, 0.03f, 0.03f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-1.0f, 0.0f, 7.0f);
		rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		rotationAngle = glm::radians(145.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		deer2.Draw(shaderProgram, camera); // Draw deer

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.038f, 0.038f, 0.038f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-6.3f, 0.642f, 8.2f);
		rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		rotationAngle = glm::radians(90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		bird.Draw(shaderProgram, camera); // Draw bird

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.036f, 0.036f, 0.036f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(5.5f, 0.626f, -3.2f);
		rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		bird.Draw(shaderProgram, camera); // Draw bird

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.038f, 0.038f, 0.038f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(0.0f, 2.7f, 0.0f);
		rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		rotationAngle = glm::radians(155.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		bird.Draw(shaderProgram, camera); // Draw bird

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.038f, 0.038f, 0.038f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-1.8f, 3.15f, -1.2f);
		rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		rotationAngle = glm::radians(155.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		bird.Draw(shaderProgram, camera); // Draw bird

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(3.0f, 0.01f, 3.0f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-11.5f, 0.0f, 3.6f);
		//rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		//rotationAngle = glm::radians(145.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		//modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		foundation2.Draw(shaderProgram, camera); // Draw foundation2

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(3.2f, 0.01f, 3.7f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(11.0f, 0.0f, 0.6f);
		//rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		//rotationAngle = glm::radians(145.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		//modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		foundation2.Draw(shaderProgram, camera); // Draw foundation2

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(3.0f, 0.01f, 3.0f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-11.5f, 0.0f, 3.6f);
		//rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		//rotationAngle = glm::radians(145.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		//modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		foundation2.Draw(shaderProgram, camera); // Draw foundation2

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(3.0f, 0.01f, 3.0f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-11.5f, 0.0f, -8.4f);
		//rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		//rotationAngle = glm::radians(145.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		//modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		foundation2.Draw(shaderProgram, camera); // Draw foundation2

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(3.0f, 0.01f, 3.0f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-11.5f, 0.0f, -2.4f);
		//rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		//rotationAngle = glm::radians(145.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		//modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		foundation2.Draw(shaderProgram, camera); // Draw foundation2

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(3.0f, 0.01f, 1.5f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-11.5f, 0.0f, -12.9f);
		//rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		//rotationAngle = glm::radians(145.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		//modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		foundation2.Draw(shaderProgram, camera); // Draw foundation2

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.7f, 0.7f, 0.7f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-13.6f, 0.02f, -12.9f);
		//rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		//rotationAngle = glm::radians(145.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		//modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		manger.Draw(shaderProgram, camera); // Draw manger

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.7f, 0.7f, 0.7f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-13.6f, 0.02f, 3.9f);
		//rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		//rotationAngle = glm::radians(145.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		//modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		manger.Draw(shaderProgram, camera); // Draw manger

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.7f, 0.7f, 0.7f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-8.1f, 0.02f, -8.9f);
		//rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		//rotationAngle = glm::radians(145.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		//modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		manger.Draw(shaderProgram, camera); // Draw manger

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.7f, 0.7f, 0.7f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-0.9f, 0.02f, -8.9f);
		//rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		//rotationAngle = glm::radians(145.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		//modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		manger.Draw(shaderProgram, camera); // Draw manger

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.7f, 0.7f, 0.7f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(6.5f, 0.02f, -8.9f);
		//rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		//rotationAngle = glm::radians(145.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		//modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		manger.Draw(shaderProgram, camera); // Draw manger

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.7f, 0.7f, 0.7f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(8.13f, 0.02f, -1.0f);
		//rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		//rotationAngle = glm::radians(145.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		//modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		manger.Draw(shaderProgram, camera); // Draw manger

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.7f, 0.7f, 0.7f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(8.13f, 0.02f, 8.0f);
		//rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		//rotationAngle = glm::radians(145.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		//modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		manger.Draw(shaderProgram, camera); // Draw manger

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.015f, 0.015f, 0.015f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(8.2f, 0.02f, -8.0f);
		//rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		//rotationAngle = glm::radians(145.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		//modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		duck.Draw(shaderProgram, camera); // Draw duck

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.015f, 0.015f, 0.015f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(8.6f, 0.02f, -5.0f);
		rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		rotationAngle = glm::radians(90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		duck.Draw(shaderProgram, camera); // Draw duck

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.015f, 0.015f, 0.015f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(9.0f, 0.02f, -10.0f);
		rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		duck.Draw(shaderProgram, camera); // Draw duck

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.015f, 0.015f, 0.015f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(10.0f, -0.2f, -12.6f);
		rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		duck.Draw(shaderProgram, camera); // Draw duck

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.015f, 0.015f, 0.015f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(11.2f, -0.2f, -12.0f);
		rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		rotationAngle = glm::radians(-70.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		duck.Draw(shaderProgram, camera); // Draw duck

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.015f, 0.015f, 0.015f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(12.6f, -0.2f, -11.0f);
		rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		rotationAngle = glm::radians(45.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		duck.Draw(shaderProgram, camera); // Draw duck

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.03f, 0.03f, 0.03f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(3.6f, 0.12f, -10.5f);
		rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		rotationAngle = glm::radians(-135.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		tamarin.Draw(shaderProgram, camera); // Draw tamarin

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.03f, 0.03f, 0.03f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(3.35f, 0.84f, -12.6f);
		rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		tamarin.Draw(shaderProgram, camera); // Draw tamarin

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.03f, 0.03f, 0.03f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(0.6f, 0.12f, -11.5f);
		rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		rotationAngle = glm::radians(-45.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		tamarin.Draw(shaderProgram, camera); // Draw tamarin

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.01f, 0.01f, 0.01f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-3.6f, 0.12f, -11.5f);
		rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		rotationAngle = glm::radians(-45.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		monkey.Draw(shaderProgram, camera); // Draw monkey

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.01f, 0.01f, 0.01f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-5.6f, 0.1f, -11.5f);
		rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		monkey.Draw(shaderProgram, camera); // Draw monkey

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.01f, 0.01f, 0.01f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-7.6f, 0.1f, -10.5f);
		rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		rotationAngle = glm::radians(-180.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		monkey.Draw(shaderProgram, camera); // Draw monkey

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.01f, 0.01f, 0.01f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-8.6f, 1.3f, -8.9f);
		rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		rotationAngle = glm::radians(-180.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(90.0f);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		monkey.Draw(shaderProgram, camera); // Draw monkey

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.007f, 0.007f, 0.007f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-4.6f, 1.3f, -8.1f);
		rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(90.0f);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		monkey.Draw(shaderProgram, camera); // Draw monkey

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.01f, 0.01f, 0.01f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-12.4f, 0.0f, 0.5f);
		rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		rotationAngle = glm::radians(25.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		lion.Draw(shaderProgram, camera); // draw lion

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.005f, 0.005f, 0.005f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-12.1f, 0.0f, 1.3f);
		rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		rotationAngle = glm::radians(77.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		lion.Draw(shaderProgram, camera); // draw lion

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.01f, 0.01f, 0.01f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-11.0f, 0.0f, -1.5f);
		rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		lion.Draw(shaderProgram, camera); // draw lion

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.01f, 0.01f, 0.01f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-10.0f, 0.0f, 4.0f);
		rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		rotationAngle = glm::radians(110.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		lion.Draw(shaderProgram, camera); // draw lion

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.3f, 0.3f, 0.3f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-10.0f, 0.0f, -8.0f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		tiger.Draw(shaderProgram, camera); // draw tiger

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.3f, 0.3f, 0.3f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-12.0f, 0.0f, -12.0f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		tiger.Draw(shaderProgram, camera); // draw tiger

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.23f, 0.23f, 0.23f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-9.0f, 0.0f, -5.0f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		rotationAxis = glm::vec3(1.0f, 0.0f, 0.0f);
		rotationAngle = glm::radians(68.0f);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		tiger.Draw(shaderProgram, camera); // draw tiger

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.23f, 0.23f, 0.23f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(-12.0f, 0.0f, -5.0f);
		rotationAxis = glm::vec3(0.0f, 0.0f, 1.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		rotationAxis = glm::vec3(1.0f, 0.0f, 0.0f);
		rotationAngle = glm::radians(-102.0f);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		tiger.Draw(shaderProgram, camera); // draw tiger

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.03f, 0.03f, 0.03f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(10.0f, 0.0f, 7.0f);
		rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		rotationAngle = glm::radians(-90.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		bear.Draw(shaderProgram, camera); // draw bear

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.027f, 0.027f, 0.027f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(9.5f, 0.0f, 9.7f);
		rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		rotationAngle = glm::radians(180.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		bear.Draw(shaderProgram, camera); // draw bear

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.023f, 0.023f, 0.023f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(9.55f, 0.0f, 12.3f);
		rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		rotationAngle = glm::radians(135.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		bear.Draw(shaderProgram, camera); // draw bear

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.004f, 0.0035f, 0.004f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(9.7f, 0.0f, 3.0f);
		rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		rotationAngle = glm::radians(135.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		camel.Draw(shaderProgram, camera); // draw camel

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.004f, 0.0035f, 0.004f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(10.7f, 0.0f, -1.0f);
		rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		rotationAngle = glm::radians(220.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		camel.Draw(shaderProgram, camera); // draw camel

		modelMatrix3 = glm::mat4(1.0f);  // Identity matrix for foundationMatrix
		scalingVector3 = glm::vec3(0.0028f, 0.003f, 0.0028f); // Adjust as needed for correct proportion
		translationVector3 = glm::vec3(10.7f, 0.0f, 1.5f);
		rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
		rotationAngle = glm::radians(157.0f);
		modelMatrix3 = glm::translate(modelMatrix3, translationVector3);
		modelMatrix3 = glm::rotate(modelMatrix3, rotationAngle, rotationAxis);
		modelMatrix3 = glm::scale(modelMatrix3, scalingVector3);
		shaderProgram.Activate();
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "modelMatrix"), 1, GL_FALSE, glm::value_ptr(modelMatrix3));
		camel.Draw(shaderProgram, camera); // draw camel

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		// Since the cubemap will always have a depth of 1.0, we need that equal sign so it doesn't get discarded
		glDepthFunc(GL_LEQUAL);

		skyboxShader.Activate();

		// Updates and exports the camera matrix to the Vertex Shader
		glm::mat4 view = glm::mat4(1.0f); // View matrix for the camera
		glm::mat4 projection = glm::mat4(1.0f); // Projection matrix

		// Update the view matrix based on camera's position and orientation
		view = glm::mat4(glm::mat3(glm::lookAt(camera.Position, camera.Position + camera.Orientation, camera.Up)));

		// Set the projection matrix for a perspective projection
		projection = glm::perspective(glm::radians(60.0f), (float)width / height, 0.01f, 100.0f);


		glUniformMatrix4fv(glGetUniformLocation(skyboxShader.ID, "view"), 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(glGetUniformLocation(skyboxShader.ID, "projection"), 1, GL_FALSE, glm::value_ptr(projection));

		// Draws the cubemap as the last object so we can save a bit of performance by discarding all fragments
		// where an object is present (a depth of 1.0f will always fail against any object's depth value)
		glBindVertexArray(skyboxVAO);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_CUBE_MAP, cubemapTexture);
		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);

		// Switch back to the normal depth function
		glDepthFunc(GL_LESS);


		// Swap the back buffer with the front buffer
		glfwSwapBuffers(window);
		// Take care of all GLFW events
		glfwPollEvents();
	}

	// Delete all the objects we've created
	shaderProgram.Delete();
	skyboxShader.Delete();

	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
	return 0;
}