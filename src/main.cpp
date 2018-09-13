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

	/** 1. Drawing lines, and lines with thickness **/

	/*****
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
	*****/

	/** 2. Drawing Triangles w/ Color **/
	/*****
	glBegin(GL_TRIANGLES);
		glVertex3f(-0.5f, -0.5f, 0);
		glVertex3f(-0.5f, 0.5f, 0);
		glVertex3f(0.5f, -0.5f, 0);

		//glColor4f(0.0f, 1.0f, 1.0f, 1.0f);
		glVertex3f(-0.5f, 0.5f, 0);
		glVertex3f(0.5f, 0.5f, 0);
		glVertex3f(0.5f, -0.5f, 0);
	glEnd();
	******/

	/** 3. Transformations **/
	/*****
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
	*****/

	/** 4. Drawing objects using Mesh.cpp **/
	/*****
	glColor4f(0.7f, 0.8f, 0.8f, 1.0f);
	display->draw();
	*****/

	/** 5. Example Model / View / Projection matrix config for scene **/
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

	// display->draw();

	/** 6. Same as above (up to before display->draw), but with lighting and depth **/
	glm::vec3 light_pos = glm::vec3(0, sinf(current_time), cosf(current_time)) * 0.17f;

	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);

	GLfloat light_ambient[] = { 0.1, 0.1, 0.1, 1.0 };
	GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_specular[] = { 0, 0, 0, 1.0 };
	GLfloat light_position[] = { light_pos.x, light_pos.y, light_pos.z, 1.0 };
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 0.0f);
	glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.0f);
	glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 1.0f);

	glColorMaterial (GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glShadeModel (GL_SMOOTH);

	glColor4f(0.7f, 0.8f, 0.8f, 1.0f);
	display->draw();
	glDisable(GL_LIGHT0);
	glDisable(GL_LIGHTING);
	glDisable(GL_COLOR_MATERIAL);

	glPointSize(5);
	glBegin(GL_POINTS);
	glColor4f(1.0, 1.0, 1.0, 1.0f);
	glVertex3f(light_pos.x, light_pos.y, light_pos.z);
	glEnd();

	glDisable(GL_DEPTH_TEST);
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