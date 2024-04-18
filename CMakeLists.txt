cmake_minimum_required(VERSION 3.16)
project(SPEL VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})

# Define source and header files
set(SOURCES
    src/kod_till_UI/App.cpp
    src/kod_till_UI/MainFrame.cpp
    src/kod_till_UI/About.cpp
    src/kod_till_UI/Settings.cpp
)

set(HEADERS
    include/granssnitt/App.h
    include/granssnitt/MainFrame.h
    include/granssnitt/About.h
    include/granssnitt/Settings.h
)

# Assuming your executable is named after your project, adjust as necessary
add_executable(UI WIN32 ${SOURCES} ${HEADERS})

# Include the directory where your headers are located
target_include_directories(UI PRIVATE ${CMAKE_SOURCE_DIR}/include/granssnitt)

# Link with wxWidgets
target_link_libraries(UI PRIVATE ${wxWidgets_LIBRARIES})

# Source and header files
set(SOURCES
    src/spelmotor/main.cpp
    src/websocket/websocketClient.cpp
)
set(HEADERS
    include/websocket/websocketClient.h
)

# Find required packages
find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(Boost REQUIRED COMPONENTS system)

# Add executable
add_executable(APP ${SOURCES} ${HEADERS})

# Include directories
target_include_directories(APP PRIVATE "${CMAKE_SOURCE_DIR}/include")

# Link libraries
target_link_libraries(APP PRIVATE SDL2::SDL2 SDL2_ttf::SDL2_ttf Boost::system)



