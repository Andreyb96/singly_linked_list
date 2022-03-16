#include "SinglyLinkedList.h"

#include <iostream>

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

void SinglyLinkedList::PrintList()
{
	for (auto i = 0; i < _size; i++)
	{
		auto node = GetNode(i);
		std::cout << "Position: " << i << "; Value: " <<
 node->value << std::endl;
	}
}

std::shared_ptr<Node> SinglyLinkedList::Find(int value, ErrorCode& err)
{
	err = OK;
	if (_size == 0)
	{
		err = EMPTY_LIST;
		return nullptr;
	}
	auto node = _head;

	while (node != nullptr)
	{
		if (node->value == value)
		{
			return node;
		}
		node = NextNode(node);
	}

	return node;
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

void SinglyLinkedList::Clear()
{
	auto& prevNode = _head;
	std::shared_ptr<Node> postNode = nullptr;
	if (_size > 1)
	{
		postNode = NextNode(prevNode);
	}

	while (prevNode != nullptr)
	{
		prevNode->ptr = nullptr;
		prevNode = postNode;
		if (prevNode != nullptr)
		{
			postNode = NextNode(prevNode);
		}
	}

	_size = 0;
}

std::shared_ptr<Node> SinglyLinkedList::NextNode(const std::shared_ptr<Node>& node)
{
	return node->ptr;
}

int SinglyLinkedList::Size()
{
	return _size;
}