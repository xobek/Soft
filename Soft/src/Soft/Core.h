#pragma once


#ifdef ST_PLATFORM_WINDOWS 
	#ifdef ST_BUILD_DLL
		#define SOFT_API __declspec(dllexport)
	#else 
		#define SOFT_API __declspec(dllimport)
	#endif
#endif