#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GLUtils.hpp>
#include <pala/opengl/tests/multiple-vaos/Model.h>

int main() {
	GLFWwindow *win = initOpenGL(1200, 800, "Instanced Rendering");
	squareViewport(win);
	glfwSetWindowSizeCallback(win, squareViewportGLFWCallback);

	/*
	 * Model
	 */
	pala::opengl::tests::multiple_vaos::Model triangle;
	float triangleData[] = {
	// Triangle Vertices
			-.5, .5,	// Top
			.5, -.5,	// Right
			-.5, -.5 	// Left
			};
	triangle.specifyAttribute(0,
			triangle.addData(triangleData, sizeof triangleData), 2, 2, 0);

	/*
	 * Instancing Configuration
	 */
	// Specify a set of "shifts" for each of the triangle instances.
	float instShifts[] = {
	// Shifts
			.2, -.4,	// Triangle 1
			-.3, .7,	// 2
			.06, .1		// 3
			};

	const int instances = sizeof instShifts / sizeof(float) / 2;
	std::cout << "There are " << instances << " triangles being rendered."
			<< std::endl;

	/*
	 * Shader
	 */
	auto prog;
	{
		auto strval = std::to_string(instances);
		prog =
				createShaderProgram(
						(std::string(
								R"(#version 330 core
in vec2 pos;

flat out int instid;
out vec2 position;

uniform int numInstances;
uniform vec2 instanceShifts[)")
								+ strval
								+ R"(];

void main() {
	gl_Position = vec4(position = pos + instanceShifts[gl_InstanceID], 0, 1);
	instid = gl_InstanceID;
})").c_str(),
						(std::string(
								R"(#version 330 core
in vec2 position;
flat in int instid;
uniform int numInstances;
uniform vec2 instanceShifts[)")
								+ strval
								+ R"(];

out vec4 color;

void main() {
	color = vec4(1, 1, 0, 1);
})").c_str());
	}
	glUseProgram(prog);

	glUniform1i(glGetUniformLocation(prog, "numInstances"), instances);
	auto instanceShiftsUniformLoc = glGetUniformLocation(prog,
			"instanceShifts");

	while (!glfwWindowShouldClose(win)) {
		glfwPollEvents();
		glClear(GL_COLOR_BUFFER_BIT);

		glUniform2fv(instanceShiftsUniformLoc, instances, instShifts);

		triangle.draw(3, 0, instances);

		glfwSwapBuffers(win);
	}
}
