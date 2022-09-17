#include <iostream>
using std::cout;
using std::endl;

#include <thread>
using std::thread;

void hello() {
	cout << "Hello, I am a thread" << endl;
}

int main() {
	thread t(hello);
	t.join();
	return 0;
}