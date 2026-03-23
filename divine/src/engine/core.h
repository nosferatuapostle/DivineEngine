#pragma once

#ifdef PLATFORM_WINDOWS
	#ifdef BUILD_DLL
		#define API _declspec(dllexport)
	#else
		#define API _declspec(dllimport)
	#endif
#else
 #error Divine Engine only support Windows platform!
#endif

#define var auto
#define bit(x) (1 << x)