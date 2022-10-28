// Copyright David Stone 2021.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <numeric_traits/int128.hpp>

#include <type_traits>

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