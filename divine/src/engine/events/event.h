#pragma once

#include "../core.h"

#include <string>
#include <functional>

namespace engine
{
	enum class event_type
	{
		none = 0,
		window_close, window_resize, window_focus, window_lost_focus, window_moved,
		app_tick, app_update, app_render,
		key_pressed, key_released,
		mouse_button_pressed, mouse_button_released, mouse_moved, mouse_scrolled
	};

	enum event_category
	{
		none = 0,
		event_category_application  = bit(0),
		event_category_input        = bit(1),
		event_category_keyboard     = bit(2),
		event_category_mouse        = bit(3),
		event_category_mouse_button = bit(4)
	};

	#define event_class_type(type) static event_type get_static_type() { return event_type::type; }\
							   virtual event_type get_event_type() const override { return get_static_type(); }\
							   virtual const char* get_name() const override { return #type; }

	#define event_class_category(category) virtual int get_category_flags() const override { return category; }

	class API event
	{
		friend class event_dispatcher;
	public:
		virtual event_type get_event_type() const = 0;
		virtual const char* get_name() const = 0;
		virtual int get_category_flags() const = 0;
		virtual std::string to_string() const { return get_name(); }

		inline bool is_in_category(event_category category)
		{
			return get_category_flags() & category;
		}
	protected:
		bool handled = false;
	};

	class event_dispatcher
	{
		template<typename T>
		using eventfn = std::function<bool(T&)>;
	public:
		event_dispatcher(event& EVENT) : event(EVENT) {}

		template<typename T>
		bool dispatcher(eventfn<T> func)
		{
			if (event.get_event_type() == T::get_static_type())
			{
				event.handled = func(*(T*)&event);
				return true;
			}

			return false;
		}
	private:
		event& event;
	};

	inline std::ostream& operator<<(std::ostream& os, const event& e)
	{
		return os << e.to_string();
	}
}