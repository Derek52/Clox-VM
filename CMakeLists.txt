cmake_minimum_required(VERSION 3.24)

project(clox)

include_directories(
	${PROJECT_SOURCE_DIR}/include
	${PROJECT_SOURCE_DIR}/src
)

file(GLOB all_SRCS
	"${PROJECT_SOURCE_DIR}/include/*.h"
	"${PROJECT_SOURCE_DIR}/src/*.c"
)

add_executable(clox ${all_SRCS})
