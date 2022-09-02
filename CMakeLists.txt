cmake_minimum_required(VERSION 3.16)

project(HO VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS QuickControls2)

file(GLOB_RECURSE srcs
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h"
)

file(GLOB_RECURSE pahoLibs
    "${CMAKE_CURRENT_SOURCE_DIR}/external/eclipse-paho-mqtt-c-win64-1.3.9/lib/*.lib"
)

file(GLOB_RECURSE images
    ./images/*.png
)

qt_add_executable(appHO ${srcs})


qt_add_resources(appHO "images"
    PREFIX "/"
    FILES
          ./images/setting_off.png
      )

qt_add_qml_module(appHO
    URI HO
    VERSION 1.0
    QML_FILES
        ./qml/main.qml
        ./qml/main_setting.qml
        ./qml/SettingButton.qml
)

set_target_properties(appHO PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appHO PRIVATE
      Qt6::Quick
      Qt6::QuickControls2
      ${pahoLibs}
      ${CMAKE_CURRENT_SOURCE_DIR}/external/paho-mqtt-cpp/lib/paho-mqttpp3-static.lib
)


target_include_directories(appHO PUBLIC
      ${CMAKE_CURRENT_SOURCE_DIR}
      ${CMAKE_CURRENT_SOURCE_DIR}/include
      ${PROJECT_BINARY_DIR}
     "${CMAKE_CURRENT_SOURCE_DIR}/external/boost_1_80_0"
     "${CMAKE_CURRENT_SOURCE_DIR}/external/eclipse-paho-mqtt-c-win64-1.3.9/include"
      ${CMAKE_CURRENT_SOURCE_DIR}/external/paho-mqtt-cpp/include/

)

install(TARGETS appHO
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})