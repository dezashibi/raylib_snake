cmake_minimum_required(VERSION 3.25)
project(raylib_snake)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} main.cpp
        src/food.cpp
        )

include_directories(src)

find_package(raylib CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

if (NOT CMAKE_BUILD_TYPE STREQUAL "Debug")
    #set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
    set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "-SUBSYSTEM:windows -ENTRY:mainCRTStartup")

    # set optimization flags
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")
endif ()

file(COPY "${PROJECT_SOURCE_DIR}/assets" DESTINATION "${PROJECT_BINARY_DIR}")