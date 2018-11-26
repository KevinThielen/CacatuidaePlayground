/// @ref gtx_projection

namespace cac
{
	template<typename genType>
	GLM_FUNC_QUALIFIER genType proj(genType const& x, genType const& Normal)
	{
		return cac::dot(x, Normal) / cac::dot(Normal, Normal) * Normal;
	}
}//namespace cac
