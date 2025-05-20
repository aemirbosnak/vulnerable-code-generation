//FormAI DATASET v1.0 Category: Database simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_SIZE 100

int data[MAX_SIZE];
int size = 0;

pthread_mutex_t mutex;

void insert_data(int value) {
    pthread_mutex_lock(&mutex);
    if (size < MAX_SIZE) {
        data[size] = value;
        ++size;
        printf("Value %d inserted successfully\n", value);
    } else {
        printf("Database is full!\n");
    }
    pthread_mutex_unlock(&mutex);
}

void delete_data() {
    pthread_mutex_lock(&mutex);
    if (size > 0) {
        --size;
        printf("Value %d deleted successfully\n", data[size]);
    } else {
        printf("Database is empty!\n");
    }
    pthread_mutex_unlock(&mutex);
}

void* producer(void* args) {
    int id = *(int*)args;
    for (int i = 0; i < 5; ++i) {
        insert_data(id * 10 + i);
    }
    return NULL;
}

void* consumer(void* args) {
    int id = *(int*)args;
    for (int i = 0; i < 5; ++i) {
        delete_data();
    }
    return NULL;
}

int main() {
    pthread_t threads[5];
    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < 2; ++i) {
        int* id = malloc(sizeof(int));
        *id = i;
        pthread_create(&threads[i], NULL, producer, id);
    }

    for (int i = 2; i < 5; ++i) {
        int* id = malloc(sizeof(int));
        *id = i;
        pthread_create(&threads[i], NULL, consumer, id);
    }

    for (int i = 0; i < 5; ++i) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);

    return 0;
}