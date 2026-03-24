#pragma once

#include "core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"


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

#define core_trace    engine::log::get_core_logger()->trace
#define core_info     engine::log::get_core_logger()->info
#define core_warn     engine::log::get_core_logger()->warn
#define core_error    engine::log::get_core_logger()->error
#define core_critical engine::log::get_core_logger()->critical

#define app_trace     engine::log::get_client_logger()->trace
#define app_info      engine::log::get_client_logger()->info
#define app_warn      engine::log::get_client_logger()->warn
#define app_error     engine::log::get_client_logger()->error
#define app_critical  engine::log::get_client_logger()->critical