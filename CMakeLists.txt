cmake_minimum_required(VERSION 3.14)

project(StudentuSistema LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source subdirectory
add_subdirectory(src)

# Testing support
enable_testing()

option(BUILD_TESTING "Build tests" ON)
if(BUILD_TESTING)
	include(FetchContent)

	set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
	FetchContent_Declare(
		googletest
		URL https://github.com/google/googletest/archive/refs/tags/v1.16.0.zip
	)
	FetchContent_MakeAvailable(googletest)

	add_subdirectory(tests)
endif()