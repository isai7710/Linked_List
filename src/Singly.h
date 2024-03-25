#ifndef SINGLY_H
#define SINGLY_H

#include <iostream>
#include <string>

template <typename T>
class Singly {
public:
    Singly() : head(nullptr), list_size(0) {}

    ~Singly() { clear_all(); }

    void append(const T &item_to_append) {
        Node* new_node = new Node(item_to_append);
        // the condition "!head" returns true if head points to null (list is empty)
        // in which case the item to append will be the head
        if (!head){
            head = new_node;
            list_size++;
            return;
        }
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_node;
    
        list_size++;
        return;
    }

    int size() const {
        return list_size;
    } 
    
    bool is_empty() const {
        return !head;
    }
    
    // Remove and return the last item in the list
    T pop_back() {
        if(!head){
            std::cout << "List is empty" << std::endl;

            return T{};
        }
        if(!head->next){
            T pop_back_item = head->data;
            Node* temp = head;
            delete temp;
            head = nullptr;

            list_size--;
            return pop_back_item;
        }
        // find second to last node
        Node* current = head;
        while(current->next->next){
            current = current->next;
        }
        T pop_back_item = current->next->data;
        Node* temp = current->next;
        current->next = nullptr;
        delete temp;

        list_size--;
        return pop_back_item;
    }

    // Remove and return the first item in the list
    T pop_front(){
        if (!head){
            std::cout << "List is empty" << std::endl;
            return T{};
        }
        T pop_front_item = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;

        list_size--;
        return pop_front_item;
    }
    
    void remove(const T &item_to_remove) {
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
            list_size--;
            return;
        }
        //
        Node* current = head;
        Node* temp;
        //draw this out as well but I will try to explain as best I can here
        //first check if we've reached the end of the list with the 'current->next' expression if so,
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

            list_size--;
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

            list_size--;
            return;
        }
        // find second to last node, again, if confusing, draw it out to see process
        Node* current = head;
        while (current->next->next) {
            current = current->next;
        }

        delete current->next;
        current->next = nullptr;

        list_size--;
        return;
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
    void insert_after(const T &value_to_insert_after, const T &value_to_insert) {
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

                list_size++;
                return;
            }
            current = current->next;
        }
        std::cout << "Item '" << value_to_insert_after << "' not found in the list. Insertion failed." << std::endl;
    }

    void insert_before(const T &value_to_insert_before, const T &value_to_insert) {
        if (!head) {
            std::cout << "List is empty, item to insert will now be appended as first item in list..." << std::endl;
            append(value_to_insert);
            return;
        }
        if (head->data == value_to_insert_before) {
            Node* newNode = new Node(value_to_insert);
            newNode->next = head;
            head = newNode;

            list_size++;
            return;
        }
        Node* current = head;
        while (current->next) {
            if (current->next->data == value_to_insert_before){
                Node* newNode = new Node(value_to_insert);
                newNode->next = current->next;
                current->next = newNode;

                list_size++;
                return;
            }
            current = current->next;
        }
        std::cout << "Item '" << value_to_insert_before << "' not found in the list. Insertion failed." << std::endl;
    }

    std::string to_string() {
        std::stringstream list;
        Node* current = head;
        while (current->next) {
            list << current->data << " ";
            current = current->next;
        }
        list << current->data;
        return list.str();
    }
    
    // Access elements in the list by index
    T& operator[](int index) {
        Node* current = head;
        for(int i=0; i<index; i++){
            current = current->next;
        }
        return current->data;
    }

    // Remove duplicate elements from the list
    void remove_duplicates() {
        
    }
    // Reverse the order of elements in the list.
    // void reverse() {}
    /*
    TODO:
    T& front() const: Get a reference to the first element in the list.
    T& back() const: Get a reference to the last element in the list.
    void sort(): Sort the elements in the list.
    Singly<T> copy() const: Create a copy of the list.
    bool equals(const Singly<T> &other) const: Compare two lists for equality.
    */
    
    void clear_all() {
        Node* node_to_delete;
        while(head){
            node_to_delete = head;
            head = head->next;
            delete node_to_delete;
        }
        list_size = 0;
        return;
    }
private:
    // ----- A Node is the building block for a single-linked list: -----
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
    int list_size;
};
#endif
