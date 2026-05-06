# Create test executable
add_executable(StudentuSistemaTests studentas_tests.cpp)

# Link with core library and GoogleTest
target_link_libraries(StudentuSistemaTests PRIVATE 
    StudentuSistemaCore 
    GTest::gtest_main
)

# Include directories for tests
target_include_directories(StudentuSistemaTests PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

# Discover tests using GoogleTest
include(GoogleTest)
gtest_discover_tests(StudentuSistemaTests)
