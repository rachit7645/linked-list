#include "TestCommon.h"

using LinkedList::Node;
using Tests::Result;

// TODO: Fix this test

int main(UNUSED int argc, UNUSED char** argv)
{
	auto* first  = new Node<f32>();
	auto* second = new Node<f32>();
	auto* third  = new Node<f32>();
	auto* fourth = new Node<f32>();

	*first  = {PI,       nullptr, second };
	*second = {69.0f,    first,   third  };
	*third  = {420.0f,   second,  fourth };
	*fourth = {69420.0f, third,   nullptr};

	auto* current = first;
	for (auto i = current->rbegin(); i != current->rend(); --current)
	{
		auto node = *i;
		Tests::PrintNode(&node);
	}

	delete first;
	delete second;
	delete third;

	return Result::Success;
}
