#pragma once

#include "variables.h"

#ifdef PLATFORM_WINDOWS

extern engine::application* engine::create_application();

int main(int argc, char** argv)
{
	engine::log::initialize();
	CORE_WARN("Initialized Log!");
	int a = 5;
	APP_INFO("HELLO! VAR={0}", a);

	var app = engine::create_application();
	app->start();
	delete app;
}

#endif