// Copyright David Stone 2021.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <numeric_traits/incomplete.hpp>
#include <numeric_traits/int128.hpp>

#include <cfloat>

namespace numeric_traits {

template<typename>
extern incomplete max_value;

template<typename T> requires(!std::is_same_v<decltype(max_value<T>), incomplete>)
inline constexpr auto max_value<T const> = max_value<T>;

template<typename T> requires(!std::is_same_v<decltype(max_value<T>), incomplete>)
inline constexpr auto max_value<T volatile> = max_value<T>;

template<typename T> requires(!std::is_same_v<decltype(max_value<T>), incomplete>)
inline constexpr auto max_value<T const volatile> = max_value<T>;

template<detail::unsigned_builtin T>
inline constexpr auto max_value<T> = T(-1);

// Signed integers are two's complement
template<detail::signed_builtin T>
inline constexpr auto max_value<T> = static_cast<T>(max_value<detail::make_unsigned<T>> / 2);

template<>
inline constexpr auto max_value<float> = FLT_MAX;

template<>
inline constexpr auto max_value<double> = DBL_MAX;

template<>
inline constexpr auto max_value<long double> = LDBL_MAX;

} // namespace numeric_traits