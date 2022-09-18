/**
 * @file	thread-class.cpp
 * @brief	Demonstrating creation of threads to run class instances upon operator overloading
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
 * @class DisplayThread
 * @brief Class representing an object to display a string on the standard output
 */
class DisplayThread {
private:
	/** @brief Message to be displayed */
	string message;

public:
	/**
	 * @brief Parameterized constructor
	 * @param msg Reference to the message to be displayed
	 */
	DisplayThread(string msg) : message(msg) {}

	/**
	 * @brief Overloading the operator ()
	 * @details This method will automatically run when an object is bound to a thread 
	 */
	void operator()() {
		cout << message << endl;
	}
};

/**
 * @brief Main function
 */
int main() {
	DisplayThread display("Hello, I am a thread.");
	thread t(display);
	t.join();
	return 0;
}