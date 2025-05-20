//FormAI DATASET v1.0 Category: Bitwise operations ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <pthread.h>

typedef struct {
    uint8_t in1;
    uint8_t in2;
    uint8_t out;
} operation_t;

void *and_thread(void *op) {
    operation_t *operation = (operation_t *) op;
    operation->out = operation->in1 & operation->in2;
    printf("AND operation: %d & %d = %d\n", operation->in1, operation->in2, operation->out);
    return NULL;
}

void *or_thread(void *op) {
    operation_t *operation = (operation_t *) op;
    operation->out = operation->in1 | operation->in2;
    printf("OR operation: %d | %d = %d\n", operation->in1, operation->in2, operation->out);
    return NULL;
}

void *xor_thread(void *op) {
    operation_t *operation = (operation_t *) op;
    operation->out = operation->in1 ^ operation->in2;
    printf("XOR operation: %d ^ %d = %d\n", operation->in1, operation->in2, operation->out);
    return NULL;
}

int main() {
    srand(time(NULL));

    // Create 10 random operations
    operation_t *ops = (operation_t *) malloc(sizeof(operation_t) * 10);
    for (int i = 0; i < 10; i++) {
        ops[i].in1 = rand() % 256;
        ops[i].in2 = rand() % 256;
    }

    // Create threads for each operation
    pthread_t *threads = (pthread_t *) malloc(sizeof(pthread_t) * 3 * 10);
    for (int i = 0; i < 10; i++) {
        pthread_create(&threads[i * 3], NULL, and_thread, (void *) &ops[i]);
        pthread_create(&threads[i * 3 + 1], NULL, or_thread, (void *) &ops[i]);
        pthread_create(&threads[i * 3 + 2], NULL, xor_thread, (void *) &ops[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < 30; i++) {
        pthread_join(threads[i], NULL);
    }

    free(ops);
    free(threads);
    return 0;
}