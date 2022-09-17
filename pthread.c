#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

void *print(void *arg) {
	printf("[thread] Thread running\n");
	printf("[thread] Received argument: %s\n", (char*) arg);
	sleep(3);
	pthread_exit((char*) "\n[thread] Finishing execution");
}

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