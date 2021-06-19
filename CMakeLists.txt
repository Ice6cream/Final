# CMakeList.txt: файл проекта CMake верхнего уровня; проведите глобальную конфигурацию
# и включите сюда подпроекты.
#
cmake_minimum_required (VERSION 3.8)

project ("mario")
add_library(default INTERFACE) 
target_compile_features(default INTERFACE cxx_std_17)  
set(SFML_STATIC_LIBRARIES TRUE) 
find_package(SFML COMPONENTS graphics window system)  

include(cmake/StandardProjectSettings.cmake) 
include(cmake/Catch.cmake) 
include(cmake/CompilerWarnings.cmake) 
set_project_warnings(default)

enable_testing()
add_subdirectory(external/doctest) 
include(external/doctest/doctest.cmake)
include_directories(external/doctest)

# Включите подпроекты.
add_subdirectory ("mario")
