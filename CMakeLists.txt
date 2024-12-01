cmake_minimum_required(VERSION 3.10)
project(HistorianHysteria)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
    src/Main.cpp
    src/ArgumentParser.cpp
    src/FileReader.cpp
)

set(HEADERS
    src/ArgumentParser.hpp
    src/Calculator.hpp
    src/FileReader.hpp
)

add_executable(HistorianHysteria ${SOURCES} ${HEADERS})
