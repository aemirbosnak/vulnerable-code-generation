//Gemma-7B DATASET v1.0 Category: File Synchronizer ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct FileSynchronizer {
    char buffer[BUFFER_SIZE];
    int head, tail, size, is_locked;
} FileSynchronizer;

FileSynchronizer* file_synchronizer_init() {
    FileSynchronizer* synchronizer = malloc(sizeof(FileSynchronizer));
    synchronizer->head = 0;
    synchronizer->tail = 0;
    synchronizer->size = 0;
    synchronizer->is_locked = 0;

    return synchronizer;
}

void file_synchronizer_add(FileSynchronizer* synchronizer, char data) {
    if (synchronizer->size == BUFFER_SIZE) {
        return;
    }

    synchronizer->buffer[synchronizer->tail] = data;
    synchronizer->tail = (synchronizer->tail + 1) % BUFFER_SIZE;
    synchronizer->size++;
}

char file_synchronizer_read(FileSynchronizer* synchronizer) {
    if (synchronizer->size == 0) {
        return -1;
    }

    synchronizer->head = (synchronizer->head + 1) % BUFFER_SIZE;
    char data = synchronizer->buffer[synchronizer->head];
    synchronizer->size--;

    return data;
}

void file_synchronizer_lock(FileSynchronizer* synchronizer) {
    synchronizer->is_locked = 1;
}

void file_synchronizer_unlock(FileSynchronizer* synchronizer) {
    synchronizer->is_locked = 0;
}

int main() {
    FileSynchronizer* synchronizer = file_synchronizer_init();

    // Simulate file operations
    file_synchronizer_add(synchronizer, 'a');
    file_synchronizer_add(synchronizer, 'b');
    file_synchronizer_add(synchronizer, 'c');
    file_synchronizer_lock(synchronizer);
    file_synchronizer_add(synchronizer, 'd');
    file_synchronizer_unlock(synchronizer);

    char data = file_synchronizer_read(synchronizer);
    if (data != -1) {
        printf("%c", data);
    }

    return 0;
}