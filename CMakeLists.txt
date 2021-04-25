# Copyright David Stone 2021.
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE_1_0.txt or copy at
# http://www.boost.org/LICENSE_1_0.txt)

cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(numeric_traits LANGUAGES CXX)

add_subdirectory(cmake_strict_defaults)

add_library(numeric_traits INTERFACE)

target_include_directories(numeric_traits INTERFACE
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	$<INSTALL_INTERFACE:include>
)

target_link_libraries(numeric_traits INTERFACE strict_defaults_interface)

add_library(numeric_traits_test
	source/numeric_traits/incomplete.cpp
	source/numeric_traits/int128.cpp
	source/numeric_traits/min_max_value.cpp
)

target_link_libraries(numeric_traits_test PUBLIC numeric_traits strict_defaults)
