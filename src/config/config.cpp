#include "config.h"

#include <utility>

namespace config {
    Config::Config(std::string config_path) : config_path(std::move(config_path)) {

    }
} // config