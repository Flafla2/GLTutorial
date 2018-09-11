#include <string>
#include <functional>

#include <GLFW/glfw3.h>
  
#include "GraphicsManager.hpp"

void render(double current_time) {
	/** Drawing Code Goes Here! **/

}

int main() {
	std::string title = "OpenGL Tutorial";
	std::function<void(double)> pass = &render;

	GraphicsManager *gm = new GraphicsManager(title, pass);

	gm->execute();

	return 0; 
}