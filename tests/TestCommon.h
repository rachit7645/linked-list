#ifndef TEST_COMMON_H
#define TEST_COMMON_H

#include <random>
#include <cstddef>

#include "../Node.h"
#include "../List.h"

#ifdef __CLION_IDE__
#define UNUSED [[maybe_unused]]
#else
#define UNUSED __attribute__((unused))
#endif

using f32 = float;
using f64 = double;

using usize = std::size_t;

namespace Tests
{
	enum Result : int
	{
		Success = 0,
		Failure = -1
	};

	// Truly random number between a range
	template<typename T>
	T RandRange(T min, T max)
	{
		std::random_device rd;
		std::seed_seq ss{ rd(), rd(), rd(), rd() };
		static thread_local std::mt19937_64 generator(ss);
		std::uniform_real_distribution<T> distributer(min, max);
		return distributer(generator);
	}

	template<typename T>
	void FillRand(LinkedList::List<T>& list, usize count)
	{
		for (usize i = 0; i < count; ++i)
		{
			list.push_back(new LinkedList::Node<T>(Tests::RandRange(-100.0f, 100.0f)));
		}
	}
}

#endif
