//GEMINI-pro DATASET v1.0 Category: Threading Library Implementation ; Style: surrealist
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct surreal_thread_args {
    int *a;
    int *b;
};

void *surreal_thread_main(void *args) {
    struct surreal_thread_args *thread_args = (struct surreal_thread_args *)args;
    int *a = thread_args->a;
    int *b = thread_args->b;

    // The thread's surreal task:
    // Increase the value of *a by one,
    // but only if the value of *b is greater than *a.
    // If the condition is not met, decrease the value of *b by one.

    if (*b > *a) {
        *a += 1;
    } else {
        *b -= 1;
    }

    // Free the thread arguments.
    free(thread_args);

    // Return NULL to indicate successful thread execution.
    return NULL;
}

int main() {
    // Declare and initialize two integer variables.
    int a = 5;
    int b = 10;

    // Create a surreal thread.
    struct surreal_thread_args *thread_args = malloc(sizeof(struct surreal_thread_args));
    thread_args->a = &a;
    thread_args->b = &b;
    pthread_t thread;
    pthread_create(&thread, NULL, surreal_thread_main, thread_args);

    // Wait for the thread to finish.
    pthread_join(thread, NULL);

    // Print the final values of a and b.
    printf("a = %d\n", a);
    printf("b = %d\n", b);

    return 0;
}