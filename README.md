# Linked_List
This is a Linked List library I've developed to get a better grasp at CMake, Test Driven Development, and the Linked List structure in general (singly and doubly). It was written in a WSL environment on Visual Studio Code using CMake tools. \
The src directory contains the source code for the Singly and Doubly linked list classes, which are just .h files. Although not shown in this repository (for the sake of simplicity) there must be a directory with the google test framework copied from the appropriate github repository, so that the unit tests in the unit_test directory work properly. The link to that gtest repository is: https://github.com/google/googletest

## Singly Linked List Class

The first linked list data structure to implement was the singly linked list.

### Key Points:
1. Nodes are the building blocks for linked lists. Each node in this singly linked list contains two main components: data, which holds the actual information to be stored, and one pointer (hence the 'singly') called next, which references the next node in the sequence. These pointers can be thought of as the single "links" of the linked list.

2. The condition `!head` returns `true` if `head` points to `nullptr`, indicating that the list is empty. 

3. Finding the second-to-last node is necessary for operations like `pop_back()` and `remove_tail()` and is done so with the `current->next->next` condition. This ensures that upon removal of the last node, the second-to-last node correctly points to `nullptr`.

4. The `remove()` function's algorithm involves iterating through the list to find and remove a specific node. It checks if the end of the list has been reached using the `current->next` expression while also checking if the current node is the one to remove by using the `&&` operator. If found, it removes the node using a temp node pointer; otherwise, it continues traversing the list until the end is reached. In which case the node to remove was not found.

5. The `insert_after()` function points the head towards the item to insert if the list is empty to begin with. If not, then it iterates through the list using a while loop and the `current->next` condition until the item to insert after is found, in which case pointers are arranged to insert the new item in the list. 

6. The  `insert_before()` function contains a little more code, as it needs to check both if the list is empty and if the item to insert before is the head, before iterating through the list to find the item to insert before. 

### Function Summaries:

1. **`append(const T &item_to_append)`**: Appends a new node with the specified item to the end of the list. If the list is empty, the new node becomes the head.

2. **`size() const`**: Returns the number of nodes in the list by returning the list size variable, a O(1) operation as opposed to iterating and counting all items in list, a O(n) operation. The drawback of this faster operation is the need to update the list size variable in all insert and remove functions.

3. **`is_empty() const`**: Returns `true` if the list is empty (i.e., `head` is `nullptr`), otherwise returns `false`.

4. **`pop_back()`**: Removes and returns the last node in the list. Handles cases where the list is empty or contains only one node.

5. **`pop_front()`**: Removes and returns the first node in the list.

6. **`remove(const T &item_to_remove)`**: Removes the node containing the specified item from the list if found.

7. **`remove_tail()`**: Removes the last node in the list.

8. **`contains(const T &item) const`**: Checks if the specified item is present in the list.

9. **`count(const T &item) const`**: Counts the number of occurrences of a specific item in the list.

10. **`insert_after(const T &item_to_insert_after, const T &item_to_insert)`**: Inserts a new node with the given item after the specified item in the list.

11. **`insert_before(const T &item_to_insert_before, const T &item_to_insert)`**: Inserts a new node with the given item before the specified item in the list.

12. **`to_string()`**: Converts the items of the list into a string representation.

13. **`operator[](int index)`**: Accesses elements in the list by index.

I plan on implementing more functions. If you have any feedback, let me konw!