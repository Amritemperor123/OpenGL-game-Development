#include"lib.h"

Vertex vertices[] =
{
	// Front face
	{ glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec3(0.9f, 0.2f, 0.2f), glm::vec3(0.f, 0.f, 1.f) },
	{ glm::vec3(0.5f, -0.5f, 0.5f), glm::vec3(0.9f, 0.2f, 0.2f), glm::vec3(0.f, 0.f, 1.f) },
	{ glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(0.9f, 0.2f, 0.2f), glm::vec3(0.f, 0.f, 1.f) },
	{ glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec3(0.9f, 0.2f, 0.2f), glm::vec3(0.f, 0.f, 1.f) },

	// Back face
	{ glm::vec3(0.5f, -0.5f, -0.5f), glm::vec3(0.2f, 0.7f, 0.9f), glm::vec3(0.f, 0.f, -1.f) },
	{ glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(0.2f, 0.7f, 0.9f), glm::vec3(0.f, 0.f, -1.f) },
	{ glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec3(0.2f, 0.7f, 0.9f), glm::vec3(0.f, 0.f, -1.f) },
	{ glm::vec3(0.5f, 0.5f, -0.5f), glm::vec3(0.2f, 0.7f, 0.9f), glm::vec3(0.f, 0.f, -1.f) },

	// Left face
	{ glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(0.2f, 0.9f, 0.4f), glm::vec3(-1.f, 0.f, 0.f) },
	{ glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec3(0.2f, 0.9f, 0.4f), glm::vec3(-1.f, 0.f, 0.f) },
	{ glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec3(0.2f, 0.9f, 0.4f), glm::vec3(-1.f, 0.f, 0.f) },
	{ glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec3(0.2f, 0.9f, 0.4f), glm::vec3(-1.f, 0.f, 0.f) },

	// Right face
	{ glm::vec3(0.5f, -0.5f, 0.5f), glm::vec3(0.9f, 0.8f, 0.2f), glm::vec3(1.f, 0.f, 0.f) },
	{ glm::vec3(0.5f, -0.5f, -0.5f), glm::vec3(0.9f, 0.8f, 0.2f), glm::vec3(1.f, 0.f, 0.f) },
	{ glm::vec3(0.5f, 0.5f, -0.5f), glm::vec3(0.9f, 0.8f, 0.2f), glm::vec3(1.f, 0.f, 0.f) },
	{ glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(0.9f, 0.8f, 0.2f), glm::vec3(1.f, 0.f, 0.f) },

	// Top face
	{ glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec3(0.7f, 0.3f, 0.9f), glm::vec3(0.f, 1.f, 0.f) },
	{ glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(0.7f, 0.3f, 0.9f), glm::vec3(0.f, 1.f, 0.f) },
	{ glm::vec3(0.5f, 0.5f, -0.5f), glm::vec3(0.7f, 0.3f, 0.9f), glm::vec3(0.f, 1.f, 0.f) },
	{ glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec3(0.7f, 0.3f, 0.9f), glm::vec3(0.f, 1.f, 0.f) },

	// Bottom face
	{ glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(0.3f, 0.6f, 0.9f), glm::vec3(0.f, -1.f, 0.f) },
	{ glm::vec3(0.5f, -0.5f, -0.5f), glm::vec3(0.3f, 0.6f, 0.9f), glm::vec3(0.f, -1.f, 0.f) },
	{ glm::vec3(0.5f, -0.5f, 0.5f), glm::vec3(0.3f, 0.6f, 0.9f), glm::vec3(0.f, -1.f, 0.f) },
	{ glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec3(0.3f, 0.6f, 0.9f), glm::vec3(0.f, -1.f, 0.f) }
};

GLuint indices[] =
{
	0, 1, 2, 0, 2, 3,
	4, 5, 6, 4, 6, 7,
	8, 9, 10, 8, 10, 11,
	12, 13, 14, 12, 14, 15,
	16, 17, 18, 16, 18, 19,
	20, 21, 22, 20, 22, 23
};

unsigned nrOfIndices = sizeof(indices) / sizeof(GLuint);

struct OrbitCamera
{
	float yaw = -90.f;
	float pitch = -20.f;
	float distance = 6.f;
	float sensitivity = 0.12f;
	float minPitch = -80.f;
	float maxPitch = 80.f;
	float minDistance = 2.f;
	float maxDistance = 20.f;
	bool firstMouse = true;
	double lastMouseX = 0.0;
	double lastMouseY = 0.0;
};

OrbitCamera gCamera;
glm::vec3 gOrbitTarget(0.f);

glm::vec3 getCameraPosition()
{
	const float yawRadians = glm::radians(gCamera.yaw);
	const float pitchRadians = glm::radians(gCamera.pitch);

	glm::vec3 offset;
	offset.x = cos(pitchRadians) * cos(yawRadians);
	offset.y = sin(pitchRadians);
	offset.z = cos(pitchRadians) * sin(yawRadians);

	return gOrbitTarget - glm::normalize(offset) * gCamera.distance;
}

void frame_buffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	if (gCamera.firstMouse)
	{
		gCamera.lastMouseX = xpos;
		gCamera.lastMouseY = ypos;
		gCamera.firstMouse = false;
	}

	const float xoffset = static_cast<float>(xpos - gCamera.lastMouseX) * gCamera.sensitivity;
	const float yoffset = static_cast<float>(gCamera.lastMouseY - ypos) * gCamera.sensitivity;

	gCamera.lastMouseX = xpos;
	gCamera.lastMouseY = ypos;

	gCamera.yaw += xoffset;
	gCamera.pitch += yoffset;
	gCamera.pitch = glm::clamp(gCamera.pitch, gCamera.minPitch, gCamera.maxPitch);
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	gCamera.distance -= static_cast<float>(yoffset) * 0.5f;
	gCamera.distance = glm::clamp(gCamera.distance, gCamera.minDistance, gCamera.maxDistance);
}

void updateInput(GLFWwindow* window, glm::vec3& position, glm::vec3& rotation)
{
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		position.z -= 0.03f;
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		position.z += 0.03f;
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		position.x -= 0.03f;
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		position.x += 0.03f;
	}
	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
	{
		rotation.y += 0.75f;
	}
	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
	{
		rotation.y -= 0.75f;
	}
	if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS)
	{
		gCamera.distance -= 0.05f;
		gCamera.distance = glm::max(gCamera.distance, gCamera.minDistance);
	}
	if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS)
	{
		gCamera.distance += 0.05f;
		gCamera.distance = glm::min(gCamera.distance, gCamera.maxDistance);
	}
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
}

int main()
{
	glfwInit();

	const int WINDOW_HEIGHT = 1080;
	const int WINDOW_WIDTH = 1920;
	int frameBufferHeight = 0;
	int frameBufferWidth = 0;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

	GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "OpenGL Window", NULL, NULL);
	if (!window)
	{
		std::cerr << "ERROR::MAIN::WINDOW_INIT_FAILED\n";
		glfwTerminate();
		return -1;
	}

	glfwGetFramebufferSize(window, &frameBufferWidth, &frameBufferHeight);
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cerr << "ERROR::MAIN::GLAD_INIT_FAILED\n";
		glfwDestroyWindow(window);
		glfwTerminate();
		return -1;
	}

	glfwSetFramebufferSizeCallback(window, frame_buffer_size_callback);
	glfwSetCursorPosCallback(window, mouse_callback);
	glfwSetScrollCallback(window, scroll_callback);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	Shader core_program("vertex_core.glsl", "fragment_core.glsl");

	ModelPlaceholder modelPlaceholder;
	modelPlaceholder.printStatus();

	GLuint VAO = 0;
	GLuint VBO = 0;
	GLuint EBO = 0;

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, position));
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, color));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, normal));
	glEnableVertexAttribArray(2);

	glBindVertexArray(0);

	glm::vec3 position(0.f);
	glm::vec3 rotation(0.f);
	glm::vec3 scale(1.f);

	glm::vec3 worldUp(0.f, 1.f, 0.f);
	glm::vec3 camTarget(0.f, 0.f, 0.f);
	glm::vec3 camPos = getCameraPosition();
	glm::mat4 ViewMatrix = glm::lookAt(camPos, camTarget, worldUp);

	float fov = 60.f;
	float nearplane = 0.1f;
	float farplane = 1000.f;
	glm::mat4 ProjectionMatrix = glm::perspective(
		glm::radians(fov),
		static_cast<float>(frameBufferWidth) / static_cast<float>(frameBufferHeight),
		nearplane,
		farplane
	);

	glm::vec3 lightPos0(2.f, 3.f, 2.f);

	core_program.setMat4fv(ViewMatrix, "ViewMatrix");
	core_program.setMat4fv(ProjectionMatrix, "ProjectionMatrix");
	core_program.setVec3f(lightPos0, "lightPos0");
	core_program.setVec3f(camPos, "camPos");

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		updateInput(window, position, rotation);
		gOrbitTarget = position;
		camPos = getCameraPosition();
		ViewMatrix = glm::lookAt(camPos, gOrbitTarget, worldUp);

		glClearColor(0.08f, 0.08f, 0.12f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glm::mat4 ModelMatrix(1.f);
		ModelMatrix = glm::translate(ModelMatrix, position);
		ModelMatrix = glm::rotate(ModelMatrix, glm::radians(rotation.x), glm::vec3(1.f, 0.f, 0.f));
		ModelMatrix = glm::rotate(ModelMatrix, glm::radians(rotation.y), glm::vec3(0.f, 1.f, 0.f));
		ModelMatrix = glm::rotate(ModelMatrix, glm::radians(rotation.z), glm::vec3(0.f, 0.f, 1.f));
		ModelMatrix = glm::scale(ModelMatrix, scale);

		core_program.setMat4fv(ModelMatrix, "ModelMatrix");
		core_program.setMat4fv(ViewMatrix, "ViewMatrix");
		core_program.setVec3f(camPos, "camPos");

		glfwGetFramebufferSize(window, &frameBufferWidth, &frameBufferHeight);
		ProjectionMatrix = glm::perspective(
			glm::radians(fov),
			static_cast<float>(frameBufferWidth) / static_cast<float>(frameBufferHeight),
			nearplane,
			farplane
		);
		core_program.setMat4fv(ProjectionMatrix, "ProjectionMatrix");

		core_program.use();
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, nrOfIndices, GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(window);

		glBindVertexArray(0);
		glUseProgram(0);
	}

	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}
