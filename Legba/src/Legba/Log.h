#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"


namespace Legba {
	class LEGBA_API Log
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

// Core logs
#define LEGBA_CORE_FATAL(...) ::Legba::Log::GetCoreLogger()->fatal(__VA_ARGS__)
#define LEGBA_CORE_ERROR(...) ::Legba::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LEGBA_CORE_WARN(...)  ::Legba::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LEGBA_CORE_INFO(...)  ::Legba::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LEGBA_CORE_TRACE(...) ::Legba::Log::GetCoreLogger()->trace(__VA_ARGS__)

// Client logs
#define LEGBA_FATAL(...) ::Legba::Log::GetClientLogger()->fatal(__VA_ARGS__)
#define LEGBA_ERROR(...) ::Legba::Log::GetClientLogger()->error(__VA_ARGS__)
#define LEGBA_WARN(...)  ::Legba::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LEGBA_INFO(...)  ::Legba::Log::GetClientLogger()->info(__VA_ARGS__)
#define LEGBA_TRACE(...) ::Legba::Log::GetClientLogger()->trace(__VA_ARGS__)