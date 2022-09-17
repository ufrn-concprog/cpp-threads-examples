#include <iostream>
using std::cout;
using std::endl;

#include <thread>
using std::thread;
using std::this_thread::get_id;

#define NUM_THREADS 5

void thread_id() {
	cout << "Hello, I am the thread " << get_id() << endl;
}

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