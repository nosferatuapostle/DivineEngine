#include "pch.h"
#include "application.h"

#include "events/application_event.h"
#include "log.h"

namespace engine
{
	application::application()
	{
		window = std::unique_ptr<engine::window>(window::create());
	}

	application::~application() {}

	void application::start()
	{
		while (is_running)
		{
			window->on_update();
		}
	}
}