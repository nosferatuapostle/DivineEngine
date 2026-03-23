#pragma once

#include "event.h"

#include <sstream>

namespace engine
{
	class API window_resize_event : public event
	{
	public:
		window_resize_event(unsigned int WIDTH, unsigned int HEIGHT) : width(WIDTH), height(HEIGHT) {}

		inline unsigned int get_width() { return width; }
		inline unsigned int get_height() { return height; }

		std::string to_string() const override
		{
			std::stringstream ss;
			ss << "WINDOW RESIZE EVENT: " << width << " x " << height;
			return ss.str();
		}

		event_class_type(window_resize);
		event_class_category(event_category_application);
	private:
		unsigned int width, height;
	};

	class API window_close_event : public event
	{
	public:
		window_close_event() {}

		event_class_type(window_close);
		event_class_category(event_category_application);
	};

	class API app_tick_event : public event
	{
	public:
		app_tick_event() {}

		event_class_type(app_tick);
		event_class_category(event_category_application);
	};

	class API app_update_event : public event
	{
	public:
		app_update_event() {}

		event_class_type(app_update);
		event_class_category(event_category_application);
	};

	class API app_render_event : public event
	{
	public:
		app_render_event() {}

		event_class_type(app_render);
		event_class_category(event_category_application);
	};
}