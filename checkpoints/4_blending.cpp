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
	
	/** 4. Blend modes **/
	glEnable(GL_BLEND);
	// Alpha blending (more on this in later lectures!)
	// Final color evaluates to [s.rgb * s.a + d.rgb * (1 - s.a)]
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glPushMatrix();

		glScalef(0.5f, 0.5f, 0.5f);

		glPushMatrix();

			glColor4f(1.0f, 0, 0, 0.5f);
			glTranslatef(-0.1f, -0.1f, 0);
			draw_box();

		glPopMatrix();

		glColor4f(0, 0, 1.0f, 0.5f);
		glTranslatef(0.1f, 0.1f, 0);
		draw_box();

	glPopMatrix();

	glDisable(GL_BLEND);
}

int main(int argc, char **argv) {
	std::string title = "OpenGL Tutorial";
	std::function<void(double, GraphicsManager*)> pass = &render;

	GraphicsManager *gm = new GraphicsManager(title, pass);

	gm->set_gl_version(2, 1); // Set OpenGL profile to 2.1
	gm->execute();

	return 0; 
}