#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <thread>

using namespace std;

#define NUM_THREADS 5

void sleep(int id) {
	int seconds = rand() % 5 + 1;
	cout << "Suspending thread " << id << " for " << seconds << " seconds" << endl;
	this_thread::sleep_for(chrono::seconds(seconds));
	cout << "Thread " << id << " resuming execution" << endl;
}

int main() {
	srand(time(NULL));
	thread threads[NUM_THREADS];
	for (int i = 0; i < NUM_THREADS; i++) {
		threads[i] = thread(sleep, i+1);
	}

	for (int i = 0; i < NUM_THREADS; i++) {
		threads[i].join();
	}

	cout << "Main thread resuming execution" << endl;
	return 0;
}