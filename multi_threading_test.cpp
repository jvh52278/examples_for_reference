#include <iostream>
#include <thread>
#include <string>
#include <mutex>

std::mutex access_control;

void wait_for_trigger(std::string *trigger) {
    std::cout << "-----thread starting" << std::endl;
    std::string loop_run_status = "running";
    while (loop_run_status == "running") {
        std::lock_guard<std::mutex> lock(access_control);
        if (*trigger != "running") {
            loop_run_status = "not running";
            std::cout << "-----thread has finished" << std::endl;
        }
        
    }
}

int main () {
    // spawn a new thread
    std::string thread_trigger = "running";
    std::thread paralell_process(wait_for_trigger, &thread_trigger);
    std::string user_loop_status = "running";
    while (user_loop_status == "running") {
        std::cout << "enter no to exit the loop" << std::endl;
        std::string user_input;
        std::cin >> user_input;
        if (user_input == "no") {
            std::lock_guard<std::mutex> lock(access_control);
            thread_trigger = "not running";
            user_loop_status = "not running";
            std::cout << "loop is exiting" << std::endl;
        }
    }
    paralell_process.join();
    std::cout << "program is exiting" << std::endl;
    return 0;
}