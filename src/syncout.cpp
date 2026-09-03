/**
 * @file	syncout.cpp
 * @brief	Demonstrating the use of synchronized output stream and jthreads in C++20
 * @author	Everton Cavalcante (everton.cavalcante@ufrn.br)
 * @since	October 16, 2024
 * @date	October 16, 2024
 */

#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <syncstream>
#include <thread>

/** @brief Number of jthreads to create */
#define NUM_JTHREADS 5

/**
 * @brief Suspends a given thread for a random number (between 1 and 5) of seconds
 * @details This is a callback function to run upon a thread
 * @param id Thread's ID
 */
void to_sleep(int id) {
	int seconds = rand() % 5 + 1;
    std::osyncstream sync_cout(std::cout);
	sync_cout << "Suspending thread " << id << " for " << seconds << " seconds" << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(seconds));
	sync_cout << "Thread " << id << " resuming execution" << std::endl;
}

/**
 * @brief Main function
 */
int main() {
	srand(time(NULL));
	std::jthread threads[NUM_JTHREADS];
	for (int i = 0; i < NUM_JTHREADS; i++) {
		threads[i] = std::jthread(to_sleep, i+1);
	}

    std::cout << "Main thread resuming execution" << std::endl;
	return 0;
}