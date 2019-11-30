#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "AllHeader.h"
#include "Application.h"
#include "Vector3.h"
#include "bitmap.h"
#include "Color.h"
#include "ColorDeclaration.h"
#include "Affector.h"
#include "AffectorDeclaration.h"
#include "GUI.h"

const int RESOLUTION_X = 800;
const int RESOLUTION_Y = 600;
bool ShowConsoleWindow;
float scrollX = 0.0f, scrollY = 0.0f;
float zoom = 1.0f;

void Stealth()
{
	HWND Stealth;
	AllocConsole();
	Stealth = FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(Stealth, 0);
}


void OrthographicView(int width, int height)
{
	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix
	glOrtho(scrollX, scrollX + width / zoom, scrollY + height / zoom, scrollY, -1, 1);
	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();
}

void onWindowResized(GLFWwindow* window, int width, int height)
{
	glViewport(0.0f, 0.0f, width, height);				// Reset The Current Viewport
	OrthographicView(width, height);
}


void WindowKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
}

void MouseScrollCallback(GLFWwindow* window, double xoffset, double yoffset)
{
}

int main(void)
{
	//Stealth();
	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_HIDE);
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(RESOLUTION_X, RESOLUTION_Y, "Application Template using Astran Game Engine by Teena 0118856", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetWindowSizeCallback(window, onWindowResized);
	onWindowResized(window, RESOLUTION_X, RESOLUTION_Y);
	glfwSetKeyCallback(window, WindowKeyCallback);
	glfwSetInputMode(window, GLFW_STICKY_MOUSE_BUTTONS, 1);
	glfwSwapInterval(1); //enable/disable vsync

	Application app(window);
	app.Start();

	GUI gui(window, RESOLUTION_X, RESOLUTION_Y);


	srand(time(NULL));
	double prevTime = glfwGetTime();

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		if (glfwGetKey(window, GLFW_KEY_ESCAPE))
		{
			break;
		}

		if (ShowConsoleWindow == true)
		{
			HWND hWnd = GetConsoleWindow();
			ShowWindow(hWnd, SW_SHOW);
		}
		else if (ShowConsoleWindow == false)
		{
			HWND hWnd = GetConsoleWindow();
			ShowWindow(hWnd, SW_HIDE);
		}

		double currentTime = glfwGetTime();
		double elapsedTime = currentTime - prevTime;

		app.Update(elapsedTime);
		app.Draw();
		gui.DrawGameGUI();

		/* Swap front and back buffers */
		glfwSwapBuffers(window);
		/* Poll for and process events */
		glfwPollEvents();
		prevTime = currentTime;
	}
	glfwTerminate();
	return 0;
}