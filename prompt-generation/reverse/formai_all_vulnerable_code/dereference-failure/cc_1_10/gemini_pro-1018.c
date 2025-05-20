//GEMINI-pro DATASET v1.0 Category: Pattern printing ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

typedef struct {
    int n;
    int *arr;
} thread_args;

void *print_pattern(void *arg) {
    thread_args *args = (thread_args *)arg;
    int n = args->n;
    int *arr = args->arr;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i * n + j] == 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return NULL;
}

int main() {
    int n;
    printf("Enter the size of the pattern: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * n * sizeof(int));
    for (int i = 0; i < n * n; i++) {
        arr[i] = rand() % 2;
    }

    pthread_t threads[n];
    thread_args args[n];

    for (int i = 0; i < n; i++) {
        args[i].n = n;
        args[i].arr = arr;
        pthread_create(&threads[i], NULL, print_pattern, &args[i]);
    }

    for (int i = 0; i < n; i++) {
        pthread_join(threads[i], NULL);
    }

    free(arr);
    return 0;
}