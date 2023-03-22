// logger.h
#pragma once

#include <iostream>
#include <string>
#include <chrono>
#include <ctime>

enum class LogLevel {
    Info,
    Warning,
    Error
};

class Logger {
public:
    static void log(LogLevel level, const std::string& message) {
        std::string timestamp = currentDateTime();
        std::cout << "[" << levelToString(level) << " - " << timestamp << "] " << message << std::endl;
    }

private:
    static const char* levelToString(LogLevel level) {
        switch (level) {
            case LogLevel::Info:
                return "Info";
            case LogLevel::Warning:
                return "Warning";
            case LogLevel::Error:
                return "Error";
            default:
                return "Unknown";
        }
    }

    static std::string currentDateTime() {
        auto now = std::chrono::system_clock::now();
        auto in_time_t = std::chrono::system_clock::to_time_t(now);

        std::tm buf;
        localtime_r(&in_time_t, &buf);

        char buffer[80];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &buf);
        return std::string(buffer);
    }
};