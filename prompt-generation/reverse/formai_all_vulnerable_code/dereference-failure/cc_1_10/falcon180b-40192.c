//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_KEY_LEN 100
#define MAX_VALUE_LEN 1000
#define MAX_THREADS 10

typedef struct {
    char key[MAX_KEY_LEN];
    char value[MAX_VALUE_LEN];
} Record;

typedef struct {
    int start;
    int end;
} ThreadData;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *thread_func(void *arg) {
    ThreadData *data = (ThreadData *) arg;
    int i;

    for (i = data->start; i <= data->end; i++) {
        Record record;
        sprintf(record.key, "key_%d", i);
        sprintf(record.value, "value_%d", i);

        // Do some indexing operation here

        printf("Thread %d indexed record %s\n", pthread_self(), record.key);
    }

    return NULL;
}

int main() {
    int i;
    pthread_t threads[MAX_THREADS];

    for (i = 0; i < MAX_THREADS; i++) {
        ThreadData data;
        data.start = i * 1000;
        data.end = (i + 1) * 1000 - 1;
        pthread_create(&threads[i], NULL, thread_func, &data);
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}