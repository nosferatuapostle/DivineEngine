#pragma once

#include "core.h"

namespace engine
{
	class DIVINE_API application
	{
	public:
		application();
		virtual ~application();
		void run();
	};

	application* create_application();
};

