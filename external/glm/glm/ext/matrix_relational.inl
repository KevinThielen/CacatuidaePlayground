/// @ref ext_vector_relational
/// @file cac/ext/vector_relational.inl

// Dependency:
#include "../ext/vector_relational.hpp"
#include "../common.hpp"

namespace cac
{
	template<length_t C, length_t R, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<C, bool, Q> equal(mat<C, R, T, Q> const& a, mat<C, R, T, Q> const& b)
	{
		return equal(a, b, static_cast<T>(0));
	}

	template<length_t C, length_t R, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<C, bool, Q> equal(mat<C, R, T, Q> const& a, mat<C, R, T, Q> const& b, T Epsilon)
	{
		return equal(a, b, vec<C, T, Q>(Epsilon));
	}

	template<length_t C, length_t R, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<C, bool, Q> equal(mat<C, R, T, Q> const& a, mat<C, R, T, Q> const& b, vec<C, T, Q> const& Epsilon)
	{
		vec<C, bool, Q> Result(true);
		for(length_t i = 0; i < C; ++i)
			Result[i] = all(equal(a[i], b[i], Epsilon[i]));
		return Result;
	}

	template<length_t C, length_t R, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<C, bool, Q> notEqual(mat<C, R, T, Q> const& x, mat<C, R, T, Q> const& y)
	{
		return notEqual(x, y, static_cast<T>(0));
	}

	template<length_t C, length_t R, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<C, bool, Q> notEqual(mat<C, R, T, Q> const& x, mat<C, R, T, Q> const& y, T Epsilon)
	{
		return notEqual(x, y, vec<C, T, Q>(Epsilon));
	}

	template<length_t C, length_t R, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER GLM_CONSTEXPR vec<C, bool, Q> notEqual(mat<C, R, T, Q> const& a, mat<C, R, T, Q> const& b, vec<C, T, Q> const& Epsilon)
	{
		vec<C, bool, Q> Result(true);
		for(length_t i = 0; i < C; ++i)
			Result[i] = any(notEqual(a[i], b[i], Epsilon[i]));
		return Result;
	}
}//namespace cac
