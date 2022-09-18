/**
 * @file	pthread-basic.c
 * @brief	Demonstrating basic programming with POSIX Threads in C
 * @author	Everton Cavalcante (everton.cavalcante@ufrn.br)
 * @since	November 29, 2021
 * @date	September 17, 2022
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

/**
 * @brief Prints the argument received as input
 * @details This is a callback function to run upon a thread
 * @param arg Argument to the function pointer
 */
void *print(void *arg) {
	printf("[thread] Thread running\n");
	printf("[thread] Received argument: %s\n", (char*) arg);
	sleep(3);
	pthread_exit((char*) "\n[thread] Finishing execution");
}

/**
 * @brief Main function
 */
int main() {
	char message[] = "Hello, world";
	pthread_t thread;
	void *thread_result;

	int result = pthread_create(&thread, NULL, print, (void*) message);
	if (result != 0) {
		perror("Fail to execute pthread_create()");
	}

	printf("[main] Waiting for the thread to finish\n");
	result = pthread_join(thread, &thread_result);
	if (result != 0) {
		perror("Fail to execute pthread_join()");
	}

	printf("[main] Waiting for the thread to finish\n");
	printf("[main] Message: %s\n\n", message);

	exit(EXIT_SUCCESS);
}