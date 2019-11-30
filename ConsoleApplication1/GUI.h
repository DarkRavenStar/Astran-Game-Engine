#pragma once
#include "AllHeader.h"
#define NK_INCLUDE_FIXED_TYPES
#define NK_INCLUDE_STANDARD_IO
#define NK_INCLUDE_STANDARD_VARARGS
#define NK_INCLUDE_DEFAULT_ALLOCATOR
#define NK_INCLUDE_VERTEX_BUFFER_OUTPUT
#define NK_INCLUDE_FONT_BAKING
#define NK_INCLUDE_DEFAULT_FONT
#define NK_IMPLEMENTATION
#define NK_GLFW_GL2_IMPLEMENTATION
#define NK_KEYSTATE_BASED_INPUT
#include "nuklear.h"
#include "nuklear_glfw_gl2.h"
#include "GUIStyle.h"

class GUI
{
protected:
	GLFWwindow* window;
	struct nk_context *ctx;
	int m_width;
	int m_height;

public:
	GUI() {}
	GUI(GLFWwindow* window, int width, int height)
	{
		/* GUI */
		ctx = nk_glfw3_init(window, NK_GLFW3_INSTALL_CALLBACKS);
		{struct nk_font_atlas *atlas;
		nk_glfw3_font_stash_begin(&atlas);
		nk_glfw3_font_stash_end(); }
		m_width = width;
		m_height = height;
	}
	~GUI()
	{
		nk_glfw3_shutdown();
	}

	void SetGUIStyle(Theme theme)
	{
		set_style(ctx, theme);
	}

	void SetWindowSize(int width, int height)
	{
		m_width = width;
		m_height = height;
	}
	
	void DrawGameGUI()
	{
		nk_glfw3_new_frame();
		/* GUI */
		if (nk_begin(ctx, "", nk_rect(0, 0, m_width, m_height), NK_WINDOW_NO_SCROLLBAR))
		{
			
		}
		nk_end(ctx);

		nk_glfw3_render(NK_ANTI_ALIASING_ON);
	}

private:
	static std::string NameAndNumber(int num)
	{
		static std::string name = "Put the string of your choosing";
		std::stringstream sstm;
		sstm << name << num;
		return sstm.str();
	}

	static std::string TextCombiner(std::string text1, int num, std::string text2)
	{
		std::stringstream sstm;
		sstm << text1 << num << text2;
		return sstm.str();
	}
};
