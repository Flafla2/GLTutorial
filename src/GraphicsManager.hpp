#pragma once

#include <functional>
#include <string>

#include <GLFW/glfw3.h>
#include <glm/vec3.hpp>
#include <glm/gtc/quaternion.hpp>

#include "Color.hpp"

class GraphicsManager {
	
public:
	GraphicsManager(std::string title, std::function<void(double, GraphicsManager*)> render_fn);
	bool execute();

	void set_gl_version(int major, int minor) {
		gl_major_version = major;
		gl_minor_version = minor;
	}
	float aspect() { return ((float)width()) / ((float)height()); }
	int width() { return 640; }
	int height() { return 480; }
	void set_clear_color(Color c) { clear_color = c; }

private:
	std::string title;
	std::function<void(double, GraphicsManager*)> render_fn;

	GLFWwindow *window;
	int gl_major_version = 2;
	int gl_minor_version = 1;

	Color clear_color = Color(0.2f, 0.2f, 0.3f, 1.0f);
};