set(SOURCES
    test_long_number.cpp
)

add_executable(test_long_numbers ${SOURCES})

target_link_libraries(test_long_numbers
    gtest
    gtest_main
    ${LONG_NUM_LIB}
)

add_test(NAME test_long_numbers COMMAND test_long_numbers)
