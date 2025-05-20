//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <sys/mman.h>

typedef struct {
    int fd;
    char *path;
    char *buf;
    size_t size;
    size_t count;
    size_t bufsize;
    off_t offset;
} file_t;

void *thread_func(void *arg) {
    file_t *file = arg;
    char *buf = file->buf;
    size_t bufsize = file->bufsize;
    size_t count = 0;
    ssize_t ret;

    while (count < file->size) {
        ret = read(file->fd, buf + count, bufsize - count);
        if (ret <= 0) {
            break;
        }
        count += ret;
    }

    if (count == file->size) {
        close(file->fd);
        free(file->buf);
        free(file);
    } else {
        printf("Error reading file %s\n", file->path);
        close(file->fd);
        free(file->buf);
        free(file);
    }

    return NULL;
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: %s <file> <size>\n", argv[0]);
        return 1;
    }

    char *path = argv[1];
    size_t size = atoi(argv[2]);

    int fd = open(path, O_RDONLY);
    if (fd == -1) {
        printf("Error opening file %s\n", path);
        return 1;
    }

    struct stat st;
    if (fstat(fd, &st) == -1) {
        printf("Error getting file status\n");
        close(fd);
        return 1;
    }

    if (st.st_size < size) {
        printf("File %s is smaller than specified size\n", path);
        close(fd);
        return 1;
    }

    file_t *file = malloc(sizeof(file_t));
    file->fd = fd;
    file->path = strdup(path);
    file->size = size;
    file->bufsize = 1024 * 1024; // 1MB
    file->buf = malloc(file->bufsize);
    file->offset = 0;

    pthread_t thread;
    pthread_create(&thread, NULL, thread_func, file);

    pthread_join(thread, NULL);

    return 0;
}