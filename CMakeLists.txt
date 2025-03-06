cmake_minimum_required(VERSION 3.13)
project(LibraryManagement)

# Headers Directory
include_directories(include)

# All Source Files
add_executable(
	my_app
	src/main.c
	src/book.c
	src/functions.c
	src/hashmap.c
)
