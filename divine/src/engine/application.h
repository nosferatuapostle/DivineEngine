#pragma once

#include "core.h"

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

