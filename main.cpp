#include <iostream>
#include "SingleList.hpp"

int main() {
    // Test 1: Creating lists using different constructors
    SingleList list1;  // Default constructor
    SingleList list2(5, 3);  // List with 5 repeated 3 times
    SingleList list3 = {1, 2, 3, 4, 5};  // Initializer list
    SingleList list4(list3);  // Copy constructor
    SingleList list5 = std::move(list2);  // Move constructor
    
    std::cout << "Initial lists:" << std::endl;
    std::cout << "list1: " << list1;
    std::cout << "list2 (after move to list5): " << list2;
    std::cout << "list3: " << list3;
    std::cout << "list4 (copy of list3): " << list4;
    std::cout << "list5 (moved from list2): " << list5;

    // Test 2: Concatenation using + and += operators
    SingleList list6 = list3 + list4;
    std::cout << "\nConcatenation of list3 and list4 using +: " << list6;
    
    list3 += list4;
    std::cout << "list3 after concatenation with += operator: " << list3;

    // Test 3: Comparison using == and != operators
    std::cout << "\nComparing lists:" << std::endl;
    if (list3 == list4) {
        std::cout << "list3 and list4 are equal" << std::endl;
    } else {
        std::cout << "list3 and list4 are not equal" << std::endl;
    }
    
    if (list5 != list6) {
        std::cout << "list5 and list6 are not equal" << std::endl;
    } else {
        std::cout << "list5 and list6 are equal" << std::endl;
    }

    // Test 4: Indexing using [] operator
    std::cout << "\nIndexing into list6:" << std::endl;
    std::cout << "Element at index 2 of list6: " << list6[2] << std::endl;
    
    // Test 5: Prefix and Postfix increment/decrement
    std::cout << "\nPrefix and Postfix increment/decrement:" << std::endl;
    std::cout << "list3 before increment: " << list3;
    ++list3;  // Prefix increment
    std::cout << "list3 after prefix increment: " << list3;
    list3++;  // Postfix increment
    std::cout << "list3 after postfix increment: " << list3;
    
    std::cout << "list3 before decrement: " << list3;
    --list3;  // Prefix decrement
    std::cout << "list3 after prefix decrement: " << list3;
    list3--;  // Postfix decrement
    std::cout << "list3 after postfix decrement: " << list3;

    // Test 6: Stream operators << and >> (I will simulate input through code)
    std::cout << "\nStream operators << and >>:" << std::endl;
    
    std::cout << "Enter values for a new list (e.g., 10): ";
    SingleList inputList;
    std::cin >> inputList;  // Using stream operator to input values
    std::cout << "You entered: " << inputList;
    
    // Edge cases: Empty list and single element list
    SingleList emptyList;
    std::cout << "\nEdge Case: Empty list: " << emptyList;

    SingleList singleElementList(42, 1);  // Single element list
    std::cout << "Edge Case: Single element list: " << singleElementList;

    // Test edge case: Accessing elements and handling errors
    try {
        std::cout << "\nAccessing invalid index in list3: " << list3[100] << std::endl;
    } catch (...) {
        std::cout << "Caught error when accessing invalid index!" << std::endl;
    }

    return 0;
}