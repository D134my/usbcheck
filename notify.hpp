#ifndef NOTIFY_HPP
#define NOTIFY_HPP

#include <chrono>
#include <exception>
#include <filesystem>
#include <iostream>
#include <regex>
#include <vector>

namespace fs = std::filesystem;
namespace chrono = std::chrono;
using namespace std::chrono_literals;

class notify {
public:
  void start();
  void check_Add();
  void check_Eject();

  notify();
  ~notify() = default;
  notify(notify &) = delete;
  notify(notify &&) = delete;
  notify &operator=(notify const &) = delete;
  notify &operator=(notify &&) = delete;

private:
  std::regex const re{R"(sd.\d?)"};
  static const inline std::string path_To_Watch{"/dev/"};
  std::vector<std::string> files;
  std::vector<std::string> result_Files;
  std::string const dunst{"dunstify "};
};

#endif // NOTIFY_HPP
