cmake_minimum_required(VERSION 4.2.3)
project(Snake)

set(CMAKE_AUTOMOC ON)
set(CMAKE_PREFIX_PATH "/opt/homebrew/opt/qt/lib/cmake")
set(CMAKE_CXX_STANDARD 20)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

add_executable(${PROJECT_NAME}
	src/main.cpp
	src/snake.cpp
	src/graphics.cpp
	src/input.cpp
	include/snake.hpp
	include/constants.hpp)

target_link_libraries(${PROJECT_NAME} Qt6::Core Qt6::Widgets)
