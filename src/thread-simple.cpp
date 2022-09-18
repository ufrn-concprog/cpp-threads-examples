/**
 * @file	thread-id.cpp
 * @brief	Demonstrating creation of threads to run a callback function
 * @author	Everton Cavalcante (everton.cavalcante@ufrn.br)
 * @since	November 29, 2021
 * @date	September 17, 2022
 */

#include <iostream>
using std::cout;
using std::endl;

#include <thread>
using std::thread;

/**
 * @brief Prints a greeting message on the standard output
 * @details This is a callback function to run upon a thread
 */
void hello() {
	cout << "Hello, I am a thread" << endl;
}

/**
 * @brief Main function
 */
int main() {
	thread t(hello);
	t.join();
	return 0;
}