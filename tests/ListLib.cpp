#include "../List.h"
#include "TestCommon.h"

using Tests::Result;

int main(UNUSED int argc, UNUSED char** argv)
{
	auto list = rstd::list<f32>();
	// Insertion functions
	list.push_back(new rstd::node<f32>(69.0f));
	list.emplace_back(420.0f);
	// Front and back
	auto front = list.front();
	auto back  = list.back();
	// iterator
	auto begin       = list.begin();
	auto end         = list.end();
	auto rbegin      = list.rbegin();
	auto rend        = list.rend();
	auto cbegin  = list.cbegin();
	auto cend    = list.cend();
	auto crbegin = list.crbegin();
	auto crend   = list.crend();
	// Insertion/Deletion
	list.erase(list.begin());

	return Result::Success;
}
