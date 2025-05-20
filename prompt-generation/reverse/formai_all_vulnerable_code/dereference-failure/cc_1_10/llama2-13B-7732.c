//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <semaphore.h>
#include <pthread.h>

#define MAX_FILE_SIZE (1024 * 1024 * 10)
#define MAX_BUFFER_SIZE (1024 * 1024 * 5)
#define SEMAPHORE_VALUE 5

typedef struct {
    char *name;
    char *buffer;
    size_t size;
    size_t offset;
    int fd;
} file_t;

void* read_file(void* arg) {
    file_t* file = arg;
    size_t bytes_read = 0;
    char buffer[MAX_BUFFER_SIZE];

    while (bytes_read < file->size) {
        ssize_t ret = read(file->fd, buffer, MAX_BUFFER_SIZE);
        if (ret < 0) {
            perror("read");
            break;
        }
        bytes_read += ret;
        file->offset += ret;

        if (file->offset >= file->size) {
            break;
        }
    }

    return NULL;
}

void* write_file(void* arg) {
    file_t* file = arg;
    size_t bytes_written = 0;
    char buffer[MAX_BUFFER_SIZE];

    while (bytes_written < file->size) {
        ssize_t ret = write(file->fd, buffer, MAX_BUFFER_SIZE);
        if (ret < 0) {
            perror("write");
            break;
        }
        bytes_written += ret;
        file->offset += ret;

        if (file->offset >= file->size) {
            break;
        }
    }

    return NULL;
}

int main() {
    int fd[2];
    file_t files[3];
    sem_t sem;
    pthread_t threads[3];

    // Create files
    for (int i = 0; i < 3; i++) {
        files[i].name = (char*)malloc(100);
        files[i].buffer = (char*)malloc(MAX_BUFFER_SIZE);
        files[i].size = (i % 2) ? MAX_FILE_SIZE : 0;
        files[i].offset = 0;
        files[i].fd = open(files[i].name, O_RDWR | O_CREAT, 0644);

        if (files[i].fd < 0) {
            perror("open");
            exit(EXIT_FAILURE);
        }

        // Create semaphore
        sem_init(&sem, 0, SEMAPHORE_VALUE);

        // Create threads
        pthread_create(&threads[0], NULL, read_file, &files[0]);
        pthread_create(&threads[1], NULL, write_file, &files[1]);
        pthread_create(&threads[2], NULL, read_file, &files[2]);

        // Wait for threads to finish
        sem_wait(&sem);

        // Close files
        for (int i = 0; i < 3; i++) {
            close(files[i].fd);
        }

        // Free memory
        for (int i = 0; i < 3; i++) {
            free(files[i].name);
            free(files[i].buffer);
        }

        return 0;
    }
}