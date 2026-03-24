#pragma once

#include "core.h"
#include "events/event.h"
#include "window.h"

namespace engine
{
	class API application
	{
	public:
		application();
		virtual ~application();
		void start();
	private:
		std::unique_ptr<window> window;
		bool is_running = true;
	};

	application* create_application();
}

