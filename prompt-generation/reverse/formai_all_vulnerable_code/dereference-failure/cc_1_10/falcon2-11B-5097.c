//Falcon2-11B DATASET v1.0 Category: Ebook reader ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>
#include <dirent.h>
#include <pthread.h>

#define BUF_SIZE 4096

typedef struct {
    char *buf;
    int size;
} Buffer;

Buffer *read_file(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    Buffer *buffer = malloc(sizeof(Buffer));
    buffer->buf = malloc(file_size + 1);
    buffer->size = file_size;

    size_t bytes_read = fread(buffer->buf, 1, file_size, file);
    if (bytes_read!= file_size) {
        free(buffer->buf);
        free(buffer);
        fclose(file);
        return NULL;
    }

    buffer->buf[file_size] = '\0';
    fclose(file);
    return buffer;
}

void *read_thread(void *args) {
    Buffer *buffer = (Buffer *)args;
    int status = 0;
    while (1) {
        char buf[BUF_SIZE];
        int bytes_read = read(STDIN_FILENO, buf, BUF_SIZE);
        if (bytes_read == -1) {
            status = -1;
            break;
        }
        buf[bytes_read] = '\0';
        if (strcmp(buf, "quit") == 0) {
            status = 0;
            break;
        }
        if (buffer->size + bytes_read + 1 > BUF_SIZE) {
            Buffer *new_buffer = malloc(sizeof(Buffer));
            new_buffer->buf = malloc(BUF_SIZE * 2);
            new_buffer->size = BUF_SIZE;
            memcpy(new_buffer->buf, buffer->buf, buffer->size);
            free(buffer->buf);
            buffer->buf = new_buffer->buf;
            buffer->size = new_buffer->size;
            new_buffer->buf = malloc(bytes_read + 1);
            new_buffer->size = bytes_read + 1;
            memcpy(new_buffer->buf, buf, bytes_read);
            free(buffer->buf);
            buffer->buf = new_buffer->buf;
            buffer->size += bytes_read + 1;
        }
        memcpy(buffer->buf + buffer->size, buf, bytes_read);
        buffer->size += bytes_read;
    }
    free(buffer->buf);
    free(buffer);
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    Buffer *buffer = read_file(argv[1]);
    if (buffer == NULL) {
        return 1;
    }
    pthread_t thread;
    pthread_create(&thread, NULL, read_thread, buffer);
    while (1) {
        char buf[BUF_SIZE];
        int bytes_read = read(STDIN_FILENO, buf, BUF_SIZE);
        if (bytes_read == -1) {
            break;
        }
        buf[bytes_read] = '\0';
        if (strcmp(buf, "quit") == 0) {
            break;
        }
        if (buffer->size + bytes_read + 1 > BUF_SIZE) {
            Buffer *new_buffer = malloc(sizeof(Buffer));
            new_buffer->buf = malloc(BUF_SIZE * 2);
            new_buffer->size = BUF_SIZE;
            memcpy(new_buffer->buf, buffer->buf, buffer->size);
            free(buffer->buf);
            buffer->buf = new_buffer->buf;
            buffer->size = new_buffer->size;
            new_buffer->buf = malloc(bytes_read + 1);
            new_buffer->size = bytes_read + 1;
            memcpy(new_buffer->buf, buf, bytes_read);
            free(buffer->buf);
            buffer->buf = new_buffer->buf;
            buffer->size += bytes_read + 1;
        }
        memcpy(buffer->buf + buffer->size, buf, bytes_read);
        buffer->size += bytes_read;
    }
    free(buffer->buf);
    free(buffer);
    return 0;
}