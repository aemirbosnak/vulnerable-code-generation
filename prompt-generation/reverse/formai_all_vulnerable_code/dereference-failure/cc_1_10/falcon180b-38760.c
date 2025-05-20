//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NUM_TASKS 10
#define STACK_SIZE 100

typedef struct {
    int (*func)(void *arg);
    void *arg;
} task_t;

void task_scheduler(task_t tasks[], int num_tasks) {
    int i, j;
    for (i = 0; i < num_tasks; i++) {
        tasks[i].func(tasks[i].arg);
    }
}

int fibonacci(void *arg) {
    int n = *(int *) arg;
    int result = fibonacci_recursive(n);
    printf("Fibonacci number %d is %d\n", n, result);
    return 0;
}

int fibonacci_recursive(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
    }
}

int factorial(void *arg) {
    int n = *(int *) arg;
    int result = factorial_recursive(n);
    printf("Factorial of %d is %d\n", n, result);
    return 0;
}

int factorial_recursive(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial_recursive(n - 1);
    }
}

int main() {
    srand(time(NULL));

    task_t tasks[NUM_TASKS];

    for (int i = 0; i < NUM_TASKS; i++) {
        int n = rand() % 20 + 1;
        tasks[i].func = (i % 2 == 0)? fibonacci : factorial;
        tasks[i].arg = malloc(sizeof(int));
        *(int *) tasks[i].arg = n;
    }

    task_scheduler(tasks, NUM_TASKS);

    for (int i = 0; i < NUM_TASKS; i++) {
        free(tasks[i].arg);
    }

    return 0;
}