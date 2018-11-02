#include <GLFW/glfw3.h>
#include <iostream>

int rotate_y = 0;
int rotate_x = 0;

void keyboard_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);

	if (key == GLFW_KEY_UP && action == GLFW_PRESS)
		rotate_x += 5;

	if (key == GLFW_KEY_DOWN && action == GLFW_PRESS)
		rotate_x -= 5;

	if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS)
		rotate_y -= 5;

	if (key == GLFW_KEY_LEFT && action == GLFW_PRESS)
		rotate_y += 5;

}

int main(int argc, char const *argv[]){
	// glfw: initialize and configure
	// ------------------------------
	glfwInit();

	// glfw window creation
	// --------------------
	GLFWwindow* window = glfwCreateWindow(800, 600, "Rotating Cube", NULL, NULL);
	if (window == NULL){
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	glEnable(GL_DEPTH_TEST);

	// render loop
	// -----------
	while (!glfwWindowShouldClose(window)){
		glfwSetKeyCallback(window, keyboard_callback);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glLoadIdentity();

		glRotatef((float)rotate_x, 1.0, 0.0, 0.0);
		glRotatef((float)rotate_y, 0.0, 1.0, 0.0);

		glBegin(GL_POLYGON); // FRONT
		
		glColor3d(0.99, 0.82, 0.63);
		glVertex3f(0.5, -0.5, -0.5);
		glVertex3f(0.5, 0.5, -0.5);
		glVertex3f(-0.5, 0.5, -0.5);
		glVertex3f(-0.5, -0.5, -0.5);
		glEnd();

		glBegin(GL_POLYGON); // BACK
		glColor3d(0.69, 0.71, 0.58);
		glVertex3f(0.5, -0.5, 0.5);
		glVertex3f(0.5, 0.5, 0.5);
		glVertex3f(-0.5, 0.5, 0.5);
		glVertex3f(-0.5, -0.5, 0.5);
		glEnd();

		glBegin(GL_POLYGON); // RIGHT
		glColor3d(0.33, 0.57, 0.49);
		glVertex3f(0.5, -0.5, -0.5);
		glVertex3f(0.5, 0.5, -0.5);
		glVertex3f(0.5, 0.5, 0.5);
		glVertex3f(0.5, -0.5, 0.5);
		glEnd();

		glBegin(GL_POLYGON); // LEFT
		glColor3d(0.39, 0.33, 0.36);
		glVertex3f(-0.5, -0.5, 0.5);
		glVertex3f(-0.5, 0.5, 0.5);
		glVertex3f(-0.5, 0.5, -0.5);
		glVertex3f(-0.5, -0.5, -0.5);
		glEnd();

		glBegin(GL_POLYGON); // TOP
		glColor3d(0.67, 0.67, 0.67);
		glVertex3f(0.5, 0.5, 0.5);
		glVertex3f(0.5, 0.5, -0.5);
		glVertex3f(-0.5, 0.5, -0.5);
		glVertex3f(-0.5, 0.5, 0.5);
		glEnd();

		glBegin(GL_POLYGON); // BOTTOM
		glColor3d(0.2, 0.19, 0.19);
		glVertex3f(0.5, -0.5, -0.5);
		glVertex3f(0.5, -0.5, 0.5);
		glVertex3f(-0.5, -0.5, 0.5);
		glVertex3f(-0.5, -0.5, -0.5);
		glEnd();

		// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
	    // -------------------------------------------------------------------------------
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	// glfw: terminate, clearing all previously allocated GLFW resources.
	// ------------------------------------------------------------------
	glfwTerminate();
	return 0;
}