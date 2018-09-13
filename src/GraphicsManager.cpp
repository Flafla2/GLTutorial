#include "GraphicsManager.hpp"

GraphicsManager::GraphicsManager(
	std::string title, 
	std::function<void(double, GraphicsManager*)> render_fn) : title(title), render_fn(render_fn) {

}

bool GraphicsManager::execute() {
	if(!glfwInit())
		return false;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, gl_major_version);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, gl_minor_version);

	window = glfwCreateWindow(640, 480, title.c_str(), NULL, NULL);

	if (!window)
    {
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(window);
    glfwGetCursorPos(window, &last_mx, &last_my);

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.2f, 0.2f, 0.3f, 1.f);
        glLoadIdentity();

        // handle looking mechanics
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);
        double difx = xpos - last_mx;
        double dify = ypos - last_my;
        last_mx = xpos;
        last_my = ypos;

        rot = rot * glm::quat(glm::vec3(dify, difx, 0) * 0.1f);

        render_fn(glfwGetTime(), this);

        glFlush();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return true;
}