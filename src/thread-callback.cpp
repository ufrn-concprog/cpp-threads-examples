/**
 * @file	thread-callback.cpp
 * @brief	Demonstrating creation of C++ threads with a parameterized callback function
 * @author	Everton Cavalcante (everton.cavalcante@ufrn.br)
 * @since	November 29, 2021
 * @date	September 17, 2022
 */

#include <iostream>
using std::cout;
using std::endl;

#include <thread>
using std::thread;

#include <string>
using std::string;

/**
 * @brief Prints a message on the standard output
 * @details This is a callback function to run upon a thread
 * @param message Message to be printed
 */
void hello(string message) {
	cout << message << endl;
}

/**
 * @brief Main function
 */
int main() {
	thread t(hello, "Hello, I am a thread");
	t.join();
	return 0;
}