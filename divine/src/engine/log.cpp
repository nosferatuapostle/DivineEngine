#include "log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace engine
{
	std::shared_ptr<spdlog::logger> log::core_logger;
	std::shared_ptr<spdlog::logger> log::client_logger;

	void log::initialize()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");

		core_logger = spdlog::stdout_color_mt("CORE");
		core_logger->set_level(spdlog::level::trace);

		client_logger = spdlog::stdout_color_mt("APP");
		client_logger->set_level(spdlog::level::trace);
	}
}