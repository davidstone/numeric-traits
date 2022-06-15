// Copyright David Stone 2021.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <concepts>
#include <cstdint>
#include <type_traits>

namespace numeric_traits {
namespace detail {

#if defined __GNUC__
	#define NUMERIC_TRAITS_DETAIL_HAS_128_BIT 1
	using int128_t = __int128_t;
	using uint128_t = __uint128_t;
#endif

#if defined NUMERIC_TRAITS_DETAIL_HAS_128_BIT

template<typename T>
struct make_signed_impl {
	using type = std::make_signed_t<T>;
};
template<>
struct make_signed_impl<int128_t> {
	using type = int128_t;
};
template<>
struct make_signed_impl<uint128_t> {
	using type = int128_t;
};
template<typename T>
using make_signed = typename make_signed_impl<T>::type;

template<typename T>
struct make_unsigned_impl {
	using type = std::make_unsigned_t<T>;
};
template<>
struct make_unsigned_impl<int128_t> {
	using type = uint128_t;
};
template<>
struct make_unsigned_impl<uint128_t> {
	using type = uint128_t;
};
template<typename T>
using make_unsigned = typename make_unsigned_impl<T>::type;

template<typename T>
concept signed_builtin = std::signed_integral<T> or std::is_same_v<T, int128_t>;

template<typename T>
concept unsigned_builtin = std::unsigned_integral<T> or std::is_same_v<T, uint128_t>;

#else

template<typename T>
using make_signed = std::make_signed_t<T>;

template<typename T>
using make_unsigned = std::make_unsigned_t<T>;

template<typename T>
concept signed_builtin = std::signed_integral<T>;

template<typename T>
concept unsigned_builtin = std::unsigned_integral<T>;

#endif

} // namespace detail
} // namespace numeric_traits