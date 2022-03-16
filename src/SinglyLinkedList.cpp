#include "SinglyLinkedList.h"

SinglyLinkedList::SinglyLinkedList()
{}

void SinglyLinkedList::AddNode(int value, int position, ErrorCode& err)
{
	err = OK;

	if (position < 0)
	{
		err = INVALID_INPUT_PARAM;
		return;
	}

	if (position >= _size)
	{
		position = _size;
	}

	auto& prevNode = GetNode(position - 1);
	auto& postNode = GetNode(position);
	auto newNode = std::make_shared<Node>(value);

	if (prevNode == nullptr)
	{
		_head = std::make_shared<Node>(value);
		_head->ptr = postNode;
	}
	else if (postNode == nullptr)
	{
		prevNode->ptr = newNode;
	} 
	else
	{
		prevNode->ptr = newNode;
		newNode->ptr = postNode;
	}
	_size++;
}

void SinglyLinkedList::RemoveNode(int position, ErrorCode& err)
{
	err = OK;
	if (_size == 0)
	{
		err = EMPTY_LIST;
		return;
	}

	if (position < 0)
	{
		err = INVALID_INPUT_PARAM;
		return;
	}

	if (position >= _size)
	{
		err = OUT_OF_BOUND;
		return;
	}

	if (position == 0)
	{
		_head = GetNode(position + 1);
	}
	else if (position == _size - 1)
	{
		auto& prevNode = GetNode(position - 1);
		prevNode->ptr = nullptr;
	}
	else
	{
		auto& prevNode = GetNode(position - 1);
		auto& postNode = GetNode(position + 1);
		prevNode->ptr = postNode;
	}


	_size--;
}

std::shared_ptr<Node> SinglyLinkedList::GetNode(int position)
{
	if (position < 0)
	{
		return nullptr;
	}

	if (position >= _size)
	{
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