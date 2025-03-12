#include <iostream>
#include <GLFW/glfw3.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	float angle = 0.0f;
	float rotationSpeed = 25.0f; // degrees per second

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		/* Calculate color based on the angle */
		float time = glfwGetTime();
		float angle = fmod(time * rotationSpeed, 360.0f);
		float red = (sin(angle * M_PI / 180.0f) + 1.0f) / 2.0f;
		float green = (cos(angle * M_PI / 180.0f) + 1.0f) / 2.0f;
		float blue = (sin(angle * M_PI / 90.0f) + 1.0f) / 2.0f;

		/* Set the color */
		glColor3f(red, green, blue);

		/* Apply rotation around the x-axis */
		glPushMatrix(); // Save the current matrix state
		glRotatef(angle, 1.0f, 0.0f, 0.0f);

		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f( 0.0f,  0.5f);
		glVertex2f( 0.5f, -0.5f);
		glEnd();

		glPopMatrix(); // Restore the previous matrix state

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}