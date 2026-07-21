#include "Logger.h"

#include <fstream>
#include <chrono>
#include <iomanip>
#include <ctime>

Logger::Logger(const std::string& filename)
{
    fileName = filename;
}

void Logger::info(const std::string& message)
{
    write("INFO", message);
}

void Logger::warning(const std::string& message)
{
    write("WARNING", message);
}

void Logger::error(const std::string& message)
{
    write("ERROR", message);
}

void Logger::write(const std::string& level, const std::string& message)
{
    std::ofstream file(fileName, std::ios::app);

    auto now = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

    file << std::put_time(std::localtime(&currentTime), "%Y-%m-%d %H:%M:%S")
         << " [" << level << "] "
         << message
         << std::endl;

    file.close();
}