cmake_minimum_required(VERSION 3.10)
project(simple-genie VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

if (APPLE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14") #For OSX
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++") #For Ubuntu
endif (APPLE)

add_subdirectory(genieutils EXCLUDE_FROM_ALL)

include_directories(
        "genieutils/include"
        "."
)
add_library(${CMAKE_PROJECT_NAME} SHARED simple.cpp data.cpp qt-genie.qrc)

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )


target_link_libraries(${CMAKE_PROJECT_NAME} genieutils Qt5::Core)
