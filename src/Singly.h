#ifndef SINGLY_H
#define SINGLY_H

#include <iostream>
#include <string>

template <typename T>
class Singly {
public:
    Singly() : head(nullptr) {}

    ~Singly() { clear_all(); }

    void append(const T &append_item) {
        Node* newNode = new Node(append_item);
        // returns true if head points to null (list is empty), in which case the item will be the head
        if (!head){
            head = newNode;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    int size() const {
        int size = 0;
        Node* current = head;
        while(current){
            current = current->next;
            size++;
        }
        return size;
    } 
    
    bool is_empty() const {
        if(!head) {
            return true;
        }
        return false;
    }
    
    //Remove and return the last element.
    T pop_back(){
        if(!head){
            std::cout << "List is empty" << std::endl;
            return T{};
        }
        if(!head->next){
            T backValue = head->data;
            delete head;
            head = nullptr;
            return backValue;
        }
        // find second to last node
        Node* current = head;
        while(current->next->next){
            current = current->next;
        }
        T backValue = current->next->data;
        Node* temp = current->next;
        current->next = nullptr;
        delete temp;

        return backValue;
    }
    //Remove and return the first element.
    T pop_front(){
        if (!head){
            std::cout << "List is empty" << std::endl;
            return T{};
        }
        Node* nodeToPop = head;
        T frontValue = head->data;
        head = head->next;
        delete nodeToPop;
        return frontValue;
    }
    
    void remove_item(const T &item_to_remove) {
        // returns true if head points to null, in which case list is empty
        if (!head) {
            std::cout << "List is empty"<< std::endl;
            return;
        } 
        // check if first item in list is the item to remove
        if (head->data == item_to_remove) {
            Node* temp = head->next;
            delete head;
            head = temp;
            std::cout << "item removed, twas the first item" << std::endl;
            return;
        }
        //
        Node* current = head;
        Node* temp;
        //draw this out as well but I will try to explain as best I can here
        //first check if we've reached the end of the list with the 'current->next expression' if so,
        //terminate while loop
        //if we haven't reached the end, then check if current's following node is the node to remove, if it is
        //terminate while loop, we've found the node to remove
        while(current->next && current->next->data != item_to_remove){
            current = current->next;
        }
        // if we did find the item to remove (which is current's following node), then current->next returns 
        // true, and so we go in here and remove it using temp
        if (current->next) {
            temp = current->next;
            current->next = current->next->next;
            delete temp;
            std::cout << "item removed" << std::endl;
            return;
        }
        // now if the current pointer has reached the end of the list (current->next returns false), then that  
        // means we did not find the item to remove
        else{
            std::cout<<"item not found"<<std::endl;
            return;
        }

    }
    
    void remove_tail() {
        // the statement !head returns true if head points to null, in which case list is empty
        if (!head){
            std::cout << "List is empty"<< std::endl;
            return;
        } 
        // the statement !head->next returns true if there is only one item in list (draw out what a 
        // single item linked list looks like if you're confused on this)
        if (!head->next){
            delete head;
            head = nullptr;
            return;
        }
        // find second to last node, again, if confusing, draw it out to see process
        Node* current = head;
        while (current->next->next) {
            current = current->next;
        }

        delete current->next;
        current->next = nullptr;
    }

    // Check if a specific value is present in the list.
    bool contains(const T &value) const {
        Node* current = head;
        while(current){
            if(current->data == value){
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // Count the number of occurrences of a specific value in the list.
    int count(const T &value) const {
        if(!head){
            return 0;
        }
        Node *current = head;
        int count = 0;
        while(current){
            if (current->data == value){
                count++;
            }
            current = current->next;
        }
        return count;
    }

    // consider the case if there are multiple of the same item we would like to insert after, how would the function parameters differ and would there be any change to the logic?
    void insert_after(const T &value_to_insert, const T &value_to_insert_after) {
        if (!head) {
            std::cout << "List is empty, value to insert will now be appended as first value in list..." << std::endl;
            append(value_to_insert);
            return;
        }
        Node* current = head;
        while(current){
            if (current->data == value_to_insert_after){
                Node* newNode = new Node(value_to_insert);
                newNode->next = current->next;
                current->next = newNode;
                return;
            }
            current = current->next;
        }
        std::cout << "Item '" << value_to_insert_after << "' not found in the list. Insertion failed." << std::endl;
    }

    void insert_before(const T &value_to_insert, const T &value_to_insert_before) {
        if (!head) {
            std::cout << "List is empty, item to insert will now be appended as first item in list..." << std::endl;
            append(value_to_insert);
            return;
        }
        if (head->data == value_to_insert_before) {
            Node* newNode = new Node(value_to_insert);
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next) {
            if (current->next->data == value_to_insert_before){
                Node* newNode = new Node(value_to_insert);
                newNode->next = current->next;
                current->next = newNode;
                return;
            }
            current = current->next;
        }
        std::cout << "Item '" << value_to_insert_before << "' not found in the list. Insertion failed." << std::endl;
    }

    void print_list() const {
        std::cout << "Your list:\n";
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
    void print_first_item() const {
        if (head) {
            std::cout << "Head points to: " << head->data << std::endl;
        } else {
            std::cout << "Head is null, the list is empty." << std::endl;
        }
    }
    
    // Reverse the order of elements in the list.
    // void reverse() {}
    /*
    TODO:
    T& front() const: Get a reference to the first element in the list.
    T& back() const: Get a reference to the last element in the list.
    T& operator[](int index): Access elements in the list by index.
    void sort(): Sort the elements in the list.
    void remove_duplicates(): Remove duplicate elements from the list.
    Singly<T> copy() const: Create a copy of the list.
    bool equals(const Singly<T> &other) const: Compare two lists for equality.
    */
    
    void clear_all() {
        Node* delete_ptr;
        while(head){
            delete_ptr = head;
            head = head->next;
            delete delete_ptr;
        }
    }
private:
    //----A Node is the building block for a single-linked list
    struct Node
    {
        // Node data
        T data;
        // Pointer to a node (subsequent node in list)
        Node *next;

        // Constructor
        Node(const T &value) : data(value), next(nullptr) {}
    };

    Node* head;
};
#endif