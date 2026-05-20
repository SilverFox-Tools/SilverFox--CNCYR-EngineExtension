#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

using std::string;

string 获取当前时间() {
    auto now = std::chrono::system_clock::now();
    auto time_t = std::chrono::system_clock::to_time_t(now);

    std::stringstream ss;
    ss << std::put_time(std::localtime(&time_t), "%Y-%m-%d %H:%M:%S");
    return ss.str();
}