#include "notify.hpp"
#include <ranges>

notify::notify() { std::cout << "Thank you for using usbcheck\n"; }

void notify::start() { // add existing files into vector
  for (auto const &file : fs::recursive_directory_iterator(path_To_Watch)) {
    files.push_back(std::string(file.path().filename()));
    if (std::regex_search(std::string(file.path().filename()), re))
      result_Files.push_back(file.path().filename());
  }
}

void notify::check_Add() {
  while (true) {
    // checks the path if any file founded that doesn't exist in our
    // vec (which means new file added) and has sd?? name

    for (auto const &file : fs::recursive_directory_iterator(path_To_Watch)) {
      if (std::regex_search(std::string(file.path().filename()), re) &&
          std::ranges::find(files, std::string(file.path().filename())) ==
              files.end()) {

        std::string connect_Dunst = dunst +
                                    std::string(file.path().filename()) +
                                    std::string(" Connected");

        std::system(connect_Dunst.c_str());
        files.push_back(std::string(file.path().filename()));
        result_Files.push_back(std::string(file.path().filename()));
      }
      check_Eject();
    }
  }
}

void notify::check_Eject() { // checks if founded usbs don't exist in /dev/
  for (auto const &file : result_Files) {
    if (!fs::exists(std::string(path_To_Watch + file))) {
      std::string eject_Dunst = dunst + file + std::string(" Ejected");
      std::system(eject_Dunst.c_str());

      result_Files.erase(
          std::remove(result_Files.begin(), result_Files.end(), file));
      result_Files.shrink_to_fit();

      files.erase(std::remove(files.begin(), files.end(), file));
    }
  }
}
