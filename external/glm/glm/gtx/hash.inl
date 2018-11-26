/// @ref gtx_hash
///
/// @see core (dependence)
///
/// @defgroup gtx_hash GLM_GTX_hash
/// @ingroup gtx
///
/// @brief Add std::hash support for cac types
///
/// <cac/gtx/hash.inl> need to be included to use the features of this extension.

namespace cac {
namespace detail
{
	GLM_INLINE void hash_combine(size_t &seed, size_t hash)
	{
		hash += 0x9e3779b9 + (seed << 6) + (seed >> 2);
		seed ^= hash;
	}
}}

namespace std
{
	template<typename T, cac::qualifier Q>
	GLM_FUNC_QUALIFIER size_t hash<cac::vec<1, T, Q>>::operator()(cac::vec<1, T, Q> const& v) const
	{
		hash<T> hasher;
		return hasher(v.x);
	}

	template<typename T, cac::qualifier Q>
	GLM_FUNC_QUALIFIER size_t hash<cac::vec<2, T, Q>>::operator()(cac::vec<2, T, Q> const& v) const
	{
		size_t seed = 0;
		hash<T> hasher;
		cac::detail::hash_combine(seed, hasher(v.x));
		cac::detail::hash_combine(seed, hasher(v.y));
		return seed;
	}

	template<typename T, cac::qualifier Q>
	GLM_FUNC_QUALIFIER size_t hash<cac::vec<3, T, Q>>::operator()(cac::vec<3, T, Q> const& v) const
	{
		size_t seed = 0;
		hash<T> hasher;
		cac::detail::hash_combine(seed, hasher(v.x));
		cac::detail::hash_combine(seed, hasher(v.y));
		cac::detail::hash_combine(seed, hasher(v.z));
		return seed;
	}

	template<typename T, cac::qualifier Q>
	GLM_FUNC_QUALIFIER size_t hash<cac::vec<4, T, Q>>::operator()(cac::vec<4, T, Q> const& v) const
	{
		size_t seed = 0;
		hash<T> hasher;
		cac::detail::hash_combine(seed, hasher(v.x));
		cac::detail::hash_combine(seed, hasher(v.y));
		cac::detail::hash_combine(seed, hasher(v.z));
		cac::detail::hash_combine(seed, hasher(v.w));
		return seed;
	}

	template<typename T, cac::qualifier Q>
	GLM_FUNC_QUALIFIER size_t hash<cac::tquat<T, Q>>::operator()(cac::tquat<T,Q> const& q) const
	{
		size_t seed = 0;
		hash<T> hasher;
		cac::detail::hash_combine(seed, hasher(q.x));
		cac::detail::hash_combine(seed, hasher(q.y));
		cac::detail::hash_combine(seed, hasher(q.z));
		cac::detail::hash_combine(seed, hasher(q.w));
		return seed;
	}

	template<typename T, cac::qualifier Q>
	GLM_FUNC_QUALIFIER size_t hash<cac::tdualquat<T, Q>>::operator()(cac::tdualquat<T, Q> const& q) const
	{
		size_t seed = 0;
		hash<cac::tquat<T, Q>> hasher;
		cac::detail::hash_combine(seed, hasher(q.real));
		cac::detail::hash_combine(seed, hasher(q.dual));
		return seed;
	}

	template<typename T, cac::qualifier Q>
	GLM_FUNC_QUALIFIER size_t hash<cac::mat<2, 2, T, Q>>::operator()(cac::mat<2, 2, T, Q> const& m) const
	{
		size_t seed = 0;
		hash<cac::vec<2, T, Q>> hasher;
		cac::detail::hash_combine(seed, hasher(m[0]));
		cac::detail::hash_combine(seed, hasher(m[1]));
		return seed;
	}

	template<typename T, cac::qualifier Q>
	GLM_FUNC_QUALIFIER size_t hash<cac::mat<2, 3, T, Q>>::operator()(cac::mat<2, 3, T, Q> const& m) const
	{
		size_t seed = 0;
		hash<cac::vec<3, T, Q>> hasher;
		cac::detail::hash_combine(seed, hasher(m[0]));
		cac::detail::hash_combine(seed, hasher(m[1]));
		return seed;
	}

	template<typename T, cac::qualifier Q>
	GLM_FUNC_QUALIFIER size_t hash<cac::mat<2, 4, T, Q>>::operator()(cac::mat<2, 4, T, Q> const& m) const
	{
		size_t seed = 0;
		hash<cac::vec<4, T, Q>> hasher;
		cac::detail::hash_combine(seed, hasher(m[0]));
		cac::detail::hash_combine(seed, hasher(m[1]));
		return seed;
	}

	template<typename T, cac::qualifier Q>
	GLM_FUNC_QUALIFIER size_t hash<cac::mat<3, 2, T, Q>>::operator()(cac::mat<3, 2, T, Q> const& m) const
	{
		size_t seed = 0;
		hash<cac::vec<2, T, Q>> hasher;
		cac::detail::hash_combine(seed, hasher(m[0]));
		cac::detail::hash_combine(seed, hasher(m[1]));
		cac::detail::hash_combine(seed, hasher(m[2]));
		return seed;
	}

	template<typename T, cac::qualifier Q>
	GLM_FUNC_QUALIFIER size_t hash<cac::mat<3, 3, T, Q>>::operator()(cac::mat<3, 3, T, Q> const& m) const
	{
		size_t seed = 0;
		hash<cac::vec<3, T, Q>> hasher;
		cac::detail::hash_combine(seed, hasher(m[0]));
		cac::detail::hash_combine(seed, hasher(m[1]));
		cac::detail::hash_combine(seed, hasher(m[2]));
		return seed;
	}

	template<typename T, cac::qualifier Q>
	GLM_FUNC_QUALIFIER size_t hash<cac::mat<3, 4, T, Q>>::operator()(cac::mat<3, 4, T, Q> const& m) const
	{
		size_t seed = 0;
		hash<cac::vec<4, T, Q>> hasher;
		cac::detail::hash_combine(seed, hasher(m[0]));
		cac::detail::hash_combine(seed, hasher(m[1]));
		cac::detail::hash_combine(seed, hasher(m[2]));
		return seed;
	}

	template<typename T, cac::qualifier Q>
	GLM_FUNC_QUALIFIER size_t hash<cac::mat<4, 2, T,Q>>::operator()(cac::mat<4, 2, T,Q> const& m) const
	{
		size_t seed = 0;
		hash<cac::vec<2, T, Q>> hasher;
		cac::detail::hash_combine(seed, hasher(m[0]));
		cac::detail::hash_combine(seed, hasher(m[1]));
		cac::detail::hash_combine(seed, hasher(m[2]));
		cac::detail::hash_combine(seed, hasher(m[3]));
		return seed;
	}

	template<typename T, cac::qualifier Q>
	GLM_FUNC_QUALIFIER size_t hash<cac::mat<4, 3, T,Q>>::operator()(cac::mat<4, 3, T,Q> const& m) const
	{
		size_t seed = 0;
		hash<cac::vec<3, T, Q>> hasher;
		cac::detail::hash_combine(seed, hasher(m[0]));
		cac::detail::hash_combine(seed, hasher(m[1]));
		cac::detail::hash_combine(seed, hasher(m[2]));
		cac::detail::hash_combine(seed, hasher(m[3]));
		return seed;
	}

	template<typename T, cac::qualifier Q>
	GLM_FUNC_QUALIFIER size_t hash<cac::mat<4, 4, T,Q>>::operator()(cac::mat<4, 4, T, Q> const& m) const
	{
		size_t seed = 0;
		hash<cac::vec<4, T, Q>> hasher;
		cac::detail::hash_combine(seed, hasher(m[0]));
		cac::detail::hash_combine(seed, hasher(m[1]));
		cac::detail::hash_combine(seed, hasher(m[2]));
		cac::detail::hash_combine(seed, hasher(m[3]));
		return seed;
	}
}
