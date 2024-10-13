cmake_minimum_required(VERSION 3.28)

project(fluent)

set(CXX_STANDARD 20)
enable_testing()

add_library(fluent STATIC
    src/frequency.hpp
    src/date.hpp
    src/cashflow.h
    src/cashflow.cpp
    src/schedule.h
    src/schedule.cpp
    src/fixed_bond.h
    src/fixed_bond.cpp
    src/discounting.hpp
    src/calendar.hpp
)

set_target_properties(fluent PROPERTIES
    PUBLIC_HEADER 
    "src/frequency.hpp;src/date.hpp;src/cashflow.h;src/schedule.h;src/fixed_bond.h;src/discounting.hpp;src/calendar.hpp"
)

add_executable(fluent_tests
    tests/fixed_bond_tests.cpp
    tests/date_tests.cpp
    tests/cashflow_tests.cpp
    tests/schedule_tests.cpp
    tests/calendar_tests.cpp
)

if(WIN32)
    set(GTest_DIR "C:/sandbox/work/oss/googletest/install/lib/cmake/GTest")
    target_compile_options(fluent PRIVATE /W4 /WX)
    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT fluent)
else()
    set(GTest_DIR "/opt/disk1/work/oss/googletest/install/lib64/cmake/GTest")
endif()

find_package(GTest
    CONFIG
    REQUIRED
)

target_link_libraries(fluent_tests PRIVATE
    fluent
    GTest::gtest_main
)

target_include_directories(fluent_tests PRIVATE src)

install(TARGETS fluent 
        LIBRARY DESTINATION lib
        PUBLIC_HEADER DESTINATION include
)

install(TARGETS fluent_tests DESTINATION bin)
add_test(fluent_tests fluent_tests)