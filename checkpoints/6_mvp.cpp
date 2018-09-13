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

void draw_box() {
	glBegin(GL_TRIANGLES);
		glVertex3f(-0.5f, -0.5f, 0);
		glVertex3f(-0.5f, 0.5f, 0);
		glVertex3f(0.5f, -0.5f, 0);
		glVertex3f(-0.5f, 0.5f, 0);
		glVertex3f(0.5f, 0.5f, 0);
		glVertex3f(0.5f, -0.5f, 0);
	glEnd();
}

void render(double current_time, GraphicsManager *gm) {
	/** Drawing Code Goes Here! **/

	/** 6. Example Model / View / Projection matrix config for scene **/
	glColor4f(0.7f, 0.8f, 0.8f, 1.0f);
	// Model matrix encodes object position
	glm::mat4 model(1.0f);
	model = glm::scale(model, glm::vec3(5, 5, 5));
	model = glm::rotate(model, (float)glm::radians(-25.0f * current_time), glm::vec3(0, 1, 0));
	model = glm::translate(model, glm::vec3(0, 0, 0));
	// View matrix encodes camera position / orientation
	glm::mat4 view(1.0f);
	view = glm::rotate(view, glm::radians(35.0f), glm::vec3(1, 0, 0));
	view = glm::rotate(view, glm::radians(-90.0f), glm::vec3(0, 1, 0));
	view = glm::translate(view, glm::vec3(-2.0f, -1.0f, 0));
	// Projection matrix encodes perspective matrix
	glm::mat4 projection = glm::perspective(glm::radians(90.0f), gm->aspect(), 0.1f, 40.0f);
	
	// We can call this once per frame
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixf(glm::value_ptr(projection));
	// We need to call this once per object rendered
	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixf(glm::value_ptr(view * model));

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