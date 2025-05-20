//Gemma-7B DATASET v1.0 Category: File Synchronizer ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

typedef struct FileSynchronizer {
    char *filename;
    int file_size;
    char *buffer;
    int buffer_size;
    int read_position;
    int write_position;
    int lock;
} FileSynchronizer;

FileSynchronizer *file_synchronizer_init(char *filename, int file_size) {
    FileSynchronizer *synchronizer = malloc(sizeof(FileSynchronizer));
    synchronizer->filename = strdup(filename);
    synchronizer->file_size = file_size;
    synchronizer->buffer = malloc(file_size);
    synchronizer->buffer_size = file_size;
    synchronizer->read_position = 0;
    synchronizer->write_position = 0;
    synchronizer->lock = 0;

    return synchronizer;
}

void file_synchronizer_write(FileSynchronizer *synchronizer, char *data, int data_size) {
    if (synchronizer->lock) {
        return;
    }

    synchronizer->lock = 1;

    int remaining_space = synchronizer->buffer_size - synchronizer->write_position;
    int bytes_to_write = data_size < remaining_space ? data_size : remaining_space;

    memcpy(synchronizer->buffer + synchronizer->write_position, data, bytes_to_write);
    synchronizer->write_position += bytes_to_write;

    if (synchronizer->write_position == synchronizer->buffer_size) {
        synchronizer->write_position = 0;
    }

    synchronizer->lock = 0;
}

void file_synchronizer_read(FileSynchronizer *synchronizer, char *data, int data_size) {
    if (synchronizer->lock) {
        return;
    }

    synchronizer->lock = 1;

    int remaining_data = synchronizer->read_position + data_size < synchronizer->file_size ? data_size : synchronizer->file_size - synchronizer->read_position;
    int bytes_to_read = remaining_data < data_size ? remaining_data : data_size;

    memcpy(data, synchronizer->buffer + synchronizer->read_position, bytes_to_read);
    synchronizer->read_position += bytes_to_read;

    if (synchronizer->read_position == synchronizer->file_size) {
        synchronizer->read_position = 0;
    }

    synchronizer->lock = 0;
}

int main() {
    FileSynchronizer *synchronizer = file_synchronizer_init("test.txt", 1024);

    // Write data to the file
    file_synchronizer_write(synchronizer, "Hello, world!", 13);

    // Read data from the file
    char data[1024];
    file_synchronizer_read(synchronizer, data, 10);

    // Print the data
    printf("%s", data);

    return 0;
}