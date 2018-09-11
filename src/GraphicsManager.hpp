#pragma once

#include <functional>
#include <string>

#include <GLFW/glfw3.h>

class GraphicsManager {
	
public:
	GraphicsManager(std::string title, std::function<void(double)> render_fn);
	bool execute();

private:
	std::string title;
	std::function<void(double)> render_fn;

	GLFWwindow *window;

};