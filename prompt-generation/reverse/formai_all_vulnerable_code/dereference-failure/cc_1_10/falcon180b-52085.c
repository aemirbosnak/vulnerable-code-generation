//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4

int value;
int base;
char *result;

void *convert(void *arg) {
    int thread_id = *(int *) arg;
    int start = thread_id * 4;
    int end = (thread_id + 1) * 4;

    for (int i = start; i < end; i++) {
        char c = (char) ('0' + (value % base) & 15);
        result[i] = c;
        value /= base;
    }

    return NULL;
}

int main() {
    int num_threads;
    scanf("%d", &num_threads);

    if (num_threads < 1 || num_threads > 4) {
        printf("Invalid number of threads.\n");
        return -1;
    }

    pthread_t threads[NUM_THREADS];
    int ids[NUM_THREADS];

    result = (char *) malloc(16 * sizeof(char));
    result[15] = '\0';

    printf("Enter the base: ");
    scanf("%d", &base);

    printf("Enter the value: ");
    scanf("%d", &value);

    for (int i = 0; i < num_threads; i++) {
        ids[i] = i;
        pthread_create(&threads[i], NULL, convert, &ids[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Binary representation: %s\n", result);

    return 0;
}