#include "../List.h"
#include "TestCommon.h"

using LinkedList::List;
using Tests::Result;

int main(UNUSED int argc, UNUSED char** argv)
{
	List<f32> list;

	list.emplace_back(PI);
	list.emplace_back(69.0f);
	list.emplace_back(420.0f);
	list.emplace_back(69420.0f);

	for (auto i = list.rbegin(); i != list.rend(); --i)
	{
		auto node = *i;
		Tests::PrintNode(&node);
	}

	return Result::Success;
}
