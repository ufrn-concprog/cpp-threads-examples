/**
 * @file	syncout.cpp
 * @brief	Demonstrating the synchronized output stream provided by C++20
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

using namespace std;

/** @brief Number of threads to create */
#define NUM_THREADS 5

/**
 * @brief Suspends a given thread for a random number (between 1 and 5) of seconds
 * @details This is a callback function to run upon a thread
 * @param id Thread's ID
 */
void to_sleep(int id) {
	int seconds = rand() % 5 + 1;
    std::osyncstream sync_cout(std::cout);
    sync_cout << "Suspending thread " << id << " for " << seconds << " seconds" << endl;
	this_thread::sleep_for(chrono::seconds(seconds));
	sync_cout << "Thread " << id << " resuming execution" << endl;
}

/**
 * @brief Main function
 */
int main() {
	srand(time(NULL));
	thread threads[NUM_THREADS];
	for (int i = 0; i < NUM_THREADS; i++) {
		threads[i] = thread(to_sleep, i+1);
	}

	for (int i = 0; i < NUM_THREADS; i++) {
		threads[i].join();
	}

	cout << "Main thread resuming execution" << endl;
	return 0;
}