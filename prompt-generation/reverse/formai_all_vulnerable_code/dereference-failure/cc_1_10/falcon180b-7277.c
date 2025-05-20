//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_REQUESTS 1000
#define MAX_REQUEST_SIZE 1024

// Global variables
int num_threads;
pthread_t threads[MAX_THREADS];
int requests[MAX_REQUESTS][MAX_REQUEST_SIZE];

// Function prototypes
void *monitor_requests(void *arg);
void process_request(int thread_id, char *request);

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <number_of_threads>\n", argv[0]);
        return 1;
    }

    num_threads = atoi(argv[1]);

    if (num_threads < 1 || num_threads > MAX_THREADS) {
        printf("Invalid number of threads\n");
        return 1;
    }

    int i;
    for (i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, monitor_requests, (void *)i);
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

void *monitor_requests(void *arg) {
    int thread_id = (int)arg;

    while (1) {
        char request[MAX_REQUEST_SIZE];
        int request_size = 0;

        while (request_size == 0 || request_size == MAX_REQUEST_SIZE) {
            printf("Thread %d waiting for request...\n", thread_id);
            if (read(0, request, MAX_REQUEST_SIZE) <= 0) {
                printf("Error reading request\n");
                exit(1);
            }
            request_size = strlen(request);
        }

        requests[thread_id][request_size - 1] = '\0';
        process_request(thread_id, request);
    }
}

void process_request(int thread_id, char *request) {
    printf("Thread %d received request: %s\n", thread_id, request);

    // Perform intrusion detection here...

    printf("Thread %d finished processing request\n", thread_id);
}