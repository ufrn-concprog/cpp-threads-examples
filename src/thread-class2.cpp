/**
 * @file	thread-class2.cpp
 * @brief	Demonstrating creation of threads to run class instances upon object and method references
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
 /** @brief Name for a thread */
 string name;

public:
	/**
	 * @brief Parameterized constructor
	 * @param n Name to be assigned to a thread
	 */
	DisplayThread(string n) : name(n) {}

	/**
	 * @brief Displays the thread's name
	 * @details A reference to this method along with an object reference 
	 * are used when creating the thread to be run
	 */
	void hello() {
		cout << "Hello, I am the thread " << name << endl;
	}
};

/**
 * @brief Main function
 */
int main() {
	DisplayThread display("T");
	thread t(&DisplayThread::hello, &display);
	t.join();
	return 0;
}