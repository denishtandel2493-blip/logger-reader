#include <iostream>
#include <thread>
#include <chrono>

#include "Logger.h"

int main()
{
    Logger logger("logs/application.log");

    std::cout << "===== Logger Started =====" << std::endl;

    logger.info("Application Started");

    for (int i = 1; i <= 10; i++)
    {
        std::string message = "Processing Request " + std::to_string(i);

        logger.info(message);

        std::cout << message << std::endl;

        std::this_thread::sleep_for(std::chrono::seconds(2));
    }

    logger.warning("Application is shutting down");

    logger.info("Application Stopped");

    std::cout << "===== Logger Finished =====" << std::endl;

    return 0;
}