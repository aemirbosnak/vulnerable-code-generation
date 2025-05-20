//GEMINI-pro DATASET v1.0 Category: Threading Library Implementation ; Style: genius
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct philosopher {
	pthread_t thread;
	int id;
	pthread_mutex_t left_fork, right_fork;  
};


void *philosopher_thread(void *arg) {
	struct philosopher *p = (struct philosopher *)arg;

	while (1) {
		// Think
		printf("Philosopher %d is thinking.\n", p->id);
		sleep(rand() % 5);
		
		// Get left fork
		pthread_mutex_lock(&p->left_fork);
		// Check if right fork is available
		if (pthread_mutex_trylock(&p->right_fork) == 0) {
			// Eat
			printf("Philosopher %d is eating.\n", p->id);
			sleep(rand() % 5);
			
			// Release right fork
			pthread_mutex_unlock(&p->right_fork);
		} 
		else {
			// Release left fork
			pthread_mutex_unlock(&p->left_fork);
		}	
	}

	return NULL;
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Usage: %s <number of philosophers>\n", argv[0]);
		return 1;
	}

	int n = atoi(argv[1]);
	if (n < 2 || n > 5) {
		printf("Number of philosophers must be between 2 and 5.\n");
		return 1;
	}

	struct philosopher philosophers[n];

	// Initialize forks
	for (int i = 0; i < n; i++) {
		pthread_mutex_init(&philosophers[i].left_fork, NULL);
		pthread_mutex_init(&philosophers[i].right_fork, NULL);
	}

	// Create philosopher threads
	for (int i = 0; i < n; i++) {
		philosophers[i].id = i + 1;
		pthread_create(&philosophers[i].thread, NULL, philosopher_thread, &philosophers[i]);
	}

	// Main thread waits for philosopher threads to finish
	for (int i = 0; i < n; i++) {
		pthread_join(philosophers[i].thread, NULL);
	}

	return 0;
}