//FormAI DATASET v1.0 Category: File Synchronizer ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>

#define BUF_SIZE 1024

void* copy_file(void* arg);

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source_dir> <dest_dir>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    DIR* src_dir = opendir(argv[1]);
    if (src_dir == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    DIR* dest_dir = opendir(argv[2]);
    if (dest_dir == NULL) {
        if (errno == ENOENT) {
            if (mkdir(argv[2], 0777) != 0) {
                perror("mkdir");
                exit(EXIT_FAILURE);
            }
            dest_dir = opendir(argv[2]);
            if (dest_dir == NULL) {
                perror("opendir");
                exit(EXIT_FAILURE);
            }
        }
        else {
            perror("opendir");
            exit(EXIT_FAILURE);
        }
    }

    struct dirent* entry;
    while ((entry = readdir(src_dir)) != NULL) {
        if (entry->d_type == DT_REG) {
            char src_path[BUF_SIZE];
            sprintf(src_path, "%s/%s", argv[1], entry->d_name);

            char dest_path[BUF_SIZE];
            sprintf(dest_path, "%s/%s", argv[2], entry->d_name);

            pthread_t thread;
            if (pthread_create(&thread, NULL, copy_file, (void*) src_path) != 0) {
                perror("pthread_create");
                exit(EXIT_FAILURE);
            }

            if (pthread_join(thread, NULL) != 0) {
                perror("pthread_join");
                exit(EXIT_FAILURE);
            }
        }
    }

    closedir(src_dir);
    closedir(dest_dir);

    return 0;
}

void* copy_file(void* arg) {
    char* src_path = (char*) arg;

    int src_fd = open(src_path, O_RDONLY);
    if (src_fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    char dest_path[BUF_SIZE];
    sprintf(dest_path, "%s.copy", src_path);

    int dest_fd = open(dest_path, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (dest_fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    char buffer[BUF_SIZE];
    ssize_t nread;
    while ((nread = read(src_fd, buffer, BUF_SIZE)) > 0) {
        if (write(dest_fd, buffer, nread) != nread) {
            perror("write");
            exit(EXIT_FAILURE);
        }
    }

    if (nread == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    if (close(src_fd) == -1) {
        perror("close");
        exit(EXIT_FAILURE);
    }

    if (close(dest_fd) == -1) {
        perror("close");
        exit(EXIT_FAILURE);
    }

    return NULL;
}