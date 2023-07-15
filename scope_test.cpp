#include <iostream>

int main () { // scope A
    int test_variable = 5; // instuction 1
    test_variable = test_variable + 3; // instruction 2
    std::string message = "test variable is greater than 0";
    if (test_variable > 0) { // scope B -- instruction 3
        std::cout << message << std::endl;
    }
    std::cout << "program has completed" << std::endl; // instruction 4
    return 0;
}