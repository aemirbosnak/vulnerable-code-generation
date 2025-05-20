//Falcon2-11B DATASET v1.0 Category: Threading Library Implementation ; Style: recursive
#include <pthread.h>
#include <stdio.h>

// Function to be executed by threads
void* thread_func(void* arg) {
    // Retrieve the argument passed to the thread
    int *num = (int*) arg;

    // Print the argument value
    printf("Thread %d: value is %d\n", *num, *num);

    // Increment the value of the argument by 1
    int *incr_num = (int*) malloc(sizeof(int));
    *incr_num = *num + 1;

    // Update the argument value with the incremented value
    free(incr_num);
    *num = *incr_num;

    // Sleep for 1 second to simulate thread synchronization
    sleep(1);

    // Cleanup
    pthread_exit(NULL);
}

int main() {
    // Create an array of thread arguments
    int nums[] = {1, 2, 3, 4, 5};

    // Create an array of thread IDs
    pthread_t threads[5];

    // Create threads and pass the array of arguments to each thread
    for (int i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, thread_func, &nums[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the final values of the arguments
    for (int i = 0; i < 5; i++) {
        printf("Final value of argument %d is %d\n", i, nums[i]);
    }

    // Cleanup
    pthread_exit(NULL);
}