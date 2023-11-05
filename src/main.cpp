#include <iostream>
#include <string>
#include <thread>
#include <chrono>

#include "Singly.h"

void delay(int milliseconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

int main() {
    Singly<int> intList;

    while (true) {
        int choice;
        std::cout << "Choose an operation:" << std::endl;
        std::cout << "\033[34m 1.\033[0m Append an item" << std::endl;
        std::cout << "\033[34m 2.\033[0m Insert an item" << std::endl;
        std::cout << "\033[34m 3.\033[0m Remove an item" << std::endl;
        std::cout << "\033[34m 4.\033[0m Print the list" << std::endl;
        std::cout << "\033[34m 5.\033[0m Remove tail" << std::endl;
        std::cout << "\033[34m 6.\033[0m Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cout << std::endl;
        switch (choice) {
            case 1: {
                int item;
                std::cout << "Enter the item to append: ";
                std::cin >> item;
                intList.append(item);
                break;
            }
            case 2: {
                int item, position;
                std::cout << "Enter the item to insert: ";
                std::cin >> item;
                std::cout << "Enter item to insert after: ";
                std::cin >> position;
                intList.insert_after(item, position);
                break;
            }
            case 3: {
                int item;
                std::cout << "Enter the item to remove: ";
                std::cin >> item;
                intList.remove_item(item);
                break;
            }
            case 4:
                intList.print_list();
                delay(1000);
                break;
            case 5:
                intList.remove_tail();
                delay(1000);
                break;
            case 6:
                return 0; // Exit the program
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}