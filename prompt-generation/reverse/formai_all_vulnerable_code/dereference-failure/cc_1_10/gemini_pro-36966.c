//GEMINI-pro DATASET v1.0 Category: Threading Library Implementation ; Style: innovative
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// Thread function to be executed by the child thread
void *child_thread(void *arg) {
    // Print a message from the child thread
    printf("Hello from child thread!\n");

    // Sleep for 1 second to simulate some work
    sleep(1);

    // Create a response message to be returned to the parent thread
    char *message = (char *)malloc(20);
    strcpy(message, "Hello from child thread!");

    // Return the response message to the parent thread
    return (void *)message;
}

int main() {
    // Create a thread attribute object
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    // Set the thread stack size to 2MB
    pthread_attr_setstacksize(&attr, 2 * 1024 * 1024);

    // Create a child thread with the specified attributes
    pthread_t child;
    int ret = pthread_create(&child, &attr, child_thread, NULL);
    if (ret != 0) {
        perror("pthread_create");
        exit(EXIT_FAILURE);
    }

    // Join the child thread, waiting for it to complete
    void *result;
    ret = pthread_join(child, &result);
    if (ret != 0) {
        perror("pthread_join");
        exit(EXIT_FAILURE);
    }

    // Print the message returned by the child thread
    printf("Message from child thread: %s\n", (char *)result);

    // Free the memory allocated for the response message
    free(result);

    // Exit the main thread, terminating the program
    return 0;
}