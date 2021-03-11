// Copyright David Stone 2021.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <numeric_traits/int128.hpp>

#include <type_traits>

namespace {

using namespace numeric_traits;

static_assert(std::is_same_v<detail::make_signed<int>, int>);
static_assert(std::is_same_v<detail::make_signed<unsigned>, int>);

static_assert(std::is_same_v<detail::make_unsigned<int>, unsigned>);
static_assert(std::is_same_v<detail::make_unsigned<unsigned>, unsigned>);

static_assert(detail::signed_builtin<int>);
static_assert(!detail::signed_builtin<unsigned>);
static_assert(!detail::signed_builtin<void>);

static_assert(!detail::unsigned_builtin<int>);
static_assert(detail::unsigned_builtin<unsigned>);
static_assert(!detail::unsigned_builtin<void>);

#if defined NUMERIC_TRAITS_DETAIL_HAS_128_BIT

static_assert(std::is_same_v<detail::make_signed<detail::int128_t>, detail::int128_t>);
static_assert(std::is_same_v<detail::make_signed<detail::uint128_t>, detail::int128_t>);

static_assert(std::is_same_v<detail::make_unsigned<detail::int128_t>, detail::uint128_t>);
static_assert(std::is_same_v<detail::make_unsigned<detail::uint128_t>, detail::uint128_t>);

static_assert(detail::signed_builtin<detail::int128_t>);
static_assert(!detail::signed_builtin<detail::uint128_t>);

static_assert(!detail::unsigned_builtin<detail::int128_t>);
static_assert(detail::unsigned_builtin<detail::uint128_t>);

#endif

} // namespace