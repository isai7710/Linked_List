#include <gtest/gtest.h>
#include "Singly.h"

// SLL = Singly Linked List
class PreBuiltSinglyLinkedList: public testing::Test{
    public:
        PreBuiltSinglyLinkedList(){
            preBuiltList.append(1);
            preBuiltList.append(2);
            preBuiltList.append(3);
        }
    protected:
    Singly<int> preBuiltList;
};

TEST(SLLAppendandSize, GivenAListWithOnly1AppendedValue_ReturnCorrectSize){
    Singly<int> list;
    list.append(1);

    EXPECT_EQ(list.size(), 1);
}

TEST(SLLAppendAndSize, GivenAListWith2AppendedValues_ReturnCorrectSize){
    Singly<int> list;
    list.append(1);
    list.append(2);

    EXPECT_EQ(list.size(), 2);
}

TEST(SLLIsEmpty, GivenAnEmptyList_WhenExecutingIsEmptyFunction_ExpectTrue){
    Singly<int> list;

    EXPECT_EQ(list.is_empty(), true);
}

TEST_F(PreBuiltSinglyLinkedList, GivenAPreBuiltList_WhenCheckingSize_ExpectCorrectValue){
    EXPECT_EQ(preBuiltList.size(), 3);
}

TEST_F(PreBuiltSinglyLinkedList, GivenAPreBuiltList_WhenExecutingClearAll_ExpectIsEmptyToBeTrue){
    preBuiltList.clear_all();
    EXPECT_EQ(preBuiltList.is_empty(), true);
}

TEST_F(PreBuiltSinglyLinkedList, GivenAPreBuiltList_ExpectCorrectSize){
    EXPECT_EQ(preBuiltList.size(), 3);
}

TEST_F(PreBuiltSinglyLinkedList, GivenAListWith3AppendedValues_WhenItemRemoved_ExpectCorrectSize){
    preBuiltList.remove_item(2);
    EXPECT_EQ(preBuiltList.size(), 2);
}

TEST_F(PreBuiltSinglyLinkedList, GivenAPreBuiltList_WhenItemToRemoveIsNotValid_ExpectCorrectSize){
    preBuiltList.remove_item(4);
    EXPECT_EQ(preBuiltList.size(), 3);
}

TEST_F(PreBuiltSinglyLinkedList, GivenAPreBuiltList_WhenTailRemoved_ExpectCorrectSize){
    preBuiltList.remove_tail();
    EXPECT_EQ(preBuiltList.size(), 2);
}

TEST_F(PreBuiltSinglyLinkedList, GivenAPreBuiltList_WhenFrontIsPopped_ExpectCorrectReturnValueandSize){
    EXPECT_EQ(preBuiltList.pop_front(), 1);
    EXPECT_EQ(preBuiltList.size(), 2);
}

TEST_F(PreBuiltSinglyLinkedList, GivenAPreBuiltList_WhenBackIsPopped_ExpectCorrectReturnValueandSize){
    EXPECT_EQ(preBuiltList.pop_back(), 3);
    EXPECT_EQ(preBuiltList.size(), 2);
}

TEST(SLLPopBack, GivenAListWith2Values_WhenBackIsPopped_ExpectCorrectReturnValueandSize){
    Singly<int> list;
    list.append(1);
    list.append(2);

    EXPECT_EQ(list.pop_back(), 2);
    EXPECT_EQ(list.size(), 1);
}

TEST_F(PreBuiltSinglyLinkedList, GivenAPreBuiltList_WhenCheckingIfContainsValidItem_ExpectToReturnTrue){
    EXPECT_EQ(preBuiltList.contains(2), true);
}

TEST_F(PreBuiltSinglyLinkedList, GivenAPreBuiltList_WhenCheckingIfContainsAnotherValidItem_ExpectToReturnTrue){
    EXPECT_EQ(preBuiltList.contains(1), true);
}

TEST_F(PreBuiltSinglyLinkedList, GivenAPreBuiltList_WhenCheckingIfContainsInvalidItem_ExpectToReturnFalse){
    EXPECT_EQ(preBuiltList.contains(7), false);
}