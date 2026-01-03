cmake_minimum_required(VERSION 3.13)

project(sequentialite1_tests)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/main_joins.cpp
)

add_executable(sequentialite1_tests ${SOURCES})

project(sequentialite2_tests)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/main_semaphores.cpp
)

add_executable(sequentialite2_tests ${SOURCES})

target_link_libraries(sequentialite1_tests PRIVATE -lpcosynchro gtest)
target_link_libraries(sequentialite2_tests PRIVATE -lpcosynchro gtest)

