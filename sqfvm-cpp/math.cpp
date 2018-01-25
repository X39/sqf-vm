#include "full.h"
#include "compiletime.h"
#include <cmath>
#include <random>
using namespace sqf;
namespace
{
	value_s plus_scalar_scalar(const virtualmachine* vm, value_s left, value_s right)
	{
		return std::make_shared<value>((left->as_double()) + (right->as_double()));
	}
	value_s minus_scalar_scalar(const virtualmachine* vm, value_s left, value_s right)
	{
		return std::make_shared<value>((left->as_double()) - (right->as_double()));
	}
	value_s multiply_scalar_scalar(const virtualmachine* vm, value_s left, value_s right)
	{
		return std::make_shared<value>((left->as_double()) * (right->as_double()));
	}
	value_s divide_scalar_scalar(const virtualmachine* vm, value_s left, value_s right)
	{
		auto r = (right->as_double());
		if (r == 0)
			return std::make_shared<value>(0);
		return std::make_shared<value>((left->as_double()) / r);
	}
	value_s abs_scalar(const virtualmachine* vm, value_s right)
	{
		auto r = right->as_double();
	}
	value_s atan2_scalar_scalar(const virtualmachine* vm, value_s left, value_s right)
	{
		return std::make_shared<value>(std::atan2(left->as_double(), right->as_double()));
	}
	value_s deg_scalar(const virtualmachine* vm, value_s right)
	{
		return std::make_shared<value>(right->as_double() * (180 / compiletime::pi()));
	}
	value_s log_scalar(const virtualmachine* vm, value_s right)
	{
		return std::make_shared<value>(std::log10(right->as_double()));
	}
	value_s pi_(const virtualmachine* vm)
	{
		return std::make_shared<value>(compiletime::pi());
	}
	value_s sin_scalar(const virtualmachine* vm, value_s right)
	{
		return std::make_shared<value>(std::sin(right->as_double()));
	}
	value_s acos_scalar(const virtualmachine* vm, value_s right)
	{
		return std::make_shared<value>(std::acos(right->as_double()));
	}
	value_s exp_scalar(const virtualmachine* vm, value_s right)
	{
		return std::make_shared<value>(std::exp(right->as_double()));
	}
	value_s min_scalar_scalar(const virtualmachine* vm, value_s left, value_s right)
	{
		auto l = left->as_double();
		auto r = right->as_double();
		return std::make_shared<value>(l < r ? l : r);
	}
	value_s rad_scalar(const virtualmachine* vm, value_s right)
	{
		return std::make_shared<value>(right->as_double() * (compiletime::pi() / 180));
	}
	value_s sqrt_scalar(const virtualmachine* vm, value_s right)
	{
		return std::make_shared<value>(std::sqrt(right->as_double()));
	}
	value_s tan_scalar(const virtualmachine* vm, value_s right)
	{
		return std::make_shared<value>(std::tan(right->as_double()));
	}
	value_s random_scalar(const virtualmachine* vm, value_s right)
	{
		return std::make_shared<value>(compiletime::rand(right->as_double()));
	}
}

void sqf::commandmap::initmath(void)
{
	add(unary(L"abs", sqf::type::SCALAR, L"Absolute value of a real number", abs_scalar));
	add(binary(7, L"atan2", sqf::type::SCALAR, sqf::type::SCALAR, L"ArcTangent of x/y. Used to determine the angle of a vector [x,y]. Result in Degrees between -180 and 180. Note that this command can handle y being 0, unlike when using atan, and will return 90", atan2_scalar_scalar));
	add(unary(L"deg", sqf::type::SCALAR, L"Convert a number from Radians to Degrees.", deg_scalar));
	add(unary(L"log", sqf::type::SCALAR, L"Base-10 logarithm of x.", log_scalar));
	add(nular(L"pi", L"The value of PI.", pi_));
	add(unary(L"sin", sqf::type::SCALAR, L"Sine of x, argument in Degrees.", sin_scalar));
	add(unary(L"acos", sqf::type::SCALAR, L"ArcCosine of a number, result in Degrees.", acos_scalar));
	add(unary(L"exp", sqf::type::SCALAR, L"Let x be a number, then exp (x) is equal to e to the power of x (or e^x).", exp_scalar));
	add(unary(L"rad", sqf::type::SCALAR, L"Convert x from Degrees to Radians. 360 degrees is equal to 2 multiplied with pi.", rad_scalar));
	add(unary(L"sqrt", sqf::type::SCALAR, L"Returns square root of x.", rad_scalar));
	add(unary(L"tan", sqf::type::SCALAR, L"Tangent of x, argument in Degrees.", tan_scalar));
	add(unary(L"random", sqf::type::SCALAR, L"Random real (floating point) value from 0 (inclusive) to x (not inclusive).", random_scalar));
	add(binary(6, L"+", sqf::type::SCALAR, sqf::type::SCALAR, L"The smaller of a,b", min_scalar_scalar));
	add(binary(6, L"+", sqf::type::SCALAR, sqf::type::SCALAR, L"b added to a.", plus_scalar_scalar));
	add(binary(6, L"-", sqf::type::SCALAR, sqf::type::SCALAR, L"Subtracts b from a.", minus_scalar_scalar));
	add(binary(7, L"*", sqf::type::SCALAR, sqf::type::SCALAR, L"Returns the value of a multiplied by b.", multiply_scalar_scalar));
	add(binary(7, L"/", sqf::type::SCALAR, sqf::type::SCALAR, L"a divided by b. Division by 0 throws \"Division by zero\" error, however script doesn't stop and the result of such division is assumed to be 0.", divide_scalar_scalar));
}