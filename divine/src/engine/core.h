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

#ifdef ENABLE_ASSERTS
#define core_assert(x, ...)
{
	if (!x)
	{
		core_error("ASSERTION FAILED {0}", __VA_ARGS__);
		__debugbreak();
	}
}

#define app_assert(x, ...)
{
	if (!x)
	{
		core_error("ASSERTION FAILED {0}", __VA_ARGS__);
		__debugbreak();
	}
}
#else
#define core_assert(x, ...)
#define app_assert(x, ...)
#endif

#define var auto
#define bit(x) (1 << x)