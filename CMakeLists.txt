cmake_minimum_required (VERSION 3.5)
project (signalrclient-sample)

find_path(SIGNALR_INCLUDE_DIR signalrclient/hub_connection.h)
include_directories(${SIGNALR_INCLUDE_DIR})

add_executable (sample sample.cpp)