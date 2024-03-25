# Linked_List
This is a Linked List library I've developed to get a better grasp at CMake, Test Driven Development, and the Linked List structure in general (singly and doubly). It was written in a WSL environment on Visual Studio Code using CMake tools. \
The src directory contains the source code for the Singly and Doubly linked list classes, which are just .h files. Although not shown in this repository (for the sake of simplicity) there must be a directory with the google test framework copied from the appropriate github repository, so that the unit tests in the linked_list_unittest directory work properly. The link to that Gtest repository is: https://github.com/google/googletest

## Singly Linked List Class

The Singly Linked List class provides a simple implementation of a singly linked list data structure in C++. The key points and functions of the Singly Linked List class are summarized below:

### Key Points:

1. The condition `!head` returns `true` if `head` points to `nullptr`, indicating that the list is empty. In this case, the item to append becomes the new head of the list.

2. Finding the second-to-last node is necessary for operations like `pop_back` and `remove_tail`. This ensures that upon removal of the last node, the second-to-last node correctly points to `nullptr`.

3. The `remove` function's algorithm involves iterating through the list to find and remove a specific node. It checks if the end of the list has been reached using the `current->next` expression. If not, it checks if the current node is the one to remove. If found, it removes the node; otherwise, it continues traversing the list until the end is reached.

### Function Summaries:

1. **append(const T &item_to_append)**: Appends a new node with the specified item to the end of the list. If the list is empty, the new node becomes the head.

2. **size() const**: Returns the number of nodes in the list by traversing the list and counting each node.

3. **is_empty() const**: Returns `true` if the list is empty (i.e., `head` is `nullptr`), otherwise `false`.

4. **pop_back()**: Removes and returns the last node in the list. Handles cases where the list is empty or contains only one node.

5. **pop_front()**: Removes and returns the first node in the list.

6. **remove_item(const T &item_to_remove)**: Removes the node containing the specified item from the list if found.

7. **remove_tail()**: Removes the last node in the list.

8. **contains(const T &value) const**: Checks if the specified value is present in the list.

9. **count(const T &value) const**: Counts the number of occurrences of a specific value in the list.

10. **insert_after(const T &value_to_insert_after, const T &value_to_insert)**: Inserts a new node with the given value after the specified value in the list.

11. **insert_before(const T &value_to_insert_before, const T &value_to_insert)**: Inserts a new node with the given value before the specified value in the list.

12. **to_string()**: Converts the items of the list into a string representation.

13. **operator[](int index)**: Accesses elements in the list by index.

Each function provides specific functionality for manipulating and querying the linked list, allowing for flexible usage and efficient management of data.
