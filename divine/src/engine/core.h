#pragma once

#ifdef PLATFORM_WINDOWS
	#ifdef BUILD_DLL
		#define DIVINE_API _declspec(dllexport)
	#else
		#define DIVINE_API _declspec(dllimport)
	#endif
#else
	#error Divine Engine only support Windows platform!
#endif