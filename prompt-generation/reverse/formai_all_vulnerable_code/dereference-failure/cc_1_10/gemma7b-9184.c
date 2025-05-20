//Gemma-7B DATASET v1.0 Category: File Synchronizer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 10

typedef struct FileSynchronizer {
    char buffer[BUFFER_SIZE];
    int head;
    int tail;
    int mutex;
} FileSynchronizer;

FileSynchronizer* file_synchronizer_init() {
    FileSynchronizer* synchronizer = malloc(sizeof(FileSynchronizer));
    synchronizer->head = 0;
    synchronizer->tail = 0;
    synchronizer->mutex = 0;
    return synchronizer;
}

void file_synchronizer_add(FileSynchronizer* synchronizer, char data) {
    pthread_mutex_lock(&synchronizer->mutex);

    if ((synchronizer->tail - synchronizer->head) == BUFFER_SIZE - 1) {
        synchronizer->tail = (synchronizer->tail + 1) % BUFFER_SIZE;
    }

    synchronizer->buffer[synchronizer->head] = data;
    synchronizer->head = (synchronizer->head + 1) % BUFFER_SIZE;

    pthread_mutex_unlock(&synchronizer->mutex);
}

int file_synchronizer_read(FileSynchronizer* synchronizer) {
    pthread_mutex_lock(&synchronizer->mutex);

    if (synchronizer->head == synchronizer->tail) {
        return -1;
    }

    int data = synchronizer->buffer[synchronizer->tail];
    synchronizer->tail = (synchronizer->tail + 1) % BUFFER_SIZE;

    pthread_mutex_unlock(&synchronizer->mutex);

    return data;
}

int main() {
    FileSynchronizer* synchronizer = file_synchronizer_init();

    // Simulate some file operations
    file_synchronizer_add(synchronizer, 'a');
    file_synchronizer_add(synchronizer, 'b');
    file_synchronizer_add(synchronizer, 'c');

    int data = file_synchronizer_read(synchronizer);
    if (data != -1) {
        printf("Read data: %c\n", data);
    }

    return 0;
}