#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GLUtils.hpp>

int main() {
	GLFWwindow *win = initOpenGL(1200, 800, "Instanced Rendering");
	squareViewport(win);
	glfwSetWindowSizeCallback(win, squareViewportGLFWCallback);

	while (!glfwWindowShouldClose(win)) {
		glfwPollEvents();
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(win);
	}
}
