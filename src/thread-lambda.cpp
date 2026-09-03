/**
 * @file	thread-lambda.cpp
 * @brief	Demonstrating creation of C++ threads with a parameterized lambda
 * @author	Everton Cavalcante (everton.cavalcante@ufrn.br)
 * @since	September 2, 2026
 * @date	September 2, 2026
 */

#include <iostream>
using std::cout;
using std::endl;

#include <thread>
using std::thread;

#include <string>
using std::string;

/**
 * @brief Main function
 */
int main() {
	thread t([](string message) {
		cout << message << endl;
	}, "Hello, I am a thread");
	t.join();
	return 0;
}