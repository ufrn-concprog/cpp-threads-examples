/**
 * @file	thread-id.cpp
 * @brief	Demonstrating creation of threads and retrieval of their IDs
 * @author	Everton Cavalcante (everton.cavalcante@ufrn.br)
 * @since	November 29, 2021
 * @date	September 17, 2022
 */

#include <iostream>
using std::cout;
using std::endl;

#include <thread>
using std::thread;
using std::this_thread::get_id;

/** @brief Number of threads to create */
#define NUM_THREADS 5

/** 
 * @brief Prints the thread's ID on the standard output 
 * @details This is a callback function to run upon a thread
 */
void thread_id() {
	cout << "Hello, I am the thread " << get_id() << endl;
}

/**
 * @brief Main function
 */
int main() {
	thread threads[NUM_THREADS];
	for (int i = 0; i < NUM_THREADS; i++) {
		threads[i] = thread(thread_id);
	}

	for (int i = 0; i < NUM_THREADS; i++) {
		threads[i].join();
	}

	cout << "Hello, I am the thread " << get_id() << " (main)" << endl;
	return 0;
}