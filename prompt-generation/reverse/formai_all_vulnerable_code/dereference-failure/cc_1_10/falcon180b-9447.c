//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10

// Global variables
int num_threads;
pthread_t threads[MAX_THREADS];

// Function prototypes
void *manage_store(void *arg);
void create_thread(int id);

int main() {
    int i;

    // Initialize random seed
    srand(time(NULL));

    // Prompt user for number of threads
    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

    // Create threads
    for (i = 0; i < num_threads; i++) {
        create_thread(i);
    }

    // Join threads
    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

void *manage_store(void *arg) {
    int id = *((int *) arg);
    char name[20];

    // Generate random name
    sprintf(name, "Thread %d", id);

    // Simulate work
    printf("%s is managing the medical store.\n", name);

    return NULL;
}

void create_thread(int id) {
    pthread_t thread_id;
    int *thread_num;

    // Allocate memory for thread ID and thread number
    thread_id = (pthread_t) malloc(sizeof(pthread_t));
    thread_num = (int *) malloc(sizeof(int));

    // Initialize thread ID and thread number
    *thread_num = id;

    // Create thread
    pthread_create(thread_id, NULL, manage_store, (void *) thread_num);

    // Add thread ID to array
    threads[id] = thread_id;
}