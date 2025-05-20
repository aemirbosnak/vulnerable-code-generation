//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define NUM_THREADS 4
#define MAX_KEY_LEN 20
#define MAX_VALUE_LEN 100
#define MAX_NUM_ENTRIES 100

typedef struct {
    char key[MAX_KEY_LEN];
    char value[MAX_VALUE_LEN];
} entry_t;

typedef struct {
    pthread_mutex_t lock;
    int num_entries;
    entry_t entries[MAX_NUM_ENTRIES];
} database_t;

void *thread_func(void *arg) {
    char *thread_name = (char *) arg;
    int thread_num = atoi(thread_name);

    database_t *db = (database_t *) malloc(sizeof(database_t));
    db->num_entries = 0;

    for (int i = 0; i < 10; i++) {
        entry_t entry;
        sprintf(entry.key, "key_%d_%d", thread_num, i);
        sprintf(entry.value, "value_%d_%d", thread_num, i);

        pthread_mutex_lock(&db->lock);
        if (db->num_entries < MAX_NUM_ENTRIES) {
            db->entries[db->num_entries++] = entry;
        }
        pthread_mutex_unlock(&db->lock);
    }

    free(db);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    char *thread_names[NUM_THREADS] = {"thread1", "thread2", "thread3", "thread4"};

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_func, (void *) thread_names[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}