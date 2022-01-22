#ifndef NOTIFY_HPP
#define NOTIFY_HPP

#include <chrono>
#include <exception>
#include <filesystem>
#include <iostream>
#include <regex>
#include <thread>
#include <vector>

namespace fs = std::filesystem;
namespace chrono = std::chrono;
using namespace std::chrono_literals;

void lipincott();

class notify {
public:
  void start();
  void check_Add();

  notify();
  ~notify() = default;
  notify(notify &) = delete;
  notify(notify &&) = delete;
  notify &operator=(notify const &) = delete;
  notify &operator=(notify &&) = delete;

private:
  std::regex const re{R"(sd.\d?)"};
  constexpr static const inline chrono::seconds time_To_Watch = 2s;
  static const inline std::string path_To_Watch{"/dev/"};
  std::vector<std::string> files;
};

#endif // NOTIFY_HPP
