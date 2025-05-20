//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N 3

// Structure for passing data between threads
struct v {
    int from;
    int to;
    int *arr;
};

void *runner(void *param);

int main() {
    int i, j;
    pthread_t threads[N];
    int arr[N] = { 1, 2, 3 };

    // Initialize the auxiliary and target stacks
    int aux[N];
    for (i = 0; i < N; i++)
        aux[i] = -1;

    int target[N];
    for (i = 0; i < N; i++)
        target[i] = -1;

    // Set the initial position of the disks
    for (i = N - 1; i >= 0; i--)
        target[i] = i;

    // Create threads
    for (i = 0; i < N; i++) {
        struct v *data = malloc(sizeof(struct v));
        data->from = 0;
        data->to = i;
        data->arr = arr;
        pthread_create(&threads[i], NULL, runner, data);
    }

    // Join threads
    for (i = 0; i < N; i++)
        pthread_join(threads[i], NULL);

    for (i = 0; i < N; i++)
        printf("%d ", arr[i]);

    return 0;
}

void *runner(void *param) {
    struct v *data = param;
    int from = data->from;
    int to = data->to;
    int *arr = data->arr;

    // Move n-1 disks from source to auxiliary
    if (from!= to) {
        int aux = -1;
        for (int i = from; i >= to; i--) {
            if (arr[i]!= -1 && aux!= -1 && arr[i]!= aux) {
                printf("Moving disk %d from rod %d to rod %d\n", arr[i], from, to);
                printf("Moving disk %d from rod %d to auxiliary\n", arr[i], from);
                arr[i] = -1;
                aux = i;
            }
        }
        printf("Moving disk %d from rod %d to rod %d\n", arr[from], from, to);
        arr[to] = arr[from];
        arr[from] = -1;
    }

    // Move the last disk
    else {
        printf("Moving disk %d from rod %d to rod %d\n", arr[from], from, to);
        arr[to] = arr[from];
        arr[from] = -1;
    }

    free(data);
}