#ifndef LOGGER_H
#define LOGGER_H

#include <string>

class Logger
{
public:
    Logger(const std::string& filename);

    void info(const std::string& message);
    void warning(const std::string& message);
    void error(const std::string& message);

private:
    std::string fileName;

    void write(const std::string& level, const std::string& message);
};

#endif