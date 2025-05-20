//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define NUM_THREADS 2
#define STACK_SIZE 1000

int fib_stack[NUM_THREADS][STACK_SIZE];
int top[NUM_THREADS] = {0};
int lock = 0;

void push(int n, int value) {
    if (top[n] == STACK_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    fib_stack[n][++top[n]] = value;
}

int pop(int n) {
    if (top[n] == 0) {
        printf("Stack Underflow\n");
        return -1;
    }
    return fib_stack[n][top[n]--];
}

void *producer(void *arg) {
    int n = *(int *) arg;
    int count = 0;
    while (count < 10) {
        pthread_mutex_lock(&lock);
        push(n, count);
        pthread_mutex_unlock(&lock);
        count++;
        sleep(1);
    }
    return NULL;
}

void *consumer(void *arg) {
    int n = *(int *) arg;
    while (1) {
        pthread_mutex_lock(&lock);
        int value = pop(n);
        if (value == -1) {
            pthread_mutex_unlock(&lock);
            break;
        }
        printf("Consumer %d popped value: %d\n", n, value);
        pthread_mutex_unlock(&lock);
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int ids[NUM_THREADS];

    srand(time(NULL));

    for (int i = 0; i < NUM_THREADS; i++) {
        ids[i] = i;
        pthread_create(&threads[i], NULL, (i % 2 == 0)? producer : consumer, &ids[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}