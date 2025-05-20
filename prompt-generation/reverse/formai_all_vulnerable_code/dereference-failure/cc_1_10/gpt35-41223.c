//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct {
    int *arr;
    int start;
    int end;
} ArraySegment;

void *sortSegment(void *arg) {
    ArraySegment *seg = (ArraySegment *) arg;
    int *arr = seg->arr;
    int start = seg->start;
    int end = seg->end;

    // insertion sort
    for (int i = start + 1; i <= end; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= start && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    pthread_exit(NULL);
}

void merge(int *arr, int start, int middle, int end) {
    int *temp = (int *) malloc((end - start + 1) * sizeof(int));
    int i = start, j = middle + 1, k = 0;
    while (i <= middle && j <= end) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= middle) {
        temp[k++] = arr[i++];
    }

    while (j <= end) {
        temp[k++] = arr[j++];
    }

    for (i = start, k = 0; i <= end; i++, k++) {
        arr[i] = temp[k];
    }

    free(temp);
}

void *mergeSort(void *arg) {
    ArraySegment *seg = (ArraySegment *) arg;
    int *arr = seg->arr;
    int start = seg->start;
    int end = seg->end;

    if (start >= end) {
        pthread_exit(NULL);
    }

    if (end - start <= 10) {
        // use insertion sort for small segments
        for (int i = start + 1; i <= end; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= start && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
        pthread_exit(NULL);
    }

    int middle = (start + end) / 2;

    pthread_t left_tid, right_tid;
    ArraySegment left = { arr, start, middle };
    ArraySegment right = { arr, middle + 1, end };
    pthread_create(&left_tid, NULL, mergeSort, &left);
    pthread_create(&right_tid, NULL, mergeSort, &right);

    // wait for threads to finish
    pthread_join(left_tid, NULL);
    pthread_join(right_tid, NULL);
    
    // merge the two sorted segments
    merge(arr, start, middle, end);

    pthread_exit(NULL);
}

int main() {
    int n = 100000;
    int *arr = (int *) malloc(n * sizeof(int));

    // populate the array with random numbers
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    // sort the array using multiple threads
    ArraySegment full = { arr, 0, n - 1 };
    pthread_t tid;
    pthread_create(&tid, NULL, mergeSort, &full);
    pthread_join(tid, NULL);

    // print the sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}