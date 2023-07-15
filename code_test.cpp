#include <iostream>
#include <vector>

int main () {
    int test_variable = 1;
    int test_variable_1 = 2;
    int test_variable_2 = 3;
    int test_variable_3 = 4;
    int test_variable_4 = 5;

    // fixed sized container
    double array_of_doubles[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    // expandible container
    std::vector<double> vector_of_doubles = {1.1, 2.2, 3.3};

    //std::cout << array_of_doubles[3] << std::endl; 

    // if statement
    int input = -5;
    if (input >= 0 || input == -5) {
        //std::cout << "correct input" << std::endl; 
    }
    // try catch
    std::string user_input;
    std::cout << "please enter a number" << std::endl; 
    std::cin >> user_input;
    std::cout << user_input << std::endl;
    try {
        int converted_string = std::stoi(user_input);
        std::cout << "conversion successful" << std::endl; 
    }
    catch (...) {
        std::cout << "error: conversion failed" << std::endl; 
    }
    return 0;
}