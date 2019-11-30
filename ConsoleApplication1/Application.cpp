#include "Application.h"

Application::Application(GLFWwindow * window)
{
	m_window = window;
}

Application::~Application()
{
}

void Application::Start()
{
}

void Application::Update(double elapsedTime)
{
}


void Application::Keys(GLFWwindow * window)
{
	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		//
	}
}

void Application::MouseButtons(GLFWwindow* window, double elapsedTime)
{
	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
	{
		//
	}
}

void Application::MousePosition(GLFWwindow * window)
{
	glfwGetCursorPos(window, &xpos, &ypos);
}


void Application::Draw()
{
	glClearColor(0.2f, 0.2f, 0.2f, 0.5f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Application::SetWindowSize(int width, int height)
{
	WINDOW_WIDTH = width;
	WINDOW_HEIGHT = height;
}

void Application::SetWindow(GLFWwindow * win)
{
	m_window = win;
}