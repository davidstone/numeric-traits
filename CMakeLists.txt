# Copyright David Stone 2021.
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE_1_0.txt or copy at
# http://www.boost.org/LICENSE_1_0.txt)

cmake_minimum_required(VERSION 3.27 FATAL_ERROR)

project(numeric_traits LANGUAGES CXX)

get_directory_property(has_parent PARENT_DIRECTORY)
if (NOT has_parent)
	set(CMAKE_CXX_STANDARD 26)
	set(CMAKE_CXX_STANDARD_REQUIRED On)
	set(CMAKE_CXX_EXTENSIONS Off)

	set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API "ac01f462-0f5f-432a-86aa-acef252918a6")

	add_subdirectory(dependencies/cmake_strict_defaults)
	add_subdirectory(dependencies/std_module)
endif()

add_library(numeric_traits STATIC)

target_include_directories(numeric_traits PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	$<INSTALL_INTERFACE:include>
)

target_link_libraries(numeric_traits
	PUBLIC strict_defaults_interface std_module
	PRIVATE strict_defaults
)

target_sources(numeric_traits PUBLIC
	FILE_SET CXX_MODULES
	BASE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}"
	FILES
		source/numeric_traits/numeric_traits.cpp
		source/numeric_traits/incomplete.cpp
		source/numeric_traits/int128.cpp
		source/numeric_traits/min_max_value.cpp
)
