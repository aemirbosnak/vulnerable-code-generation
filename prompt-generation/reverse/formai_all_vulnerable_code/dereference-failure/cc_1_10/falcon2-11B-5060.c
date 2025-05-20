//Falcon2-11B DATASET v1.0 Category: Threading Library Implementation ; Style: automated
#include <stdio.h>
#include <pthread.h>

// Function to be executed by each thread
void* thread_function(void* arg)
{
    // Get the thread id
    int thread_id = *((int*) arg);

    // Print the thread id
    printf("Thread %d is running...\n", thread_id);

    // Wait for 1 second
    sleep(1);

    // Print the thread id again
    printf("Thread %d has finished...\n", thread_id);

    // Return from the function
    return NULL;
}

int main()
{
    // Create an array to store thread ids
    int thread_ids[5];

    // Initialize all thread ids to 0
    for (int i = 0; i < 5; i++) {
        thread_ids[i] = 0;
    }

    // Create threads
    pthread_t threads[5];
    for (int i = 0; i < 5; i++) {
        int thread_id = i;
        thread_ids[i] = thread_id;
        pthread_create(&threads[i], NULL, thread_function, &thread_id);
    }

    // Wait for all threads to finish
    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print thread ids
    for (int i = 0; i < 5; i++) {
        printf("Thread %d finished with the value %d\n", i, thread_ids[i]);
    }

    return 0;
}