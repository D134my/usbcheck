#include "notify.hpp"

void lippincott() {
  try {
    throw;
  } catch (std::runtime_error const &error) {
    std::cerr << "runtime happend error \n";
  } catch (std::exception const &error) {
    std::cerr << "error !! : " << error.what() << '\n';
  } catch (...) {
    std::cerr << "unknown error\n";
  }
}

int main() {

  try {
    notify s;
    s.start();
    s.check_Add();
  } catch (...) {
    lippincott();
    std::exit(EXIT_FAILURE);
  }

  return EXIT_SUCCESS;
}