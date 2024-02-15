#pragma once

#ifdef ST_PLATFORM_WINDOWS 
	#ifdef ST_BUILD_DLL
		#define SOFT_API __declspec(dllexport)
	#else 
		#define SOFT_API __declspec(dllimport)
	#endif
#endif

#ifdef ST_ENABLE_ASSERTS 
	#define ST_ASSERT(x, ...) { if(!(x)) { ST_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define ST_CORE_ASSERT(x, ...) { if(!(x)) { ST_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define ST_ASSERT(x, ...)
	#define ST_CORE_ASSERT(x, ...)
#endif

#define BIT(X) (1 << X)