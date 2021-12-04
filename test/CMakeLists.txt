cmake_minimum_required (VERSION 3.15)

include(GoogleTest)

project(SingleLinkedListTests)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(PARENT_SRC_DIR ../src)
set(PARENT_INCLUDE_DIR ../include)
set(GOOGLE_TEST_DIR ../GoogleTest/include)

include_directories("${PARENT_INCLUDE_DIR}")
include_directories("${GOOGLE_TEST_DIR}")

file(GLOB SOURCES
 	"${PROJECT_SOURCE_DIR}/src/unitTests.cpp"
)
file(GLOB HEADERS
    "${PARENT_INCLUDE_DIR}/SinglyLinkedList.h"
)

if(CMAKE_BUILD_TYPE MATCHES Release)
	set (LIB_NAMES_LIST gmock gmock_main gtest gtest_main)
else()
	set (LIB_NAMES_LIST gmockd gmock_maind gtestd gtest_maind)
endif()
	
set (LIB_PATH "../GoogleTest/lib/${CMAKE_BUILD_TYPE}")

list(APPEND GOOGLE_TEST_LIBS "")

find_path(GOOGLE_TEST_INCLUDE_DIR gtest/gtest.h
	PATHS "../GoogleTest/include"
)

foreach(NAME ${LIB_NAMES_LIST})

	find_library(${NAME}_LIBRARY
		NAMES ${NAME}
		PATHS ${LIB_PATH}
	)

	list(APPEND GOOGLE_TEST_LIBS ${${NAME}_LIBRARY})

endforeach()

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${GOOGLE_TEST_LIBS})

gtest_add_tests(TARGET ${PROJECT_NAME})