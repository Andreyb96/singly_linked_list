#include <SinglyLinkedList.h>
#include <cassert>

int main()
{
	ErrorCode err = OK;

	{ // AddNode UT
		SinglyLinkedList myList;
		myList.AddNode(1, 0, err);
		assert(myList.GetNode(0)->value == 1);
		assert(err == OK);
		err = OK;
		myList.AddNode(2, 1, err);
		assert(myList.GetNode(1)->value == 2);
		assert(err == OK);
		myList.AddNode(9, 2, err);
		assert(myList.GetNode(2)->value == 9);
		assert(err == OK);
		myList.AddNode(10, 3, err);
		assert(myList.GetNode(3)->value == 10);
		assert(err == OK);
		myList.AddNode(3, 2, err);
		assert(myList.GetNode(2)->value == 3);
		assert(err == OK);
		myList.AddNode(4, 3, err);
		assert(myList.GetNode(3)->value == 4);
		assert(err == OK);
		myList.AddNode(7, 4, err);
		assert(myList.GetNode(4)->value == 7);
		assert(err == OK);
		myList.AddNode(8, 5, err);
		assert(myList.GetNode(5)->value == 8);
		assert(err == OK);
		myList.AddNode(5, 4, err);
		assert(myList.GetNode(4)->value == 5);
		assert(err == OK);
		myList.AddNode(6, 5, err);
		assert(myList.GetNode(5)->value == 6);
		assert(err == OK);
		assert(myList.Size() == 10);

		for (auto i = 0; i < 10; i++)
		{
			assert(myList.GetNode(i)->value == i + 1);
			assert(err == OK);
		}
		myList.Clear();
	}

	{ // RemoveNode UT
		SinglyLinkedList myList;
		for (auto i = 0; i < 10; i++)
		{
			myList.AddNode(i + 1, i, err);
			assert(myList.Size() == i + 1);
			assert(err == OK);
		}

		for (auto i = 9; i > -1; i--)
		{
			myList.RemoveNode(i, err);
			assert(myList.Size() == i);
			assert(err == OK);
		}
		myList.Clear();
	}

	{ // Find UT
		SinglyLinkedList myList;
		for (auto i = 0; i < 10; i++)
		{
			myList.AddNode(i + 1, i, err);
			assert(myList.Size() == i + 1);
			assert(err == OK);
			assert(myList.Find(i + 1, err) != nullptr);
			assert(err == OK);
		}

		assert(myList.Find(1, err) != nullptr);
		assert(myList.Find(5, err) != nullptr);
		assert(myList.Find(10, err) != nullptr);
		assert(myList.Find(-5, err) == nullptr);
		assert(myList.Find(15, err) == nullptr);
		myList.Clear();
	}

	{ // GetIndex UT
		SinglyLinkedList myList;

		assert(myList.GetIndex(1, err) == -1);
		assert(err == EMPTY_LIST);

		for (auto i = 0; i < 10; i++)
		{
			myList.AddNode(i + 1, i, err);
			assert(myList.Size() == i + 1);
			assert(err == OK);
			assert(myList.Find(i + 1, err) != nullptr);
			assert(err == OK);
		}

		assert(myList.GetIndex(1, err) == 0);
		assert(err == OK);
		assert(myList.GetIndex(5, err) == 4);
		assert(err == OK);
		assert(myList.GetIndex(10, err) == 9);
		assert(err == OK);
		assert(myList.GetIndex(-5, err) == -1);
		assert(err == OK);
		assert(myList.GetIndex(15, err) == -1);
		assert(err == OK);
		myList.Clear();
	}

	return 0;
}