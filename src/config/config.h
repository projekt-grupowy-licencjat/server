#ifndef SERVER_CONFIG_H
#define SERVER_CONFIG_H

#include <string>
#include <map>

namespace config {

    class Config {
    public:
        explicit Config(std::string config_path);
        void parse();
        std::map<std::string, std::string> getAllProperties();
        std::string getProperty(std::string key);
    private:
        std::string config_path;
        std::map<std::string, std::string> properties;
    };

} // config

#endif //SERVER_CONFIG_H
