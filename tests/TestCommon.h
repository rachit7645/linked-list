#ifndef TEST_COMMON_H
#define TEST_COMMON_H

#ifdef __CLION_IDE__
#define UNUSED [[maybe_unused]]
#else
#define UNUSED __attribute__((unused))
#endif

using f32 = float;
using f64 = double;

constexpr f64 PI = 22.0 / 7.0;

namespace Tests
{
	enum Result : int
	{
		Success = 0,
		Failure = -1
	};
}

#endif
