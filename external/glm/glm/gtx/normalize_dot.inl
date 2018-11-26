/// @ref gtx_normalize_dot

namespace cac
{
	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER T normalizeDot(vec<L, T, Q> const& x, vec<L, T, Q> const& y)
	{
		return cac::dot(x, y) * cac::inversesqrt(cac::dot(x, x) * cac::dot(y, y));
	}

	template<length_t L, typename T, qualifier Q>
	GLM_FUNC_QUALIFIER T fastNormalizeDot(vec<L, T, Q> const& x, vec<L, T, Q> const& y)
	{
		return cac::dot(x, y) * cac::fastInverseSqrt(cac::dot(x, x) * cac::dot(y, y));
	}
}//namespace cac
