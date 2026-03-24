#pragma once

#include "event.h"

namespace engine
{
	class API key_event : public event
	{
	public:
		inline int get_key_code() const { return key_code; }

		event_class_category(event_category_keyboard, event_category_input);
	protected:
		key_event(int key_code) : key_code(key_code) {}

		int key_code;
	};

	class API key_pressed_event : public key_event
	{
	public:
		key_pressed_event(int key_code, int repeat_count) : key_event(key_code) {}

		inline int get_reapeat_count() const { return repeat_count; }

		std::string to_string() const override
		{
			std::stringstream ss;
			ss << "KEY PRESSED EVENT: " << key_code << " (" << repeat_count << " repeats)";
			return ss.str();
		}

		static event_type get_static_type() { return event_type::key_pressed; }
		virtual event_type get_event_type() const override { return get_static_type(); }
		virtual const char* get_name() const override { return "key_pressed"; }

		event_class_type(key_pressed)
	private:
		int repeat_count;
	};

	class API key_released_event : public key_event
	{
	public:
		key_released_event(int key_code) : key_event(key_code) {}

		std::string to_string() const override
		{
			std::stringstream ss;
			ss << "KEY RELEASED EVENT: " << key_code;
			return ss.str();
		}

		static event_type get_static_type() { return event_type::key_pressed; }
		virtual event_type get_event_type() const override { return get_static_type(); }
		virtual const char* get_name() const override { return "key_released"; }

		event_class_type(key_released);
	};
}