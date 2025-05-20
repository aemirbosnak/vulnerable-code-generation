//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX 10

// Structure for passing data to threads
struct v {
    int value;
    int from;
    int to;
};

// Function for moving disk
void *move_disk(void *arg) {
    struct v *data = (struct v *) arg;
    int value = data->value;
    int from = data->from;
    int to = data->to;

    // Move disk from source to destination
    printf("Moving disk %d from rod %d to rod %d\n", value, from, to);

    // Wait for 2 seconds
    sleep(2);

    // Move disk from source to destination
    printf("Moving disk %d from rod %d to rod %d\n", value, to, from);

    // Exit the thread
    pthread_exit(0);
}

int main() {
    pthread_t threads[MAX];
    int value = MAX - 1;
    int from = 0;
    int to = 2;

    // Move n disks from source to destination
    for (int i = MAX - 1; i >= 1; i--) {
        // Create a thread for each disk
        pthread_create(&threads[i], NULL, move_disk, (void *) &i);

        // Wait for thread to complete
        pthread_join(threads[i], NULL);
    }

    return 0;
}