cmake_minimum_required(VERSION 3.10)

project(StudentuSistema)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CTest)

file(GLOB SOURCES CONFIGURE_DEPENDS "*.cpp")
list(REMOVE_ITEM SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")

add_library(StudentuSistemaCore ${SOURCES})
target_include_directories(StudentuSistemaCore PUBLIC ${CMAKE_SOURCE_DIR})

add_executable(StudentuSistema main.cpp)
target_link_libraries(StudentuSistema PRIVATE StudentuSistemaCore)

if(BUILD_TESTING)
	include(FetchContent)

	set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
	FetchContent_Declare(
		googletest
		URL https://github.com/google/googletest/archive/refs/tags/v1.16.0.zip
	)
	FetchContent_MakeAvailable(googletest)

	add_executable(StudentuSistemaTests tests/studentas_tests.cpp)
	target_link_libraries(StudentuSistemaTests PRIVATE StudentuSistemaCore GTest::gtest_main)

	include(GoogleTest)
	gtest_discover_tests(StudentuSistemaTests)
endif()