// Copyright David Stone 2021.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <numeric_traits/max_value.hpp>

#include <limits>
#include <type_traits>

namespace {

template<typename T>
constexpr auto check_type() {
	static_assert(numeric_traits::max_value<T> == std::numeric_limits<T>::max());
}

template<typename T>
constexpr auto check_cv_qualifiers() {
	check_type<T>();
	check_type<T const>();
	check_type<T volatile>();
	check_type<T const volatile>();
	return true;
}

static_assert(check_cv_qualifiers<signed char>());
static_assert(check_cv_qualifiers<short>());
static_assert(check_cv_qualifiers<int>());
static_assert(check_cv_qualifiers<long>());
static_assert(check_cv_qualifiers<long long>());

static_assert(check_cv_qualifiers<unsigned char>());
static_assert(check_cv_qualifiers<unsigned short>());
static_assert(check_cv_qualifiers<unsigned int>());
static_assert(check_cv_qualifiers<unsigned long>());
static_assert(check_cv_qualifiers<unsigned long long>());

#if defined NUMERIC_TRAITS_DETAIL_HAS_128_BIT
static_assert(check_cv_qualifiers<numeric_traits::detail::int128_t>());
static_assert(check_cv_qualifiers<numeric_traits::detail::uint128_t>());
#endif

static_assert(check_cv_qualifiers<float>());
static_assert(check_cv_qualifiers<double>());
static_assert(check_cv_qualifiers<long double>());

static_assert(check_cv_qualifiers<bool>());

static_assert(check_cv_qualifiers<char>());
static_assert(check_cv_qualifiers<wchar_t>());
static_assert(check_cv_qualifiers<char8_t>());
static_assert(check_cv_qualifiers<char16_t>());
static_assert(check_cv_qualifiers<char32_t>());

template<typename T>
constexpr auto check_no_max() {
	static_assert(std::is_same_v<decltype(numeric_traits::max_value<T>), numeric_traits::incomplete>);
}

template<typename T>
constexpr auto check_no_max_cv_qualifiers() {
	check_no_max<T>();
	check_no_max<T const>();
	check_no_max<T volatile>();
	check_no_max<T const volatile>();
	return true;
}

static_assert(check_no_max_cv_qualifiers<void>());

} // namespace