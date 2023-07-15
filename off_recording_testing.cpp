#include <iostream>

#include <thread>
#include <mutex>

#include <chrono>

// set the mutex
std::mutex access_control;  

int wait_for_trigger (std::string *trigger) {
    const auto time_started = std::chrono::system_clock::now();
    std::cout << "-----timer thread has started: " << std::chrono::duration_cast<std::chrono::milliseconds>(time_started.time_since_epoch()).count() << std::endl;
    // set the timer loop to run
    std::string function_loop_status = "running";
    while (function_loop_status == "running") {
        /*
        // lock access to the flag variable
        std::lock_guard<std::mutex> lock(access_control);
        */
        //check if the flag variable is active
        if (*trigger != "running") {
            function_loop_status = "not running";
            //end the program if the trigger is off
            const auto time_ended = std::chrono::system_clock::now();
            std::cout << "-----timer thread has ended\n-----thread ran for: " << std::chrono::duration_cast<std::chrono::milliseconds>(time_ended.time_since_epoch()).count() - std::chrono::duration_cast<std::chrono::milliseconds>(time_started.time_since_epoch()).count() << " ms" << std::endl;
            return 0;
        }
    }
    return 0;
}

int main () {
    std::string run_status = "running";
    // spin off a process
    std::thread paralell_process(wait_for_trigger, &run_status);
    // run this loop until the user enters "no"
    std::string user_loop_run = "running";
    while (user_loop_run == "running") {
        std::cout << "enter no to exit loop" << std::endl;
        std::string user_input;
        std::cin >> user_input;
        // if the user enters no, stop the timer and exit this loop
        if (user_input == "no") {
            // set the thread trigger to off
            run_status = "not running";
            // exit the loop
            user_loop_run = "not running";
            std::cout << "user loop has ended" << std::endl;
        }
    }
    std::cout << "program will end ended" << std::endl;
    paralell_process.join();
    std::cout << "program is done" << std::endl;
    return 0;
}