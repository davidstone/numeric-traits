// Copyright David Stone 2021.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

module;

#include <numeric_traits/has_int128.hpp>

export module numeric_traits.int128;

import std_module;

namespace numeric_traits {

#if defined NUMERIC_TRAITS_HAS_INT128

#if defined __GNUC__
	export using int128_t = __int128_t;
	export using uint128_t = __uint128_t;
#endif

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

export template<typename T>
using make_signed = typename make_signed_impl<T>::type;

export template<typename T>
using make_unsigned = typename make_unsigned_impl<T>::type;

export template<typename T>
concept signed_builtin = std::signed_integral<T> or std::same_as<T, int128_t>;

export template<typename T>
concept unsigned_builtin = std::unsigned_integral<T> or std::same_as<T, uint128_t>;

export using max_signed_t = int128_t;
export using max_unsigned_t = uint128_t;

#else

export template<typename T>
using make_signed = std::make_signed_t<T>;

export template<typename T>
using make_unsigned = std::make_unsigned_t<T>;

export template<typename T>
concept signed_builtin = std::signed_integral<T>;

export template<typename T>
concept unsigned_builtin = std::unsigned_integral<T>;

export using max_signed_t = std::intmax_t;
export using max_unsigned_t = std::uintmax_t;

#endif

export template<typename T>
using promoted_unsigned = std::conditional_t<
	sizeof(T) <= sizeof(unsigned),
	unsigned,
	make_unsigned<std::decay_t<T>>
>;

} // namespace numeric_traits

namespace {

static_assert(std::same_as<numeric_traits::make_signed<int>, int>);
static_assert(std::same_as<numeric_traits::make_signed<unsigned>, int>);

static_assert(std::same_as<numeric_traits::make_unsigned<int>, unsigned>);
static_assert(std::same_as<numeric_traits::make_unsigned<unsigned>, unsigned>);

static_assert(numeric_traits::signed_builtin<int>);
static_assert(!numeric_traits::signed_builtin<unsigned>);
static_assert(!numeric_traits::signed_builtin<void>);

static_assert(!numeric_traits::unsigned_builtin<int>);
static_assert(numeric_traits::unsigned_builtin<unsigned>);
static_assert(!numeric_traits::unsigned_builtin<void>);

#if defined NUMERIC_TRAITS_DETAIL_HAS_128_BIT

static_assert(std::same_as<numeric_traits::make_signed<numeric_traits::int128_t>, numeric_traits::int128_t>);
static_assert(std::same_as<numeric_traits::make_signed<numeric_traits::uint128_t>, numeric_traits::int128_t>);

static_assert(std::same_as<numeric_traits::make_unsigned<numeric_traits::int128_t>, numeric_traits::uint128_t>);
static_assert(std::same_as<numeric_traits::make_unsigned<numeric_traits::uint128_t>, numeric_traits::uint128_t>);

static_assert(numeric_traits::signed_builtin<numeric_traits::int128_t>);
static_assert(!numeric_traits::signed_builtin<numeric_traits::uint128_t>);

static_assert(!numeric_traits::unsigned_builtin<numeric_traits::int128_t>);
static_assert(numeric_traits::unsigned_builtin<numeric_traits::uint128_t>);

#endif

} // namespace