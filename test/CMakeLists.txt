cmake_minimum_required(VERSION 3.10.2)

set(This FractionTest)

set(Sources
    TestMain.cpp
    FractionTest.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This}
    gtest_main
    Fraction
)

add_test(
    NAME ${This}
    COMMAND ${This}
)