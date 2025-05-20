//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define a struct to hold a thread's attributes
struct ThreadArgs {
    int id;
    int sleep_time;
    char* message;
};

// Define a function that threads will call
void* thread_function(void* arg) {
    struct ThreadArgs* args = (struct ThreadArgs*) arg;

    // Sleep for the specified amount of time
    printf("Thread %d sleeping for %d seconds...\n", args->id, args->sleep_time);
    sleep(args->sleep_time);

    // Print the message
    printf("Thread %d: %s\n", args->id, args->message);

    // Free the argument memory and return
    free(args);
    return NULL;
}

int main(int argc, char** argv) {
    // Create an array of thread IDs
    pthread_t threads[5];

    // Create a counter for the thread IDs
    int i = 0;

    // Create some thread arguments
    struct ThreadArgs* args1 = (struct ThreadArgs*) malloc(sizeof(struct ThreadArgs));
    args1->id = i++;
    args1->sleep_time = 1;
    args1->message = "Hello from thread 1!";

    struct ThreadArgs* args2 = (struct ThreadArgs*) malloc(sizeof(struct ThreadArgs));
    args2->id = i++;
    args2->sleep_time = 3;
    args2->message = "Hello from thread 2!";

    struct ThreadArgs* args3 = (struct ThreadArgs*) malloc(sizeof(struct ThreadArgs));
    args3->id = i++;
    args3->sleep_time = 2;
    args3->message = "Hello from thread 3!";

    struct ThreadArgs* args4 = (struct ThreadArgs*) malloc(sizeof(struct ThreadArgs));
    args4->id = i++;
    args4->sleep_time = 4;
    args4->message = "Hello from thread 4!";

    struct ThreadArgs* args5 = (struct ThreadArgs*) malloc(sizeof(struct ThreadArgs));
    args5->id = i++;
    args5->sleep_time = 5;
    args5->message = "Hello from thread 5!";

    // Create the threads
    pthread_create(&threads[0], NULL, thread_function, args1);
    pthread_create(&threads[1], NULL, thread_function, args2);
    pthread_create(&threads[2], NULL, thread_function, args3);
    pthread_create(&threads[3], NULL, thread_function, args4);
    pthread_create(&threads[4], NULL, thread_function, args5);

    // Wait for the threads to finish
    for (i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}