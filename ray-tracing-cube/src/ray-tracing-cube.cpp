#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GLUtils.hpp>

int main() {
	GLFWwindow *win = initOpenGL(1920, 1080, "Ray Tracer");
	squareViewport(win);
	glfwSetWindowSizeCallback(win, squareViewportGLFWCallback);

	GLuint vao, vbo;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	// Cube centered at middle of screen.
	float cube[] = {
	// Front Face - 1
			-.5, .5, 0, 1, 0, 0, 				//v1
			.5, .5, 0, 0, 1, 0, 				//v2
			-.5, -.5, 0, 0, 0, 1, 				//v3
			// Front Face - 2
			.5, .5, 0, 0, 1, 0,					//v2
			-.5, -.5, 0, 0, 0, 1,				//v3
			.5, -.5, 0, 1, 1, 0,				//v4

			// Back Face - 1
			-.4, .6, -.9, 0, 1, 1,				//v5
			.6, .4, -.9, 1, 0, 1,				//v6
			-.4, -.4, -.9, 0, 0, 0,				//v7
			// Back Face - 2
			.6, .4, -.9, 1, 0, 1,				//v6
			-.4, -.4, -.9, 0, 0, 0,				//v7
			.6, -.4, -.9, 1, 1, 1,				//v8

			// Left Side - 1
			-.5, .5, 0, 1, 0, 0,				//v1
			-.4, .6, -.9, 0, 1, 1,				//v5
			-.5, -.5, 0, 0, 0, 1,				//v3
			// Left Side - 2
			-.4, .6, -.9, 0, 1, 1,				//v5
			-.5, -.5, 0, 0, 0, 1,				//v3
			-.4, -.4, -.9, 0, 0, 0,				//v7

			// Top Side - 1
			-.5, .5, 0, 1, 0, 0,				//v1
			-.4, .6, -.9, 0, 1, 1,				//v5
			.6, .4, -.9, 1, 0, 1,				//v6
			// Top Side - 2
			-.4, .6, -.9, 0, 1, 1,				//v5
			.6, .4, -.9, 1, 0, 1,				//v6
			.5, .5, 0, 0, 1, 0,					//v2

			// Right Side - 1
			.5, .5, 0, 0, 1, 0,					//v2
			.6, .4, -.9, 1, 0, 1,				//v6
			.5, -.5, 0, 1, 1, 0,				//v4
			// Right Side - 2
			.6, .4, -.9, 1, 0, 1,				//v6
			.5, -.5, 0, 1, 1, 0,				//v4
			.6, -.4, -.9, 1, 1, 1,				//v8

			// Bottom Side - 1
			-.5, -.5, 0, 0, 0, 1,				//v3
			.5, -.5, 0, 1, 1, 0,				//v4
			-.4, -.4, -.9, 0, 0, 0,				//v7
			// Bottom Side - 2
			.5, -.5, 0, 1, 1, 0,				//v4
			-.4, -.4, -.9, 0, 0, 0,				//v7
			.6, -.4, -.9, 1, 1, 1,				//v8
			};

	glBufferData(GL_ARRAY_BUFFER, sizeof cube, cube, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(float) * 6, 0);
	glVertexAttribPointer(1, 3, GL_FLOAT, false, sizeof(float) * 6,
			(void*) (sizeof(float) * 3));
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	auto prog =
			createShaderProgram(
					R"(#version 330 core
		layout(location = 0) in vec3 pos;
		layout(location = 1) in vec3 color;

		out vec3 colorFromVertShader;

		void main() {
			gl_Position = vec4(pos, 1);
			colorFromVertShader = color;
		}
		)",
					R"(#version 330 core
		in vec3 colorFromVertShader;
		out vec4 colorFromFragShader;

		void main() {
			colorFromFragShader = vec4(colorFromVertShader, 1);
		})");
	glUseProgram(prog);

	while (!glfwWindowShouldClose(win)) {
		glfwPollEvents();
		glClear(GL_COLOR_BUFFER_BIT);

		glBindVertexArray(vao);
		glDrawArrays(GL_TRIANGLES, 0, 36);

		glfwSwapBuffers(win);
	}

	return 0;
}
