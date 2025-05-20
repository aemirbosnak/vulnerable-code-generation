//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define MAX 100

int Fibonacci[MAX];

typedef struct {
    int start;
    int end;
} parameters;

void *fibonacci_seq(void *arg) {
    parameters *param = arg;
    int start = param->start;
    int end = param->end;
    Fibonacci[start] = 0;
    Fibonacci[start+1] = 1;
    for (int i = start+2; i <= end; i++) {
        Fibonacci[i] = Fibonacci[i-1] + Fibonacci[i-2];
    }
    pthread_exit(0);
}

void print_fibonacci(int N) {
    for (int i = 0; i < N; i++) {
        printf("%d ", Fibonacci[i]);
    }
    printf("\n");
}

int main() {
    int N, n_threads, remainder;
    parameters *param;
    pthread_t *threads;

    printf("Enter the number of terms in the Fibonacci sequence: ");
    scanf("%d", &N);

    printf("Enter the number of threads: ");
    scanf("%d", &n_threads);

    threads = (pthread_t *) malloc(n_threads*sizeof(pthread_t));
    param = (parameters *) malloc(n_threads*sizeof(parameters));

    remainder = N % n_threads;
    int block_size = N / n_threads;

    for (int i = 0; i < n_threads; i++) {
        param[i].start = i * block_size;
        param[i].end = (i+1) * block_size - 1;
    }
    param[n_threads-1].end += remainder;

    for (int i = 0; i < n_threads; i++) {
        pthread_create(&threads[i], NULL, fibonacci_seq, &param[i]);
    }

    for (int i = 0; i < n_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    print_fibonacci(N);

    free(param);
    free(threads);

    return 0;
}