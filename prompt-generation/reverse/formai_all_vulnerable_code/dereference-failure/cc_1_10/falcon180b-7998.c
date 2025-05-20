//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MAX_THREADS 4

typedef struct {
    int start;
    int end;
} thread_data;

void *thread_function(void *param) {
    thread_data *data = (thread_data *) param;
    int i;
    
    for (i = data->start; i <= data->end; i++) {
        printf("%d ", i);
    }
    printf("\n");

    return NULL;
}

int main() {
    int num_threads;
    pthread_t threads[MAX_THREADS];
    int i, j;
    int num_elements = 20;
    int bucket_size = num_elements / MAX_THREADS;
    int *array = (int *) malloc(num_elements * sizeof(int));
    int *buckets[MAX_THREADS];

    srand(time(NULL));

    // Fill the array with random integers
    for (i = 0; i < num_elements; i++) {
        array[i] = rand() % 100;
    }

    // Create the buckets
    for (i = 0; i < MAX_THREADS; i++) {
        buckets[i] = (int *) malloc(bucket_size * sizeof(int));
    }

    // Distribute the elements into the buckets
    for (i = 0; i < num_elements; i++) {
        j = i / bucket_size;
        buckets[j][i % bucket_size] = array[i];
    }

    // Sort each bucket
    for (i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_function, (void *) &(thread_data){.start = 0,.end = bucket_size - 1});
    }

    // Join each thread
    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Merge the sorted buckets back into the original array
    int k = 0;
    for (i = 0; i < MAX_THREADS; i++) {
        for (j = 0; j < bucket_size; j++) {
            array[k++] = buckets[i][j];
        }
    }

    // Print the sorted array
    for (i = 0; i < num_elements; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}