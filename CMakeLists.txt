cmake_minimum_required(VERSION 3.22.1)

set(CMAKE_FIND_PACKAGE_PREFER_CONFIG TRUE)

if(APPLE AND NOT CMAKE_OSX_DEPLOYMENT_TARGET)
    if(CMAKE_SYSTEM_NAME STREQUAL "iOS")
        set(CMAKE_OSX_DEPLOYMENT_TARGET 12.0 CACHE STRING "iOS Deployment Target")
    else()
        set(CMAKE_OSX_DEPLOYMENT_TARGET 10.10 CACHE STRING "macOS Deployment Target")
    endif()
endif()

project(datadirswx)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC_FILES
datadirswx.cpp
)

add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE ${SRC_FILES})

find_package(wxWidgets COMPONENTS core base REQUIRED)
if(wxWidgets_USE_FILE)
    include(${wxWidgets_USE_FILE})
endif()
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})



enable_testing()

add_test(NAME nominal COMMAND $<TARGET_FILE:${PROJECT_NAME}>)

add_test(NAME home COMMAND $<TARGET_FILE:${PROJECT_NAME}>)
set_property(TEST home PROPERTY ENVIRONMENT HOME=/tmp)

add_test(NAME appdata COMMAND $<TARGET_FILE:${PROJECT_NAME}>)
set_property(TEST appdata PROPERTY ENVIRONMENT APPDATA=Z:\\User\\Me\\AppData\\Roaming)
