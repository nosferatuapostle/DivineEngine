#include "pch.h"
#include "windows_window.h"

namespace engine
{
	static bool static_glfw_initialize = false;

	window* window::create(const window_props& props)
	{
		return new windows_window(props);
	}

	windows_window::windows_window(const window_props& props) { initialize(props); }

	windows_window::~windows_window() {}

	void windows_window::initialize(const window_props& props)
	{
		data.title = props.title;
		data.width = props.width;
		data.height = props.height;

		core_info("CREATING WINDOW {0}, ({1} x {2})", props.title, props.width, props.height);

		if (!static_glfw_initialize)
		{
			int success = glfw_init();
			core_assert(success, "COULD NOT INITIALIZE GLFW!");

			static_glfw_initialize = true;
		}

		window = glfw_create_window((int)props.width, (int)props.height, data.title.c_str(), nullptr, nullptr);
		glfw_make_context_current(window);
		glfw_set_window_user_pointer(window, &data);

		set_vsync(true);
	}

	void windows_window::shutdown()
	{
		glfw_destroy_window(window);
	}

	void windows_window::on_update()
	{
		glfw_poll_events();
		glfw_swap_buffers(window);
	}

	void windows_window::set_vsync(bool enabled)
	{
		if (enabled)
		{
			glfw_swap_interval(1);
		}
		else
		{
			glfw_swap_interval(0);
		}

		data.vsync = enabled;
	}

	bool windows_window::is_vsync() const
	{
		return data.vsync;
	}
}