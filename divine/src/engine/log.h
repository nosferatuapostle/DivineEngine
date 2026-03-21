#pragma once

#include <memory>

#include "core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace engine
{
	class API log
	{
	public:
		static void initialize();
		inline static std::shared_ptr<spdlog::logger>& get_core_logger() { return core_logger; }
		inline static std::shared_ptr<spdlog::logger>& get_client_logger() { return client_logger; }
	private:
		static std::shared_ptr<spdlog::logger> core_logger;
		static std::shared_ptr<spdlog::logger> client_logger;
	};
}

#define CORE_TRACE(...)    ::engine::log::get_core_logger()->trace(__VA_ARGS__)
#define CORE_INFO(...)     ::engine::log::get_core_logger()->info(__VA_ARGS__)
#define CORE_WARN(...)     ::engine::log::get_core_logger()->warn(__VA_ARGS__)
#define CORE_ERROR(...)    ::engine::log::get_core_logger()->error(__VA_ARGS__)
#define CORE_CRITICAL(...) ::engine::log::get_core_logger()->critical(__VA_ARGS__)

#define APP_TRACE(...)     ::engine::log::get_client_logger()->trace(__VA_ARGS__)
#define APP_INFO(...)      ::engine::log::get_client_logger()->info(__VA_ARGS__)
#define APP_WARN(...)      ::engine::log::get_client_logger()->warn(__VA_ARGS__)
#define APP_ERROR(...)     ::engine::log::get_client_logger()->error(__VA_ARGS__)
#define APP_CRITICAL(...)  ::engine::log::get_client_logger()->critical(__VA_ARGS__)