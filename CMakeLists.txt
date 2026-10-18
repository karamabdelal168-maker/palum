cmake_minimum_required(VERSION 3.10.0)
project(palum VERSION 0.1.0 LANGUAGES C CXX)

add_executable(palum src/main.cpp src/the_dediction.cpp src/vector_to_string_array.cpp)
include_directories( /include/the_dedcition.hpp /include/vector_to_string_array.hpp)


include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
