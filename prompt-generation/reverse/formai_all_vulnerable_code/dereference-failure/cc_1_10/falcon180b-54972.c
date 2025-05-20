//Falcon-180B DATASET v1.0 Category: Memory management ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#define MAX_SIZE 1024 * 1024 * 10 // 10 MB

typedef struct {
    char *data;
    size_t size;
    int ref_count;
} Buffer;

Buffer *buffer_create(size_t size) {
    Buffer *buffer = (Buffer *) malloc(sizeof(Buffer));
    if (buffer == NULL) {
        fprintf(stderr, "Failed to allocate memory for buffer\n");
        exit(1);
    }
    buffer->data = (char *) malloc(size);
    if (buffer->data == NULL) {
        fprintf(stderr, "Failed to allocate memory for buffer data\n");
        exit(1);
    }
    buffer->size = size;
    buffer->ref_count = 1;
    return buffer;
}

void buffer_destroy(Buffer *buffer) {
    if (buffer == NULL) {
        return;
    }
    if (buffer->ref_count > 0) {
        buffer->ref_count--;
    } else {
        free(buffer->data);
        free(buffer);
    }
}

void buffer_retain(Buffer *buffer) {
    if (buffer == NULL) {
        return;
    }
    buffer->ref_count++;
}

void buffer_release(Buffer *buffer) {
    if (buffer == NULL) {
        return;
    }
    buffer->ref_count--;
    if (buffer->ref_count == 0) {
        free(buffer->data);
        free(buffer);
    }
}

char *buffer_data(Buffer *buffer) {
    if (buffer == NULL) {
        return NULL;
    }
    return buffer->data;
}

size_t buffer_size(Buffer *buffer) {
    if (buffer == NULL) {
        return 0;
    }
    return buffer->size;
}

int main() {
    Buffer *data = NULL;
    FILE *file = fopen("data.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Failed to open file data.txt\n");
        exit(1);
    }
    fseek(file, 0, SEEK_END);
    size_t file_size = ftell(file);
    rewind(file);
    data = buffer_create(file_size);
    if (data == NULL) {
        fprintf(stderr, "Failed to allocate memory for buffer\n");
        exit(1);
    }
    size_t bytes_read = fread(data->data, 1, file_size, file);
    if (bytes_read!= file_size) {
        fprintf(stderr, "Failed to read entire file\n");
        exit(1);
    }
    fclose(file);
    printf("File data:\n%s\n", data->data);
    buffer_release(data);
    return 0;
}