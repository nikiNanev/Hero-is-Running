#ifndef GLFW_INITIALIZE_H
#define GLFW_INITIALIZE_H

#include <string>
#include <iostream>
#include <memory>

class GLFWInitialize
{
	GLFWwindow *window;
	std::string title;
	const std::string error_text_glfw_window = "Failed to create Window.";
	const unsigned int SCR_WIDTH = 800;
	const unsigned int SCR_HEIGHT = 600;

public:
	GLFWInitialize(std::string title, std::unique_ptr<Callbacks> &callback)
	{
		// glfw: initialize and configure
		// ------------------------------
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

		this->window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, title.c_str(), glfwGetPrimaryMonitor(), NULL);

		if (this->window == NULL)
		{
			std::cout << this->error_text_glfw_window << std::endl;
			glfwTerminate();
		}
		glfwMakeContextCurrent(this->window);
		glfwSetFramebufferSizeCallback(this->window, callback->framebuffer_size);
		glfwSetCursorPosCallback(this->window, callback->mouse_input);
		glfwSetScrollCallback(this->window, callback->mouse_scroll);

		// tell GLFW to capture our mouse
		glfwSetInputMode(this->window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	}
	~GLFWInitialize() {}
	GLFWwindow *getWindow()
	{
		return this->window;
	}
};

#endif
