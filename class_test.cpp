#include <iostream>
#include <string>
#include "external_class.h"

class test_class {
private:
int number_1 = 0;
int number_2 = 0;
protected:
int linked_variable = 15;
public:
int set_numbers (int value_1, int value_2) {
    number_1 = value_1;
    number_2 = value_2;
    return 0;
}
void add_numbers () {
    std::cout << number_1 + number_2 << std::endl;
}
};

class test_class_1 : test_class {
    public:
    void multiply_fixed_value () {
        std::cout << linked_variable * 2 << std::endl;
    }
    void set_linked_variable (int value) {
        linked_variable = value;
    }
};

int main () {
    /*
    int number_1 = 2;
    int number_2 = 3;
    std::cout << number_1 + number_2 << std::endl;

    int number_3 = 2;
    int number_4 = 3;
    std::cout << number_3 + number_4 << std::endl;

    int number_5 = 2;
    int number_6 = 3;
    std::cout << number_5 + number_6 << std::endl;
    */
    /*
    test_class class_instance_1;

    class_instance_1.set_numbers(10, 7);
    class_instance_1.add_numbers();

    class_instance_1.set_numbers(11, 7);
    class_instance_1.add_numbers();

    class_instance_1.set_numbers(12, 7);
    class_instance_1.add_numbers();
    */
   /*
    test_class_1 class_instance_2;
    class_instance_2.set_linked_variable(25);
    class_instance_2.multiply_fixed_value();
    */
    external_class class_instance_3;
    class_instance_3.external_function();
    return 0;
}