#ifndef APP_CONFIG_HPP
#define APP_CONFIG_HPP

namespace Config {
	struct AppCfg_t;
}

struct AppConfig {
	static void populateConfiguration(Config::AppCfg_t& cfg);
};

#endif