#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>

int main()
{
    const std::string logFile = "logs/application.log";

    std::ifstream file(logFile);

    if (!file.is_open())
    {
        std::cerr << "Unable to open log file: " << logFile << std::endl;
        return 1;
    }

    // શરૂઆતમાં file ના અંતે જાઓ (જૂના logs skip કરવા)
    file.seekg(0, std::ios::end);

    std::cout << "===== Logger Reader Started =====" << std::endl;

    while (true)
    {
        std::string line;

        // નવી lines વાંચો
        while (std::getline(file, line))
        {
            std::cout << "[NEW LOG] " << line << std::endl;

            // અહીં processing કરો
            // sendToAPI(line);
            // saveToDatabase(line);
        }

        // EOF clear કરો જેથી આગળ ફરી વાંચી શકાય
        file.clear();

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
