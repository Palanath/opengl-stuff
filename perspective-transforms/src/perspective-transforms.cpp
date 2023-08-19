#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GLUtils.hpp>
#include <pala/opengl/tests/multiple-vaos/Model.h>

int main() {
	GLFWwindow *win = initOpenGL(1200, 800, "Perspective Transforms");
	glfwSetWindowSizeCallback(win, squareViewportGLFWCallback);
	squareViewport(win);

	pala::opengl::tests::multiple_vaos::Model cube;
	float data[] = {
	// Front Face - 1
			-.5, .5, 0, 1, 0, 0, 				//v1
			.5, .5, 0, 0, 1, 0, 				//v2
			-.5, -.5, 0, 0, 0, 1, 				//v3
			// Front Face - 2
			.5, .5, 0, 0, 1, 0,					//v2
			-.5, -.5, 0, 0, 0, 1,				//v3
			.5, -.5, 0, 1, 1, 0,				//v4

			// Back Face - 1
			-.5, .5, -1, 1, 0, 0,				//v5
			.5, .5, -1, 0, 1, 0,				//v6
			-.5, -.5, -1, 0, 0, 1,				//v7
			// Back Face - 2
			.5, .5, -1, 0, 1, 0,				//v6
			-.5, -.5, -1, 0, 0, 1,				//v7
			.5, -.5, -1, 1, 1, 0,				//v8

			// Left Side - 1
			-.5, .5, 0, 1, 0, 0,				//v1
			-.5, .5, -1, 1, 0, 0,				//v5
			-.5, -.5, 0, 0, 0, 1,				//v3
			// Left Side - 2
			-.5, .5, -1, 1, 0, 0,				//v5
			-.5, -.5, 0, 0, 0, 1,				//v3
			-.5, -.5, -1, 0, 0, 1,				//v7

			// Top Side - 1
			-.5, .5, 0, 1, 0, 0,				//v1
			-.5, .5, -1, 1, 0, 0,				//v5
			.5, .5, -1, 0, 1, 0,				//v6
			// Top Side - 2
			-.5, .5, -1, 1, 0, 0,				//v5
			.5, .5, -1, 0, 1, 0,				//v6
			.5, .5, 0, 0, 1, 0,					//v2

			// Right Side - 1
			.5, .5, 0, 0, 1, 0,					//v2
			.5, .5, -1, 0, 1, 0,				//v6
			.5, -.5, 0, 1, 1, 0,				//v4
			// Right Side - 2
			.5, .5, -1, 0, 1, 0,				//v6
			.5, -.5, 0, 1, 1, 0,				//v4
			.5, -.5, -1, 1, 1, 0,				//v8

			// Bottom Side - 1
			-.5, -.5, 0, 0, 0, 1,				//v3
			.5, -.5, 0, 1, 1, 0,				//v4
			-.5, -.5, -1, 0, 0, 1,				//v7
			// Bottom Side - 2
			.5, -.5, 0, 1, 1, 0,				//v4
			-.5, -.5, -1, 0, 0, 1,				//v7
			.5, -.5, -1, 1, 1, 0,				//v8
			};
	cube.addData(data, sizeof data);
	cube.specifyAttribute(0, 0, 3, 6, 0);// Position
	cube.specifyAttribute(1, 0, 3, 6, 3);// Color

	auto prog = createShaderProgram(R"(#version 330 core

in vec3 pos;
in vec3 col;

out vec3 color;

uniform float xShift;

void main() {
	color = col;
	gl_Position = vec4(pos, 1);
})", R"(#version 330 core

in vec3 color;
out vec3 outcol;

void main() {
	outcol = color;
})");
	glUseProgram(prog);



	while (!glfwWindowShouldClose(win)) {
		glfwPollEvents();
		glClear(GL_COLOR_BUFFER_BIT);

		cube.draw(36);

		glfwSwapBuffers(win);
	}
}
