/**
 * @file	thread-sleep.cpp
 * @brief	Demonstrating creation and suspension of threads
 * @author	Everton Cavalcante (everton.cavalcante@ufrn.br)
 * @since	November 29, 2021
 * @date	September 17, 2022
 */

#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <thread>

using namespace std;

/** @brief Number of threads to create */
#define NUM_THREADS 5

/**
 * @brief Suspends a given thread for a random number (between 1 and 5) of seconds
 * @details This is a callback function to run upon a thread
 * @param id Thread's ID
 */
void sleep(int id) {
	int seconds = rand() % 5 + 1;
	cout << "Suspending thread " << id << " for " << seconds << " seconds" << endl;
	this_thread::sleep_for(chrono::seconds(seconds));
	cout << "Thread " << id << " resuming execution" << endl;
}

/**
 * @brief Main function
 */
int main() {
	srand(time(NULL));
	thread threads[NUM_THREADS];
	for (int i = 0; i < NUM_THREADS; i++) {
		threads[i] = thread(sleep, i+1);
	}

	for (int i = 0; i < NUM_THREADS; i++) {
		threads[i].join();
	}

	cout << "Main thread resuming execution" << endl;
	return 0;
}