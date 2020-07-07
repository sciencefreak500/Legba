#pragma once

#ifdef LEGBA_PLATFORM_WINDOWS
	#ifdef LEGBA_BUILD_DLL
		#define LEGBA_API __declspec(dllexport)
	#else
		#define LEGBA_API __declspec(dllimport)
	#endif
#else
	#error Legba Engine only supports Windows
#endif


#define BIT(x) (1 << x)