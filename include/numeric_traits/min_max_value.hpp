// Copyright David Stone 2021.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <numeric_traits/incomplete.hpp>
#include <numeric_traits/int128.hpp>

#include <cfloat>
#include <cstddef>

namespace numeric_traits {

template<typename>
extern incomplete min_value;

template<typename>
extern incomplete max_value;

// These concepts exist until we can delete variable templates
template<typename T>
concept has_min_value = !std::is_same_v<decltype(min_value<T>), incomplete>;

template<typename T>
concept has_max_value = !std::is_same_v<decltype(max_value<T>), incomplete>;

template<has_min_value T>
inline constexpr auto min_value<T const> = min_value<T>;

template<has_max_value T>
inline constexpr auto max_value<T const> = max_value<T>;

template<has_min_value T>
inline constexpr auto min_value<T volatile> = min_value<T>;

template<has_max_value T>
inline constexpr auto max_value<T volatile> = max_value<T>;

template<has_min_value T>
inline constexpr auto min_value<T const volatile> = min_value<T>;

template<has_max_value T>
inline constexpr auto max_value<T const volatile> = max_value<T>;


template<>
inline constexpr auto min_value<std::byte> = std::byte(0);

template<>
inline constexpr auto max_value<std::byte> = std::byte(-1);


template<detail::unsigned_builtin T>
inline constexpr auto min_value<T> = T(0);

template<detail::unsigned_builtin T>
inline constexpr auto max_value<T> = T(-1);

// Signed integers are two's complement
template<detail::signed_builtin T>
inline constexpr auto max_value<T> = static_cast<T>(max_value<detail::make_unsigned<T>> / 2);

template<detail::signed_builtin T>
inline constexpr auto min_value<T> = static_cast<T>(-max_value<T> - 1);


template<>
inline constexpr auto min_value<float> = FLT_MIN;

template<>
inline constexpr auto max_value<float> = FLT_MAX;

template<>
inline constexpr auto min_value<double> = DBL_MIN;

template<>
inline constexpr auto max_value<double> = DBL_MAX;

template<>
inline constexpr auto min_value<long double> = LDBL_MIN;

template<>
inline constexpr auto max_value<long double> = LDBL_MAX;

} // namespace numeric_traits