//Falcon2-11B DATASET v1.0 Category: Searching algorithm ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

typedef struct {
    int start, end;
    int *arr;
    int (*func)(int);
} AsyncTask;

void *do_async(void *task) {
    AsyncTask *task_ptr = (AsyncTask *)task;
    for (int i = task_ptr->start; i <= task_ptr->end; i++) {
        task_ptr->func(task_ptr->arr[i]);
    }
    pthread_exit(NULL);
}

int binary_search(int *arr, int n, int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    srand(time(NULL));
    int n = rand() % 100 + 1;
    int *arr = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
    int (*binary_search_func)(int *, int, int);
    binary_search_func = &binary_search;

    pthread_t threads[n];
    AsyncTask tasks[n];
    for (int i = 0; i < n; i++) {
        tasks[i].start = i;
        tasks[i].end = i + 1;
        tasks[i].arr = arr;
        tasks[i].func = binary_search_func;
        pthread_create(&threads[i], NULL, do_async, (void *)&tasks[i]);
    }
    for (int i = 0; i < n; i++) {
        pthread_join(threads[i], NULL);
    }
    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);
    return 0;
}