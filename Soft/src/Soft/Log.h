#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"

namespace Soft {
	class SOFT_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private: 
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};


}

#define ST_CORE_ERROR(...)		::Soft::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ST_CORE_WARN(...)		::Soft::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ST_CORE_INFO(...)		::Soft::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ST_CORE_TRACE(...)		::Soft::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ST_CORE_CRITICAL(...)	::Soft::Log::GetCoreLogger()->critical(__VA_ARGS__)

#define ST_ERROR(...)			::Soft::Log::GetClientLogger()->error(__VA_ARGS__)
#define ST_WARN(...)			::Soft::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ST_INFO(...)			::Soft::Log::GetClientLogger()->info(__VA_ARGS__)
#define ST_TRACE(...)			::Soft::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ST_CRITICAL(...)		::Soft::Log::GetClientLogger()->critical(__VA_ARGS__)