#include "SinglyLinkedList.h"

SinglyLinkedList::SinglyLinkedList()
{}

void SinglyLinkedList::AddNode(int value, int position, ErrorCode& err)
{
	if (position < 0 && position > _size - 1)
	{
		err = INVALID_INPUT_PARAM;
		return;
	}

	auto& prevNode = GetNode(position - 1, err);
	auto& postNode = GetNode(position, err);

	if (!prevNode)
	{
		_head = std::make_shared<Node>(value);
	}
	else
	{
		auto newNode = std::make_shared<Node>(value);
		prevNode->ptr = newNode;
		newNode->ptr = postNode;
	}
	_size++;
}

std::shared_ptr<Node> SinglyLinkedList::GetNode(int position, ErrorCode& err)
{
	err = OK;
	if (_size == 0)
	{
		err = EMPTY_LIST;
		return nullptr;
	}

	if (position >= _size)
	{
		err = OUT_OF_BOUND;
		return nullptr;
	}

	auto tmpNode = _head;

	for (auto i = 0; i < position; i++)
	{
		tmpNode = NextNode(tmpNode);
	}

	return tmpNode;
}

std::shared_ptr<Node> SinglyLinkedList::NextNode(const std::shared_ptr<Node>& node)
{
	return node->ptr;
}

int SinglyLinkedList::Size()
{
	return _size;
}