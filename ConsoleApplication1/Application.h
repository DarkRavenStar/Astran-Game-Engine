#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "AllHeader.h"
#include "GLFW/glfw3.h"


class Application
{
protected:
	GLFWwindow* m_window;
	double xpos, ypos;
public:
	int WINDOW_WIDTH;
	int WINDOW_HEIGHT;

    Application(GLFWwindow* window);
    virtual ~Application();

	virtual void Start();
	void Update(double elapsedTime);
	void Keys(GLFWwindow* window);
	void MouseButtons(GLFWwindow* window, double elapsedTime);
	void MousePosition(GLFWwindow* window);

    virtual void Draw();

	void SetWindowSize(int width, int height);
	void SetWindow(GLFWwindow* win);
};


#endif // APPLICATION_H_