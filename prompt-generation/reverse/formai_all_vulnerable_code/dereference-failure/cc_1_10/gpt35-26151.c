//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define a struct that holds data for each thread
typedef struct {
    int id;
    char* message;
    int delay;
} ThreadData;

// Function that each thread will execute
void* threadFunction(void* arg) {
    ThreadData* data = (ThreadData*) arg;
    printf("Thread %d: %s\n", data->id, data->message);
    sleep(data->delay); // Simulate work by sleeping
    printf("Thread %d: Done after %d seconds\n", data->id, data->delay);
    free(data); // Free the memory allocated for the thread data
    return NULL;
}

// Function to create a new thread with the given data
void createThread(pthread_t* thread, ThreadData* data) {
    int ret = pthread_create(thread, NULL, threadFunction, data);
    if (ret != 0) {
        printf("Error creating thread!\n");
        exit(-1);
    }
}

int main() {
    // Create some data for the threads to process
    ThreadData* data1 = (ThreadData*) malloc(sizeof(ThreadData));
    data1->id = 1;
    data1->message = "Hello from thread 1";
    data1->delay = 3;
    ThreadData* data2 = (ThreadData*) malloc(sizeof(ThreadData));
    data2->id = 2;
    data2->message = "Greetings from thread 2";
    data2->delay = 5;
    
    // Create the threads
    pthread_t thread1, thread2;
    createThread(&thread1, data1);
    createThread(&thread2, data2);
    
    // Wait for the threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    
    printf("All threads finished!\n");
    return 0;
}