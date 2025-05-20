//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_BUCKETS 100
#define MAX_VAL 1000000

int *arr;
int n;
int bucket_size;
pthread_mutex_t mutex;

void *bucket_sort(void *param) {
    int i, j, k;
    int start, end;
    int *bucket;

    start = (int) param * bucket_size;
    end = (start + bucket_size - 1) % n;

    bucket = (int *) malloc(sizeof(int) * (end - start + 1));

    for (i = start; i <= end; i++) {
        pthread_mutex_lock(&mutex);
        bucket[arr[i] / MAX_VAL]++;
        pthread_mutex_unlock(&mutex);
    }

    for (i = 0; i < MAX_BUCKETS; i++) {
        if (bucket[i]!= 0) {
            for (j = start; j <= end; j++) {
                if (arr[j] / MAX_VAL == i) {
                    arr[j] = arr[j] % MAX_VAL;
                    k = j;
                    while (k > start && arr[k - 1] > arr[j]) {
                        arr[k] = arr[k - 1];
                        k--;
                    }
                    arr[k] = arr[j];
                }
            }
        }
    }

    free(bucket);
}

void bucket_sort_multi_threaded(int num_threads) {
    int i;
    pthread_t threads[num_threads];

    bucket_size = n / num_threads;

    pthread_mutex_init(&mutex, NULL);

    for (i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, bucket_sort, (void *) i);
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
}

int main() {
    int i;
    int num_threads;
    int *input_arr;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    arr = (int *) malloc(sizeof(int) * n);

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

    input_arr = arr;
    bucket_sort_multi_threaded(num_threads);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}