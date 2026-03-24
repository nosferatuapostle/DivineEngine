#pragma once

#include "engine/window.h"

#include "../glfw.h"

namespace engine
{
	class windows_window : public window
	{
	public:
		windows_window(const window_props& props);
		virtual ~windows_window();

		void on_update() override;

		inline unsigned int get_width() const override { return data.width; }
		inline unsigned int get_height() const override { return data.height; }

		inline void set_event_callback(const event_callback_fn& callback) override { data.event_callback = callback; }
		void set_vsync(bool enabled) override;
		bool is_vsync() const override;
	private:
		virtual void initialize(const window_props& props);
		virtual void shutdown();

		glfw_window* window;

		struct window_data
		{
			std::string title;
			unsigned int width = 0, height = 0;
			bool vsync = false;

			event_callback_fn event_callback;
		};

		window_data data;
	};
}