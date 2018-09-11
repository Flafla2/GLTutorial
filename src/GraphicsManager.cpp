#include "GraphicsManager.hpp"

GraphicsManager::GraphicsManager(
	std::string title, 
	std::function<void(double)> render_fn) : title(title), render_fn(render_fn) {

}

bool GraphicsManager::execute() {
	if(!glfwInit())
		return false;

	window = glfwCreateWindow(640, 480, title.c_str(), NULL, NULL);

	if (!window)
    {
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        render_fn(glfwGetTime());

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return true;
}