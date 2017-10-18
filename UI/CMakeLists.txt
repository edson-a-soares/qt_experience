SET(MODULE_NAME "UI")
SET(MODULE_DIRECTORY "UI")

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_C_COMPILER /usr/bin/gcc)
set(CMAKE_CXX_COMPILER /usr/bin/g++)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Configure Qt Components
find_package(Qt5Widgets REQUIRED)
include_directories(${Qt5Widgets_INCLUDE_DIRS})

# Add compiler flags for building executables (-fPIE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

# Project structure directory
set(PROJECT_SOURCE_DIR ${CMAKE_HOME_DIRECTORY}/${MODULE_DIRECTORY}/src)

find_package(Qt5Core REQUIRED)
include_directories(${Qt5Core_INCLUDE_DIRS})

find_package(Qt5Gui REQUIRED)
include_directories(${Qt5Gui_INCLUDE_DIRS})

# Use the compile definitions defined in the Qt 5 Widgets module
add_definitions(${Qt5Widgets_DEFINITIONS})

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/${MODULE_DIRECTORY}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/${MODULE_DIRECTORY}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/${MODULE_DIRECTORY}/bin)

file(GLOB UI_SOURCE_FILES_TOP "${PROJECT_SOURCE_DIR}/*.cpp")
file(GLOB_RECURSE UI_SOURCE_FILES_NESTED ${PROJECT_SOURCE_DIR}/${MODULE_DIRECTORY}/*.cpp)
set(UI_SOURCE_FILES ${UI_SOURCE_FILES_TOP} ${UI_SOURCE_FILES_NESTED})

include_directories("${PROJECT_SOURCE_DIR}")

add_executable(UI ${UI_SOURCE_FILES})
target_link_libraries(UI Core Qt5::Core Qt5::Gui Qt5::Widgets)
