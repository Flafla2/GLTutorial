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

void render(double current_time, GraphicsManager *gm) {
	/** Drawing Code Goes Here! **/

	/** 1. Drawing lines, and lines with thickness **/
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glLineWidth(1.0f);
	glBegin(GL_LINES);
		glVertex3f(-0.5f, 0, 0);
		glVertex3f(0.5f, 0, 0);
	glEnd();

	glLineWidth(5.0f);
	glBegin(GL_LINES);
		glColor4f(1.0f, 0, 0, 1.0f);
		glVertex3f(-0.2f, -0.4, 0);
		glColor4f(0, 0, 1.0f, 1.0f);
		glVertex3f(0.2f, 0.4, 0);
	glEnd();
}

int main(int argc, char **argv) {
	std::string title = "OpenGL Tutorial";
	std::function<void(double, GraphicsManager*)> pass = &render;

	GraphicsManager *gm = new GraphicsManager(title, pass);

	gm->set_gl_version(2, 1); // Set OpenGL profile to 2.1
	gm->execute();

	return 0; 
}