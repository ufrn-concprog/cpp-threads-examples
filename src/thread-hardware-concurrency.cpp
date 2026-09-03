/**
 * @file    thread-hardware-concurrency.cpp
 * @brief   Demonstrates obtaining hardware concurrency and creating matching worker threads
 * @author  Everton Cavalcante (everton.cavalcante@ufrn.br)
 * @since   September 2, 2026
 * @date    September 2, 2026
 */

#include <iostream>
using std::cout;
using std::endl;

#include <thread>
using std::thread;

#include <vector>
using std::vector;

/**
 * @brief Displays a message identifying a running worker thread
 * @param id Identifier assigned to the worker thread
 */
void doWork(int id) {
    cout << "Worker " << id << " running on some core\n";
}

/**
 * @brief Main function
 */
int main() {
    unsigned int numcores = thread::hardware_concurrency();

    // hardware_concurrency() can return 0 if the value is not computable/well-defined
    // on a given platform, so it is good practice to fall back to a sane default.
    if (numcores == 0) {
        cout << "Unable to detect hardware concurrency; defaulting to 4\n";
        numcores = 4;
    }

    cout << "Detected " << numcores << " concurrent threads supported\n";
    cout << "Creating " << numcores << " worker threads to match...\n\n";

    vector<thread> workers;
    for (unsigned int i = 0; i < numcores; ++i) {
        workers.emplace_back(doWork, i);
    }

    for (auto& t : workers) {
        t.join();
    }

    return 0;
}