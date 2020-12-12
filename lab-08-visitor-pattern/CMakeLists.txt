cmake_minimum_required(VERSION 2.8)
add_subdirectory(googletest)
set(CMAKE_CXX_STANDARD 11)

add_executable(test
    tests/initialize_google_test.cpp
    src/binary_iterator.cpp
    src/preorder_iterator.cpp
)

add_executable(lab08
     main.cpp
     src/binary_iterator.cpp
     src/preorder_iterator.cpp
 )

target_link_libraries(test gtest)
target_compile_definitions(test PRIVATE gtest_disable_pthreads=ON)
