#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <memory>

#include <ErrorCode.h>

struct Node
{
	Node(int value) :
		value(value)
	{}
		
	int value;
	std::shared_ptr<Node> ptr = nullptr;
};

class SinglyLinkedList
{
public:
	SinglyLinkedList();

	void AddNode(int value, int position, ErrorCode& err);
	void RemoveNode(int position, ErrorCode& err);
	std::shared_ptr<Node> GetNode(int position);

	void PrintList();
	
	int Size();

private:
	std::shared_ptr<Node> NextNode(const std::shared_ptr<Node>& node);
private:
	int _size = 0;
	std::shared_ptr<Node> _head = nullptr;
};

#endif // SINGLY_LINKED_LIST_H