#include <string>
#include <sstream>
#include <functional>
#include <iostream>

#include <GLFW/glfw3.h>

#include <glm/vec3.hpp>
#include <glm/matrix.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
  
#include "GraphicsManager.hpp"
#include "Mesh.hpp"

Mesh *display;

void render(double current_time, GraphicsManager *gm) {
	/** Drawing Code Goes Here! **/

	/** 5. Drawing objects using Mesh.cpp **/
	glColor4f(0.7f, 0.8f, 0.8f, 1.0f);
	display->draw();
}

int main(int argc, char **argv) {
	std::string title = "OpenGL Tutorial";
	std::function<void(double, GraphicsManager*)> pass = &render;

	const char *path = argc > 1 ? argv[1] : "../../obj/utah-teapot.obj";

	display = new Mesh(path);

	GraphicsManager *gm = new GraphicsManager(title, pass);

	gm->set_gl_version(2, 1); // Set OpenGL profile to 2.1
	gm->execute();

	return 0; 
}