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

	/** 3. Transformations **/
	glTranslatef(0.0f, 0.2f, 0.0f); // applied in all cases
	glPushMatrix();
		// Transformations are in reverse order 
		glTranslatef(-0.5f, 0, 0);
		glRotatef(45.0f, 0, 0, 1);
		glScalef(0.2f, 0.2f, 0.2f);
		
		glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
		draw_box();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0.5f, 0, 0);
		glRotatef(20.0f, 0, 0, 1);
		glScalef(0.2f, 0.4f, 0.2f);
		
		glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
		draw_box();

		// Nested transformations
		glPushMatrix();
			glScalef(0.5f, 0.5f, 0.5f);
		
			glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
			draw_box();
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();
		glm::mat4 custom_rot(1.0f); // identity
		custom_rot = glm::rotate(custom_rot, (float)glm::radians(10.0f * current_time), glm::vec3(0,0,1));
		custom_rot = glm::scale(custom_rot, glm::vec3(0.2f, 0.2f, 0.2f));
		// glLoadMatrixf replaces the current matrix on the stack
		glLoadMatrixf(glm::value_ptr(custom_rot));
		// glMultMatrixf multiplies the current matrix by this one
		// glMultMatrixf(glm::value_ptr(custom_rot));

		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		draw_box();
	glPopMatrix();
}

int main(int argc, char **argv) {
	std::string title = "OpenGL Tutorial";
	std::function<void(double, GraphicsManager*)> pass = &render;

	GraphicsManager *gm = new GraphicsManager(title, pass);

	gm->set_gl_version(2, 1); // Set OpenGL profile to 2.1
	gm->execute();

	return 0; 
}