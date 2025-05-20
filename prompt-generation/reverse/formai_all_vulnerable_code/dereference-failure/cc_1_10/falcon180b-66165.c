//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MAX_NUM 1000000
#define NUM_BUCKETS 10
#define NUM_THREADS 4

int *arr;
int *buckets[NUM_BUCKETS];
pthread_t threads[NUM_THREADS];
pthread_mutex_t lock;

void init_arr() {
    arr = (int*) malloc(MAX_NUM * sizeof(int));
    for (int i = 0; i < MAX_NUM; i++) {
        arr[i] = rand() % MAX_NUM;
    }
}

void init_buckets() {
    for (int i = 0; i < NUM_BUCKETS; i++) {
        buckets[i] = (int*) malloc(MAX_NUM * sizeof(int));
    }
}

void *bucket_sort_thread(void *param) {
    int thread_id = *(int*) param;
    int start_index = thread_id * MAX_NUM / NUM_THREADS;
    int end_index = (thread_id + 1) * MAX_NUM / NUM_THREADS;

    for (int i = start_index; i < end_index; i++) {
        pthread_mutex_lock(&lock);
        int bucket_index = arr[i] / MAX_NUM;
        buckets[bucket_index][buckets[bucket_index][0]++] = arr[i];
        pthread_mutex_unlock(&lock);
    }
}

void merge_buckets() {
    int index = 0;
    for (int i = 0; i < NUM_BUCKETS; i++) {
        for (int j = 0; j < buckets[i][0]; j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

int main() {
    srand(time(NULL));
    init_arr();
    init_buckets();

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, bucket_sort_thread, (void*) &i);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    merge_buckets();

    for (int i = 0; i < MAX_NUM; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}