//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_KEYS 100

struct key_value {
    char key[50];
    int value;
};

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *thread_func(void *arg) {
    int id = *(int *) arg;
    char thread_name[10];
    sprintf(thread_name, "Thread %d", id);
    pthread_setname_np(pthread_self(), thread_name);

    struct key_value *key_value = malloc(sizeof(struct key_value));
    key_value->key[0] = '\0';
    key_value->value = 0;

    while (1) {
        pthread_mutex_lock(&lock);
        printf("%s is waiting for a key...\n", thread_name);
        pthread_mutex_unlock(&lock);

        pthread_mutex_lock(&lock);
        if (key_value->key[0] == '\0') {
            printf("%s got an empty key!\n", thread_name);
        } else {
            printf("%s got key: %s\n", thread_name, key_value->key);
        }
        pthread_mutex_unlock(&lock);

        sleep(1);
    }

    free(key_value);
    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    int i;

    srand(time(NULL));

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_func, (void *) &i);
    }

    for (i = 0; i < MAX_KEYS; i++) {
        struct key_value *key_value = malloc(sizeof(struct key_value));
        key_value->key[0] = '\0';
        key_value->value = rand() % 100;

        pthread_mutex_lock(&lock);
        printf("Adding key: %s\n", key_value->key);
        pthread_mutex_unlock(&lock);

        sleep(1);
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}