#include "gtest/gtest.h"
#include "SinglyLinkedList.h"

TEST(SingleLinkedList, SimpleTest)
{
	SinglyLinkedList list;
	list.Size();
	list.Add();
	ASSERT_TRUE(true == true);
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}