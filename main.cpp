#include "SingleList.hpp"
#include <iostream>

void testCopyAndMove() {
    std::cout << "=== Copy & Move Test ===\n";

    SingleList original{1, 2, 3};
    SingleList copy = original; // Copy constructor
    SingleList assigned;
    assigned = original; // Copy assignment

    SingleList moved = std::move(original); // Move constructor
    SingleList moveAssigned;
    moveAssigned = std::move(copy); // Move assignment

    std::cout << "Moved List: " << moved;
    std::cout << "Move Assigned List: " << moveAssigned;
    std::cout << "Copy should now be empty: " << copy;
    std::cout << "Original should now be empty: " << original;
    std::cout << "Assigned (copy assignment): " << assigned << "\n";
}

void testConcatenation() {
    std::cout << "\n=== Concatenation Test ===\n";

    SingleList list1{1, 2, 3};
    SingleList list2{4, 5};

    SingleList result = list1 + std::move(list2);
    std::cout << "Result of list1 + list2: " << result;

    list1 += SingleList{6, 7};
    std::cout << "List1 after += {6, 7}: " << list1 << "\n";
}

void testComparison() {
    std::cout << "\n=== Comparison Test ===\n";

    SingleList list1{1, 2, 3};
    SingleList list2{1, 2, 3};
    SingleList list3{1, 2};

    std::cout << "list1 == list2: " << (list1 == list2) << "\n";
    std::cout << "list1 != list3: " << (list1 != list3) << "\n";
}

void testIndexing() {
    std::cout << "\n=== Indexing Test ===\n";

    SingleList list{10, 20, 30};

    for (int i = 0; i < list.size(); ++i) {
        std::cout << "list[" << i << "] = " << list[i] << "\n";
    }

    std::cout << "Modifying list[1] = 200\n";
    list[1] = 200;
    std::cout << "Updated list: " << list;
}

void testIncrementDecrement() {
    std::cout << "\n=== Increment/Decrement Test ===\n";

    SingleList list{1, 2};

    std::cout << "Original list: " << list;

    std::cout << "Postfix increment (list++): " << list++;
    std::cout << "After postfix increment: " << list;

    std::cout << "Prefix increment (++list): " << ++list;

    std::cout << "Postfix decrement (list--): " << list--;
    std::cout << "After postfix decrement: " << list;

    std::cout << "Prefix decrement (--list): " << --list << "\n";
}

void testStreamOperators() {
    std::cout << "\n=== Stream Operators Test ===\n";
    
    SingleList list;
    std::cout << "Enter a number to add to the list: ";
    std::cin >> list;
    std::cout << "You entered: " << list;
}

void testEdgeCases() {
    std::cout << "\n=== Edge Cases Test ===\n";

    SingleList empty;
    std::cout << "Empty list: " << empty;
    std::cout << "Is empty list false? (!empty): " << (!empty) << "\n";

    SingleList single{42};
    std::cout << "Single element list: " << single;
    std::cout << "Accessing single[0]: " << single[0] << "\n";
}

int main() {
    testCopyAndMove();
    testConcatenation();
    testComparison();
    testIndexing();
    testIncrementDecrement();
    testStreamOperators();
    testEdgeCases();

    return 0;
}
