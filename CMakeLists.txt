cmake_minimum_required(VERSION 3.5)

project(usbcheck LANGUAGES CXX VERSION 2.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(usbcheck main.cpp notify.cpp notify.hpp)
target_link_libraries(usbcheck stdc++fs)
target_link_libraries(usbcheck pthread)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/bin/dunstify 
 	PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ
	DESTINATION /usr/bin)
install(TARGETS usbcheck DESTINATION /usr/bin)
