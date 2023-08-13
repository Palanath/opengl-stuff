#include <GLUtils.hpp>

int main() {
	GLFWwindow *win = initOpenGL(1200, 800, "Perspective Transforms");
	glfwSetWindowSizeCallback(win, squareViewportGLFWCallback);
	squareViewport(win);

	while (!glfwWindowShouldClose(win)) {
		glfwPollEvents();
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(win);
	}
}
