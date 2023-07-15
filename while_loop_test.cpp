#include <iostream>
#include <string>

int main () {
    std::string run_status = "yes";
    while (run_status == "yes") {
        std::cout << "do you want the loop to keeping running? yes or no" << std::endl;
        std::string user_input;
        std::cin >> user_input;
        if (user_input == "no") {
            run_status = "no";
        }
    }
    return 0;
}