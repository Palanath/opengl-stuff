#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GLUtils.hpp>
#include <pala/opengl/tests/multiple-vaos/Model.h>

int main() {
	GLFWwindow *win = initOpenGL(1200, 800, "Perspective Transforms");
	glfwSetWindowSizeCallback(win, squareViewportGLFWCallback);
	squareViewport(win);

	pala::opengl::tests::multiple_vaos::Model cube;


	while (!glfwWindowShouldClose(win)) {
		glfwPollEvents();
		glClear(GL_COLOR_BUFFER_BIT);


		glfwSwapBuffers(win);
	}
}
