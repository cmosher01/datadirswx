cmake_minimum_required(VERSION 3.22.1)

set(CMAKE_FIND_PACKAGE_PREFER_CONFIG TRUE)

project(datadirswx)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC_FILES
datadirswx.cpp
)

add_executable(${PROJECT_NAME} ${SRC_FILES})

find_package(wxWidgets COMPONENTS core base REQUIRED)
include(${wxWidgets_USE_FILE})
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})



enable_testing()

add_test(NAME nominal COMMAND $<TARGET_FILE:${PROJECT_NAME}>)

if(UNIX AND NOT APPLE)
add_test(NAME home COMMAND $<TARGET_FILE:${PROJECT_NAME}>)
set_property(TEST home PROPERTY ENVIRONMENT HOME=${CMAKE_SOURCE_DIR}/home)
endif()
