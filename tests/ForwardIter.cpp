#include "TestCommon.h"

using LinkedList::Node;
using Tests::Result;

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

	for (auto& i : *first)
	{
		Tests::PrintNode(&i);
	}

	delete first;
	delete second;
	delete third;

	return Result::Success;
}