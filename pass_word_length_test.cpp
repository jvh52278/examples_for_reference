#include <iostream>
#include <string>

int main()
{
    /*
    std::string char_1 = "a";
    std::string char_2 = "a";
    std::string char_3 = "a";
    std::string char_4 = "a";
    std::string char_5 = "a";
    std::string char_6 = "a";
    std::string final_password = char_1 + char_2 + char_3 + char_4 + char_5 + char_5;
    std::cout << final_password << std::endl;
    */
    std::string final_password;
    for (int x = 1; x <= 50; x = x + 1) {
        final_password = final_password + "a";
    }
    std::cout << final_password << std::endl;
}