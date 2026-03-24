#pragma once

#include "event.h"

namespace engine
{
	class API mouse_moved_event : public event
	{
	public:
		mouse_moved_event(float x, float y) : x(x), y(y) {}

		inline float get_x() const { return x; }
		inline float get_y() const { return y; }

		std::string to_string() const override
		{
			std::stringstream ss;
			ss << "MOUSE MOVED EVENT: " << x << " x " << y;
			return ss.str();
		}

		event_class_type(mouse_moved);
		event_class_category(event_category_mouse | event_category_input);
	private:
		float x, y;
	};

	class API mouse_scrolled_event : public event
	{
	public:
		mouse_scrolled_event(float x_offset, float y_offset) : x_offset(x_offset), y_offset(y_offset) {}

		inline float get_x_offset() const { return x_offset; }
		inline float get_y_offset() const { return y_offset; }

		std::string to_string() const override
		{
			std::stringstream ss;
			ss << "MOUSE SCROLLED EVENT: " << x_offset << " x " << y_offset;
			return ss.str();
		}
	private:
		float x_offset, y_offset;
	};

	class API mouse_button_event : public event
	{
	public:
		inline int get_mouse_button() const { return button; }

		event_class_category(event_category_mouse | event_category_input)
	protected:
		mouse_button_event(int BUTTON) : button(BUTTON) {}

		int button;
	};

	class API mouse_button_pressed_event : public mouse_button_event
	{
	public:
		mouse_button_pressed_event(int button) : mouse_button_event(button) {}

		std::string to_string() const override
		{
			std::stringstream ss;
			ss << "MOUSE BUTTON PRESSED EVENT: " << button;
			return ss.str();
		}

		event_class_type(mouse_button_pressed);
	};

	class API mouse_button_released_event : public mouse_button_event
	{
	public:
		mouse_button_released_event(int button) : mouse_button_event(button) {}

		std::string to_string() const override
		{
			std::stringstream ss;
			ss << "MOUSE BUTTON RELEASED EVENT: " << button;
			return ss.str();
		}

		event_class_type(mouse_button_released);
	};
}