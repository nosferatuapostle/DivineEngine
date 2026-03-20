#pragma once

#ifdef PLATFORM_WINDOWS

extern engine::application* engine::create_application();

int main(int argc, char** argv)
{
	printf("Divine Engine\n");
	auto app = engine::create_application();
	app->run();
	delete app;
}

#endif