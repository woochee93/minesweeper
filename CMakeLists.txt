cmake_minimum_required(VERSION 3.14)
project(my_project)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(SOURCES
  src/Minesweeper.cpp
  src/Bomb.cpp
  src/Board.cpp)
 set (TEST_SOURCES tests/Minesweeper.test.cpp)

# add_executable(app main.cpp)
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)

FetchContent_MakeAvailable(googletest)
add_compile_options(-Wall -Werror -pedantic -Wextra)
enable_testing()

add_executable(
  my_tests
  ${SOURCES}
  ${TEST_SOURCES}
)
target_link_libraries(
  my_tests
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(my_tests)