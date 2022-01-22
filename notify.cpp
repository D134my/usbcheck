#include "notify.hpp"
#include <ranges>

notify::notify() { std::cout << "Thank you for using usbcheck\n"; }

void notify::start() { // add existing files into vector
  for (auto const &file : fs::recursive_directory_iterator(path_To_Watch)) {
    files.push_back(std::string(file.path().filename()));
  }
}

void notify::check_Add() {
  std::string dunst{"dunstify"};
  while (true) {
    // checks the path if any file founded that doesn't exist in our
    // vec (which means new file added) and has sd?? name

    for (auto const &file : fs::recursive_directory_iterator(path_To_Watch)) {
      if (std::regex_search(std::string(file.path().filename()), re) &&
          std::ranges::find(files, std::string(file.path().filename())) ==
              files.end()) {

        dunst += " ";
        dunst += file.path().filename();
        dunst += " connected";

        std::system(dunst.c_str());
        dunst = "dunstify";
        files.push_back(std::string(file.path().filename()));
        std::this_thread::sleep_for(time_To_Watch);
      }
    }
  }
}
