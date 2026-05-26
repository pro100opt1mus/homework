target_sources(${LONG_NUM_LIB}
    PRIVATE
        long_number.cpp
)

target_include_directories(${LONG_NUM_LIB}
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}"
)
