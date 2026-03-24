#pragma once

#include "pch.h"

#include "core.h"
#include "events/event.h"

namespace engine
{
	struct window_props
	{
		std::string title;
		unsigned int width, height;

		window_props(const std::string& p_title = "DIVINE ENGINE", unsigned int p_width = 1280, unsigned int p_height = 720) : title(p_title), width(p_width), height(p_height) {}
	};

	class API window
	{
	public:
		using event_callback_fn = std::function<void(event&)>;

		virtual ~window() {}

		virtual void on_update() = 0;

		virtual unsigned int get_width() const = 0;
		virtual unsigned int get_height() const = 0;

		virtual void set_event_callback(const event_callback_fn& p_callback) = 0;
		virtual void set_vsync(bool enabled) = 0;
		virtual bool is_vsync() const = 0;

		static window* create(const window_props& p_props = window_props());
	};
}