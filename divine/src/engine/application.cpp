#include "application.h"
#include "events/application_event.h"
#include "log.h"

namespace engine
{
	application::application()
	{

	}

	application::~application()
	{

	}

	void application::start()
	{
		window_resize_event e(1280, 720);
		app_trace(e.to_string());

		while (true)
		{
			//app_update_event();
		};
	}
}