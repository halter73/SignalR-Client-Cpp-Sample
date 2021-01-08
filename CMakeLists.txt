cmake_minimum_required (VERSION 3.5)
project (signalrclient-sample)

find_path(SIGNALR_INCLUDE_DIR signalrclient/hub_connection.h)
include_directories(${SIGNALR_INCLUDE_DIR})

find_library(SIGNALR_LIBRARY NAMES signalrclient PATHS {SIGNALR_INCLUDE_DIR} REQUIRED)
link_libraries(${SIGNALR_LIBRARY})

add_executable (sample sample.cpp)