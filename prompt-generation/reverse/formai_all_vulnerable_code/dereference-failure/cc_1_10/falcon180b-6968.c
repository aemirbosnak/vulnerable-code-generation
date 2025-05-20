//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define a structure for passing data to threads
struct v {
    int *a;
    int n;
};

// Function to be executed by the thread
void *runner(void *arg) {
    struct v *v = arg;
    int i, sum = 0;

    // Do some work
    for(i = 0; i < v->n; i++) {
        sum += v->a[i];
    }

    // Print the result
    printf("The sum is: %d\n", sum);

    // Exit the thread
    return NULL;
}

// Main function
int main(int argc, char **argv) {
    pthread_t threads[5];
    int i, sum = 0, n = 10;
    int *a = malloc(n * sizeof(int));
    struct v data;

    // Initialize the array
    for(i = 0; i < n; i++) {
        a[i] = i + 1;
        sum += a[i];
    }

    // Create the threads
    for(i = 0; i < 5; i++) {
        data.a = a;
        data.n = n;
        pthread_create(&threads[i], NULL, runner, &data);
    }

    // Join the threads
    for(i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the final result
    printf("The final sum is: %d\n", sum);

    // Exit the program
    return 0;
}