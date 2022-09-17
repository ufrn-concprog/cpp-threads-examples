#include <iostream>
using std::cout;
using std::endl;

#include <thread>
using std::thread;

#include <string>
using std::string;

void hello(string message) {
	cout << message << endl;
}

int main() {
	thread t(hello, "Hello, I am a thread");
	t.join();
	return 0;
}