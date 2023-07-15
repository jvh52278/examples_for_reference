#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <cctype>
#include <chrono>
#include <mutex>
#include <thread>

class random_char_class {
    private:
    protected:
    public:
    char generate_random_character () {
        // generate a random char
        std::string list_of_random_chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890+-=_?;:";

        std::random_device os_seed;
        uint_least32_t random_number_seed = os_seed();

        std::mt19937 generator(random_number_seed);
        std::uniform_int_distribution< uint_least32_t > distribute(0, list_of_random_chars.length() - 1);

        int random_index = distribute(generator);
        //std::cout << random_index << std::endl;
        char random_char = list_of_random_chars[random_index];
        return random_char;
    }

};

std::mutex access_control;

int timer (std::string *trigger) {
    // log the start time
    auto start_time = std::chrono::system_clock::now();
    int start_time_covererted = std::chrono::duration_cast<std::chrono::microseconds>(start_time.time_since_epoch()).count();
    // check if the trigger is active
    std::string timer_loop_status = "running";
    while (timer_loop_status == "running") {
        std::lock_guard<std::mutex> lock(access_control);
        // if the trigger is not active, exit the function
        if (*trigger == "running") {
            auto end_time = std::chrono::system_clock::now();
            int end_time_covererted = std::chrono::duration_cast<std::chrono::microseconds>(end_time.time_since_epoch()).count();
            int running_time = end_time_covererted - start_time_covererted;
            std::cout << "password was generated in: " << running_time << " microseconds" << std::endl;
            timer_loop_status = "not running";
        }
    }
    return 0;
}

int main () {
    std::string run_status = "yes";
    while (run_status == "yes") {

        // get this user input
        std::cout << "do you want to generate a random password? yes or no?" << std::endl;
        std::string user_input;
        std::cin >> user_input;
        std::cout << user_input << std::endl;
        // check if the input is yes or no
        if (user_input == "yes") {
            std::cout << "a password will now be generated" << std::endl;
            // generate the password
            std::cout << "please enter a password length" << std::endl;
            std::string user_input_password_length;
            std::cin >> user_input_password_length;
            int converted_string = 0;
            try {
                // convert the string to int
                converted_string = std::stoi(user_input_password_length);
                std::cout << "the password length is: " << converted_string << std::endl;
                if (converted_string >= 1) {
                    std::string timer_trigger = "running";
                    // generate a new thread
                    std::thread timer_thread(timer, &timer_trigger);
                    // generate the appropriate number of random chars
                    std::string generated_password;
                    for (int x = 1; x <= converted_string; x = x + 1) {
                        // generate the random character
                        random_char_class random_char_class;
                        char random_char = random_char_class.generate_random_character();
                        // append the random char to the password string
                        generated_password = generated_password + random_char;
                    }
                    // stop the timer
                    std::lock_guard<std::mutex> lock(access_control);
                    timer_trigger = "not running";
                    timer_thread.join();
                    // display the password
                    std::cout << "your password is:\n" << generated_password << std::endl;
                } else {
                    std::cout << "error: the password must be 1 character long or more" << std::endl;
                }
            }
            catch (...) {
                std::cout << "error: you have not entered a valid number" << std::endl;
            }
        } else if (user_input == "no") {
            std::cout << "the program will exit" << std::endl;
            run_status = "no";
            // exit the program
        } else {
            std::cout << "please enter yes or no" << std::endl;
        }
    }
    return 0;
}