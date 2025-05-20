//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_KEYS 100

typedef struct {
    char *key;
    int value;
} KeyValue;

typedef struct {
    int start;
    int end;
} ThreadData;

KeyValue *database;
pthread_mutex_t mutex;

void *thread_func(void *arg) {
    ThreadData *data = (ThreadData *) arg;
    int i;

    for (i = data->start; i <= data->end; i++) {
        pthread_mutex_lock(&mutex);
        database[i].value++;
        pthread_mutex_unlock(&mutex);
    }

    return NULL;
}

int main() {
    int i;
    pthread_t threads[MAX_THREADS];

    database = (KeyValue *) malloc(MAX_KEYS * sizeof(KeyValue));
    if (database == NULL) {
        printf("Error: could not allocate memory for database\n");
        exit(1);
    }

    for (i = 0; i < MAX_KEYS; i++) {
        database[i].key = (char *) malloc(10 * sizeof(char));
        if (database[i].key == NULL) {
            printf("Error: could not allocate memory for key %d\n", i);
            exit(1);
        }
        sprintf(database[i].key, "key_%d", i);
        database[i].value = 0;
    }

    pthread_mutex_init(&mutex, NULL);

    for (i = 0; i < MAX_THREADS; i++) {
        ThreadData *data = (ThreadData *) malloc(sizeof(ThreadData));
        if (data == NULL) {
            printf("Error: could not allocate memory for thread data %d\n", i);
            exit(1);
        }
        data->start = i * (MAX_KEYS / MAX_THREADS);
        data->end = (i == MAX_THREADS - 1)? MAX_KEYS - 1 : (i + 1) * (MAX_KEYS / MAX_THREADS) - 1;
        pthread_create(threads + i, NULL, thread_func, data);
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    for (i = 0; i < MAX_KEYS; i++) {
        printf("key: %s, value: %d\n", database[i].key, database[i].value);
    }

    free(database);
    pthread_mutex_destroy(&mutex);

    return 0;
}