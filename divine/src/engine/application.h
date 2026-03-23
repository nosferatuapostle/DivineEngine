#pragma once

#include "core.h"
#include "events/event.h"

namespace engine
{
	class API application
	{
	public:
		application();
		virtual ~application();
		void start();
	};

	application* create_application();
}

