//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: asynchronous
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<assert.h>
#include<pthread.h>

// struct to store the arguments for the fibonacci number calculation
typedef struct {
    int index;
    int *fib_array;
} fib_arg;

// function to calculate the nth fibonacci number
void *fib(void *arguments) {
    fib_arg *args = (fib_arg*) arguments;
    int n = args->index;
    if (args->fib_array[n-1] != 0) {
        pthread_exit(NULL);
    }
    if (n == 1 || n == 2) {
        args->fib_array[n-1] = 1;
        pthread_exit(NULL);
    }
    void *prev, *curr;
    pthread_t thread1, thread2;
    fib_arg args1, args2;
    prev = &args->fib_array[n-2];
    curr = &args->fib_array[n-3];
    args1.index = n-1;
    args1.fib_array = args->fib_array;
    args2.index = n-2;
    args2.fib_array = args->fib_array;
    pthread_create(&thread1, NULL, fib, &args1);
    pthread_create(&thread2, NULL, fib, &args2);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    args->fib_array[n-1] = *(int*)curr + *(int*)prev;
    pthread_exit(NULL);
}

int main() {
    int n;
    printf("Enter the length of the fibonacci sequence to generate: ");
    scanf("%d", &n);
    assert(n > 0 && n < 47);
    int *fib_array = (int*)calloc(n, sizeof(int));
    pthread_t thread1;
    fib_arg args1;
    args1.index = n;
    args1.fib_array = fib_array;
    pthread_create(&thread1, NULL, fib, &args1);
    pthread_join(thread1, NULL);
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", fib_array[i]);
        usleep(50000);
    }
    printf("\n");
    free(fib_array);
    return 0;
}