#include <iostream>

int add_two_numbers (int number_1, int number_2) {
    int sum = number_1 + number_2;
    return sum;
}

int add_two_numbers_new (const int *number_1, const int *number_2) {
    int sum = *number_1 + *number_2;
    std::cout << sum << std::endl;
    return 0;
}

int add_two_numbers_new_reference (const int &number_1, const int &number_2) {
    int sum = number_1 + number_2;
    std::cout << sum << std::endl;
    return 0;
}

int change_value_by_pointer (int *value_to_change) {
    *value_to_change = 666;
    return 0;
}


int change_value_by_reference (int &value_to_change) {
    value_to_change = 616;
    return 0;
}

void function_returns_nothing () {
    std::cout << "this does nothing" << std::endl;
}

int function_also_does_nothing() {
    std::cout << "this also does nothing" << std::endl;
    return 0;
}

bool function_as_a_condition (int test_this_int) {
    if (test_this_int > 0) {
        return true;
    } else {
        return false;
    }
}

int main () {
    /*
    int number_1 = 2;
    int number_2 = 3;
    std::cout << number_1 + number_2 << std::endl;

    int number_3 = 5;
    int number_4 = 6;
    std::cout << number_3 + number_4 << std::endl;
    */

    /*
    int sum_1 = add_two_numbers(4,5);
    std::cout << sum_1 << std::endl;

    function_returns_nothing();

    function_also_does_nothing();

    int test_value = 7;
    // pointer
    int *test_pointer = &test_value;
    std::cout << *test_pointer << std::endl;
    // reference
    int &test_reference = test_value;
    std::cout << test_reference << std::endl;

    *test_pointer = 90;
    std::cout << test_value << std::endl;

    test_reference = 190;
    std::cout << test_value << std::endl;

    const int *new_test_pointer = &test_value;
    // *new_test_pointer = 200;
    std::cout << *new_test_pointer << std::endl;

    //const int &new_test_reference = test_value;
    //new_test_reference = 290;

    int test_variable_1 = 8;
    int test_variable_2 = 7;
    add_two_numbers_new(&test_variable_1, &test_variable_2);

    add_two_numbers_new_reference(test_variable_1, test_variable_2);
    */
    /*
    int value_should_change = 0;
    change_value_by_pointer(&value_should_change);
    change_value_by_reference(value_should_change);
    std::cout << value_should_change << std::endl;
    */
    int test_int = -5;
    if (function_as_a_condition(test_int)) {
        std::cout << "this if statement was executed" << std::endl;
    }

    return 0;
}