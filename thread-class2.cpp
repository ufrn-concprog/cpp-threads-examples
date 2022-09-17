#include <iostream>
using std::cout;
using std::endl;

#include <thread>
using std::thread;

#include <string>
using std::string;


class DisplayThread {
private:
	string name;

public:
	DisplayThread(string n) : name(n) {}
	void hello() {
		cout << "Hello, I am the thread " << name << endl;
	}
};

int main() {
	DisplayThread display("T");
	thread t(&DisplayThread::hello, &display);
	t.join();
	return 0;
}