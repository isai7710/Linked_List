#include <gtest/gtest.h>
#include <string>
#include "../src/Singly.h"

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

TEST(SLLIsEmpty, GivenANonEmptyList_WhenExecutingIsEmptyFunction_ExpectFalse){
    Singly<int> list;
    list.append(1);

    EXPECT_EQ(list.is_empty(), false);
}

TEST(SLLPopBack, GivenAListWith2Values_WhenPopBackisExecuted_ExpectCorrectReturnValueandSize){
    Singly<int> list;
    list.append(1);
    list.append(2);

    EXPECT_EQ(list.pop_back(), 2);
    EXPECT_EQ(list.size(), 1);
}

TEST(SLLPopFront, GivenAListWith2Values_WhenPopFrontisExecuted_ExpectCorrectReturnValueandSize){
    Singly<int> list;
    list.append(1);
    list.append(2);

    EXPECT_EQ(list.pop_front(), 1);
    EXPECT_EQ(list.size(), 1);
}

TEST_F(PreBuiltSinglyLinkedList, GivenAPreBuiltList_WhenAppendingValue_ExpectCorrectSize){
    preBuiltList.append(4);
    EXPECT_EQ(preBuiltList.size(), 4);
}

TEST_F(PreBuiltSinglyLinkedList, GivenAPreBuiltList_WhenCheckingSize_ExpectCorrectValue){
    EXPECT_EQ(preBuiltList.size(), 3);
}

TEST_F(PreBuiltSinglyLinkedList, GivenAPreBuiltList_WhenExecutingClearAll_ExpectIsEmptyToBeTrue){
    preBuiltList.clear_all();
    EXPECT_EQ(preBuiltList.is_empty(), true);
}

TEST_F(PreBuiltSinglyLinkedList, GivenAPreBuiltList_WhenBackIsPopped_ExpectCorrectReturnValueandSize){
    EXPECT_EQ(preBuiltList.pop_back(), 3);
    EXPECT_EQ(preBuiltList.size(), 2);
}

TEST_F(PreBuiltSinglyLinkedList, GivenAPreBuiltList_WhenFrontIsPopped_ExpectCorrectReturnValueandSize){
    EXPECT_EQ(preBuiltList.pop_front(), 1);
    EXPECT_EQ(preBuiltList.size(), 2);
}

TEST_F(PreBuiltSinglyLinkedList, GivenAPreBuiltList_WhenItemtoRemoveisValid_ExpectCorrectSize){
    preBuiltList.remove_item(2);
    EXPECT_EQ(preBuiltList.size(), 2);
}

TEST_F(PreBuiltSinglyLinkedList, GivenAPreBuiltList_WhenItemtoRemoveisInvalid_ExpectCorrectSize){
    preBuiltList.remove_item(4);
    EXPECT_EQ(preBuiltList.size(), 3);
}

TEST_F(PreBuiltSinglyLinkedList, GivenAPreBuiltList_WhenTailRemoved_ExpectCorrectSize){
    preBuiltList.remove_tail();
    EXPECT_EQ(preBuiltList.size(), 2);
}

TEST_F(PreBuiltSinglyLinkedList, GivenAPreBuiltList_WhenCheckingIfContainsValidItem_ExpectToReturnTrue){
    EXPECT_EQ(preBuiltList.contains(2), true);
}

TEST_F(PreBuiltSinglyLinkedList, GivenAPreBuiltList_WhenCheckingIfContainsInvalidItem_ExpectToReturnFalse){
    EXPECT_EQ(preBuiltList.contains(7), false);
}

TEST_F(PreBuiltSinglyLinkedList, GivenAPreBuiltList_WhenCheckingOccurrenceOfValue_ExpectCorrectCount){
    EXPECT_EQ(preBuiltList.count(1), 1);
}

TEST_F(PreBuiltSinglyLinkedList, GivenAPreBuiltList_WhenAppendingValueandCheckingOccurrenceOfValue_ExpectCorrectCount){
    preBuiltList.append(1);
    EXPECT_EQ(preBuiltList.count(1), 2);
}

TEST_F(PreBuiltSinglyLinkedList, GivenAPreBuiltList_WhenInsertingAfterValidItem_ExpectCorrectSize){
    preBuiltList.insert_after(2, 11);
    EXPECT_EQ(preBuiltList.size(), 4);
}

TEST_F(PreBuiltSinglyLinkedList, GivenAPreBuiltList_WhenInsertingAfterInvalidItem_ExpectCorrectSize){
    preBuiltList.insert_after(4, 11);
    EXPECT_EQ(preBuiltList.size(), 3);
}

TEST_F(PreBuiltSinglyLinkedList, GivenAPreBuiltList_WhenInsertingBeforeValidItem_ExpectCorrectSize){
    preBuiltList.insert_before(2, 11);
    EXPECT_EQ(preBuiltList.size(), 4);
}

TEST_F(PreBuiltSinglyLinkedList, GivenAPreBuiltList_WhenInsertingBeforeInvalidItem_ExpectCorrectSize){
    preBuiltList.insert_before(4, 11);
    EXPECT_EQ(preBuiltList.size(), 3);
}

TEST_F(PreBuiltSinglyLinkedList, GivenAPreBuiltList_WhenConvertingtoString_ExpectCorrectOrderandMatchingString){
    EXPECT_EQ(preBuiltList.to_string(), "1 2 3");
}

TEST_F(PreBuiltSinglyLinkedList, GivenAPreBuiltList_WhenAppendingValueandConvertingtoString_ExpectCorrectOrderandMatchingString){
    preBuiltList.append(5);
    EXPECT_EQ(preBuiltList.to_string(), "1 2 3 5");
}

TEST_F(PreBuiltSinglyLinkedList, GivenAPreBuiltList_WhenInsertingAfterValidItemAndConvertingtoString_ExpectCorrectOrderandMatchingString){
    preBuiltList.insert_after(2, 3);
    EXPECT_EQ(preBuiltList.to_string(), "1 2 3 3");
}

TEST_F(PreBuiltSinglyLinkedList, GivenAPreBuiltList_WhenInsertingBeforeValidItemAndConvertingtoString_ExpectCorrectOrderandMatchingString){
    preBuiltList.insert_before(2, 3);
    EXPECT_EQ(preBuiltList.to_string(), "1 3 2 3");
}

TEST_F(PreBuiltSinglyLinkedList, GivenAPreBuiltList_WhenAccessingElementByIndex_ExpectCorrectAccessedItem){
    EXPECT_EQ(preBuiltList[1], 2);
}

TEST_F(PreBuiltSinglyLinkedList, GivenAPreBuiltList_WhenAssigningNewValuetoElementByIndex_ExpectCorrectOrderandSize){
    preBuiltList[0] = 2;
    EXPECT_EQ(preBuiltList.to_string(), "2 2 3");
    EXPECT_EQ(preBuiltList.size(), 3);
}