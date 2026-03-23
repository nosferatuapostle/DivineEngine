#pragma once

#include "core.h"

#ifdef PLATFORM_WINDOWS

extern engine::application* engine::create_application();

int main(int argc, char** argv)
{
	engine::log::initialize();
	core_warn("Initialized Log!");
	app_info("Hello!");

	var app = engine::create_application();
	app->start();
	delete app;
}

#endif