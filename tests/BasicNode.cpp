#include "TestCommon.h"

using LinkedList::Node;
using Tests::Result;

template<typename T>
void PrintNode(Node<T>* node)
{
	std::cout << "\nData: " << node->data << "\n";

	if (node->prev != nullptr)
	{
		std::cout << "Prev: " << node->prev << "\n";
	}

	if (node->next != nullptr)
	{
		std::cout << "Next: " << node->next << "\n";
	}
}

int main(UNUSED int argc, UNUSED char** argv)
{
	auto* first  = new Node<f32>();
	auto* second = new Node<f32>();
	auto* third  = new Node<f32>();

	*first  = {PI,     nullptr, second };
	*second = {69.0f,  first,   third  };
	*third  = {420.0f, second,  nullptr};

	PrintNode(first);
	PrintNode(second);
	PrintNode(third);

	delete first;
	delete second;
	delete third;

	return Result::Success;
}