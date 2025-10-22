#include "glad/glad.h"

#include <GLFW/glfw3.h>
#include <GL/glcorearb.h>
#include <iostream>
#include <string>
#include <memory>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "shader.h"

#include "loaders/texture_loader.h"
#include "callbacks.h"
#include "input_processing.h"

#include "glfw_initialize.h"

#include "level/level.h"
#include "player/player.h"
#include "player/player_profile.h"
#include "scores/score.h"
#include "player/achievements.h"
#include "enemy/enemy.h"
#include "ui/main_menu.h"
#include "map/map.h"


using std::cout;
using std::endl;
using std::vector;
using std::string;

// timing
float deltaTime = 0.0f;
float lastFrame = 0.0f;

const string error_text_glad_initialize = "Failed to initialize GLAD.";

auto callback = std::make_unique<Callbacks>();
auto input = std::make_unique<InputProcessing>();

int main(void) {
	
	//GLFW Initialization
	GLFWInitialize *glfwInit = new GLFWInitialize("Hero is Running", callback);

	// glad: load all OpenGL function pointers
	// ---------------------------------------
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		cout << error_text_glad_initialize << endl;
		return -1;
	}

	// configure global opengl state
	// -----------------------------
	glEnable(GL_DEPTH_TEST);

	// build and compile our shader zprogram
	// ------------------------------------
	Shader shader("../shaders/vertex.glsl",
			      "../shaders/fragment.glsl");

	// set up vertex data (and buffer(s)) and configure vertex attributes
	// ------------------------------------------------------------------
	float vertices[] = {
	    -1.0f, -1.0f, 0.0f, 0.0f, 0.0f,
	     1.0f, -1.0f, 0.0f, 1.0f, 0.0f,
	     1.0f,  1.0f, 0.0f, 1.0f, 1.0f,
	     
	    -1.0f, -1.0f, 0.0f, 0.0f, 0.0f,
	     1.0f,  1.0f, 0.0f, 1.0f, 1.0f,
	    -1.0f,  1.0f, 0.0f, 0.0f, 1.0f};
	// first, configure the cube's VAO (and VBO)
	unsigned int planeVBO, planeVAO;
	glGenVertexArrays(1, &planeVAO);
	glGenBuffers(1, &planeVBO);
	
	glBindVertexArray(planeVAO);
	
	glBindBuffer(GL_ARRAY_BUFFER, planeVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices,
		     GL_STATIC_DRAW);

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float),
			      (void *)0);
	glEnableVertexAttribArray(0);
	// texture attribute
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float),
			      (void *)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	// Load Textures
	stbi_set_flip_vertically_on_load(true);
	
	unsigned int mapID;
	TextureLoader tl1("../images/2D_topdown.png", mapID);
	shader.setInt("map_2d", 0);
	shader.use();
	
	//Load level
	auto level = std::make_unique<Level>(5);

	//Load Player
	auto player = std::make_unique<Player>(1, 100, 25, 30, 5.0f, 2.0f);
	
	//Initialize an enemy
	auto enemy = std::make_unique<Enemy>(0, "Buggy", 1, 1);
	
	//Score board initialization
	auto score = std::make_unique<Score>();
	
	auto map = std::make_unique<Map>();

	// render loop
	// -----------
	while (!glfwWindowShouldClose(glfwInit->getWindow())) {
		// per-frame time logic
		// --------------------
		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		// input
		// -----
		input->keyboard_input(glfwInit->getWindow(), deltaTime);

		// render
		// ------
		glClearColor(0.1f, 0.3f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		
		// be sure to activate shader when setting uniforms/drawing
		shader.use();
		
		map->draw(planeVAO, mapID);
		// glfw: swap buffers and poll IO events (keys pressed/released,
		// mouse moved etc.)
		// -------------------------------------------------------------------------------
		glfwSwapBuffers(glfwInit->getWindow());
		glfwPollEvents();
	}

	// optional: de-allocate all resources once they've outlived their
	// purpose:
	// ------------------------------------------------------------------------
	glDeleteVertexArrays(1, &planeVAO);
	glDeleteBuffers(1, &planeVBO);

	// glfw: terminate, clearing all previously allocated GLFW resources.
	// ------------------------------------------------------------------
	glfwTerminate();
	return 0;
}	
