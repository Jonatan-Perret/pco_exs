cmake_minimum_required(VERSION 3.13)

project(bridgesimple_tests)

set(CMAKE_CXX_STANDARD 17)

# Original test
set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

set(HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/bridgemanager.h
    ${CMAKE_CURRENT_SOURCE_DIR}/bridgemanagermonitor.h
)

add_executable(bridgesimple_tests ${SOURCES} ${HEADERS})
target_link_libraries(bridgesimple_tests PRIVATE -lpcosynchro gtest)

# Semaphore implementation
set(SOURCES_SEMAPHORE
    ${CMAKE_CURRENT_SOURCE_DIR}/main_semaphore.cpp
)

set(HEADERS_SEMAPHORE
    ${CMAKE_CURRENT_SOURCE_DIR}/bridgemanager_semaphore.h
)

add_executable(bridge_semaphore_tests ${SOURCES_SEMAPHORE} ${HEADERS_SEMAPHORE})
target_link_libraries(bridge_semaphore_tests PRIVATE -lpcosynchro gtest)

# Condition Variable implementation
set(SOURCES_CONDVAR
    ${CMAKE_CURRENT_SOURCE_DIR}/main_condvar.cpp
)

set(HEADERS_CONDVAR
    ${CMAKE_CURRENT_SOURCE_DIR}/bridgemanager_condvar.h
)

add_executable(bridge_condvar_tests ${SOURCES_CONDVAR} ${HEADERS_CONDVAR})
target_link_libraries(bridge_condvar_tests PRIVATE -lpcosynchro gtest)

# Hoare Monitor implementation
set(SOURCES_MONITOR
    ${CMAKE_CURRENT_SOURCE_DIR}/main_monitor.cpp
)

set(HEADERS_MONITOR
    ${CMAKE_CURRENT_SOURCE_DIR}/bridgemanagermonitor.h
)

add_executable(bridge_monitor_tests ${SOURCES_MONITOR} ${HEADERS_MONITOR})
target_link_libraries(bridge_monitor_tests PRIVATE -lpcosynchro gtest)

