cmake_minimum_required (VERSION 3.8)
project (signalrclient-sample)


find_package(microsoft-signalr CONFIG REQUIRED)
link_libraries(microsoft-signalr::microsoft-signalr)

add_executable (sample sample.cpp)