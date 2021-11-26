cmake_minimum_required (VERSION 3.15)

project(SinglyLinkedList)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB SOURCES
	"src/*.cpp")

file(GLOB HEADERS
	"include/*.h")

add_library(${PROJECT_NAME} STATIC ${SOURCES} ${HEADERS})
