//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX 1000000

// Struct for passing data to threads
struct v {
    int start;
    int end;
};

// Function to be executed by each thread
void *runner(void *param) {
    struct v *data = (struct v *) param;
    int i, key, cmp;
    int *arr = (int *) malloc(data->end - data->start + 1);

    for (i = data->start; i <= data->end; i++) {
        arr[i - data->start] = i;
    }

    qsort(arr, data->end - data->start + 1, sizeof(int), cmp);

    free(arr);
    return NULL;
}

// Main function
int main() {
    int i, c, *arr = (int *) malloc(MAX * sizeof(int));
    pthread_t threads[4];
    struct v data[4];

    // Populate array with random integers
    for (i = 0; i < MAX; i++) {
        arr[i] = rand() % MAX;
    }

    // Divide work among threads
    for (i = 0; i < 4; i++) {
        data[i].start = i * (MAX / 4);
        data[i].end = (i + 1) * (MAX / 4) - 1;
    }

    // Create threads
    for (i = 0; i < 4; i++) {
        pthread_create(&threads[i], NULL, runner, (void *) &data[i]);
    }

    // Join threads
    for (i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print sorted array
    for (i = 0; i < MAX; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}