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

// append()
TEST_F(PreBuiltSinglyLinkedList, GivenAPreBuiltList_WhenAppendingValue_ExpectCorrectSizeAndContent){
    preBuiltList.append(4);
    EXPECT_EQ(preBuiltList.size(), 4);
    EXPECT_EQ(preBuiltList[3], 4);
}

TEST(AppendTest, GivenEmptyLinkedList_WhenAppendingValue_ExpectCorrectSizeAndContent){
    Singly<int> list;
    list.append(1);
    EXPECT_EQ(list.size(), 1);
    EXPECT_EQ(list[0], 1);
}

// size()
TEST_F(PreBuiltSinglyLinkedList, GivenAPreBuiltList_WhenCheckingSize_ExpectCorrectValue){
    EXPECT_EQ(preBuiltList.size(), 3);
}

TEST(ListSizeTest, GivenAnEmptyList_WhenCheckingSize_ExpectCorrectValue){
    Singly<int> list;
    EXPECT_EQ(list.size(), 0);
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
    preBuiltList.remove(2);
    EXPECT_EQ(preBuiltList.size(), 2);
}

TEST_F(PreBuiltSinglyLinkedList, GivenAPreBuiltList_WhenItemtoRemoveisInvalid_ExpectCorrectSize){
    preBuiltList.remove(4);
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
