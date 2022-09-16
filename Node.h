#ifndef NODE_H
#define NODE_H

namespace LinkedList
{
	template<typename T>
	struct Node
	{
		T     data;
		Node* prev;
		Node* next;
	};
}

#endif