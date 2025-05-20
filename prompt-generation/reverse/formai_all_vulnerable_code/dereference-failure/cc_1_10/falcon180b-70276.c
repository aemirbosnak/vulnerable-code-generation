//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_KEYS 1000
#define MAX_VALUES 10000

typedef struct {
    int key;
    int value;
} KeyValue;

KeyValue* database;
pthread_mutex_t lock;

void* thread_function(void* arg) {
    int thread_id = *(int*) arg;
    int i;

    for (i = thread_id * MAX_KEYS / MAX_THREADS; i < (thread_id + 1) * MAX_KEYS / MAX_THREADS && i < MAX_KEYS; i++) {
        int j;
        for (j = 0; j < MAX_VALUES; j++) {
            if (database[i * MAX_VALUES + j].key == -1) {
                pthread_mutex_lock(&lock);
                database[i * MAX_VALUES + j].key = i;
                pthread_mutex_unlock(&lock);
                break;
            }
        }
    }

    return NULL;
}

int main() {
    int i, j;
    pthread_t threads[MAX_THREADS];

    database = (KeyValue*) malloc(MAX_KEYS * MAX_VALUES * sizeof(KeyValue));
    for (i = 0; i < MAX_KEYS; i++) {
        for (j = 0; j < MAX_VALUES; j++) {
            database[i * MAX_VALUES + j].key = -1;
        }
    }

    pthread_mutex_init(&lock, NULL);

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_function, (void*) &i);
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    free(database);
    pthread_mutex_destroy(&lock);

    return 0;
}