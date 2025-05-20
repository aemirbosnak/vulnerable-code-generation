//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX 100

// Structure for passing data between threads
struct v {
    int value;
    int from;
    int to;
};

// Function to be executed by each thread
void *runner(void *param) {
    struct v *data = param;
    int value = data->value;
    int from = data->from;
    int to = data->to;

    // Move the disk from source to destination
    printf("Moving disk %d from rod %d to rod %d\n", value, from, to);

    // Wait for 1 second
    sleep(1);

    // Signal the main thread that the move is complete
    pthread_exit(0);
}

void move(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;
    }

    move(n - 1, from_rod, aux_rod, to_rod);

    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);

    sleep(1);

    move(n - 1, aux_rod, to_rod, from_rod);
}

int main() {
    pthread_t thread_id[MAX];
    int i, value;

    // Create threads
    for (i = 1; i <= MAX; i++) {
        pthread_create(&thread_id[i], NULL, runner, (void *)&value);
        printf("Created thread %d\n", i);
    }

    // Join with all threads
    for (i = 1; i <= MAX; i++) {
        pthread_join(thread_id[i], NULL);
    }

    return 0;
}