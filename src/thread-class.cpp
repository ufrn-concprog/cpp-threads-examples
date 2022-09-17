#include <iostream>
using std::cout;
using std::endl;

#include <thread>
using std::thread;

#include <string>
using std::string;


class DisplayThread {
private:
	string message;

public:
	DisplayThread(string msg) : message(msg) {}
	void operator()() {
		cout << message << endl;
	}
};

int main() {
	DisplayThread display("Hello, I am a thread.");
	thread t(display);
	t.join();
	return 0;
}