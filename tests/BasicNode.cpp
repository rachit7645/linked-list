#include "TestCommon.h"

using LinkedList::Node;
using Tests::Result;

int main(UNUSED int argc, UNUSED char** argv)
{
	auto* first  = new Node<f32>();
	auto* second = new Node<f32>();
	auto* third  = new Node<f32>();

	*first  = {PI,     nullptr, second };
	*second = {69.0f,  first,   third  };
	*third  = {420.0f, second,  nullptr};

	Tests::PrintNode(first);
	Tests::PrintNode(second);
	Tests::PrintNode(third);

	delete first;
	delete second;
	delete third;

	return Result::Success;
}