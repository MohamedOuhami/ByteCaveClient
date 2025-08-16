cmake_minimum_required(VERSION 3.16)

project(ByteCaveClient VERSION 0.1 LANGUAGES CXX)

# -----------------------------
# C++ standard
# -----------------------------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# -----------------------------
# Qt auto features
# -----------------------------
set(CMAKE_AUTOUIC ON)    # process .ui files automatically
set(CMAKE_AUTOMOC ON)    # process Q_OBJECT macros
set(CMAKE_AUTORCC ON)    # process Qt resource files

# -----------------------------
# Find Qt
# -----------------------------
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

# -----------------------------
# Source files
# -----------------------------
set(PROJECT_SOURCES
    main.cpp

    # Main window
    mainwindow.h
    mainwindow.cpp
    mainwindow.ui

    # Other windows
    hellowindow.h
    hellowindow.cpp
    hellowindow.ui

    chatroomcreation.h
    chatroomcreation.cpp
    chatroomcreation.ui

    # Services and structs
    services/bytecaveclient.h
    services/bytecaveclient.cpp
    structs/Chatroom.h

    # Add any other source files here
)

# -----------------------------
# Executable
# -----------------------------
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(ByteCaveClient
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    add_executable(ByteCaveClient
        ${PROJECT_SOURCES}
    )
endif()

# -----------------------------
# Link Qt libraries
# -----------------------------
target_link_libraries(ByteCaveClient PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# -----------------------------
# Include directories
# -----------------------------
target_include_directories(ByteCaveClient
    PRIVATE
    ${CMAKE_SOURCE_DIR}/include/asio
    ${CMAKE_SOURCE_DIR}/interfaces
    ${CMAKE_SOURCE_DIR}/services
    ${CMAKE_SOURCE_DIR}/structs
    ${CMAKE_SOURCE_DIR}/Forms
    /home/v01d/dev/libs/include/json/include  # nlohmann/json
)

# -----------------------------
# Finalize Qt executable
# -----------------------------
if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(ByteCaveClient)
endif()

# -----------------------------
# Optional: install
# -----------------------------
include(GNUInstallDirs)
install(TARGETS ByteCaveClient
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
