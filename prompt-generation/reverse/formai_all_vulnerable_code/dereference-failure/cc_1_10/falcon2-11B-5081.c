//Falcon2-11B DATASET v1.0 Category: File Synchronizer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <pthread.h>
#include <unistd.h>
#include <dirent.h>

int main(int argc, char **argv) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <source-file> <destination-file>\n", argv[0]);
        exit(1);
    }

    const char *source = argv[1];
    const char *destination = argv[2];

    int source_fd = open(source, O_RDONLY);
    if (source_fd == -1) {
        fprintf(stderr, "Error opening source file: %s\n", strerror(errno));
        exit(1);
    }

    int destination_fd = open(destination, O_CREAT | O_WRONLY, 0644);
    if (destination_fd == -1) {
        fprintf(stderr, "Error opening destination file: %s\n", strerror(errno));
        exit(1);
    }

    off_t total_size = lseek(source_fd, 0, SEEK_END);
    if (total_size == -1) {
        fprintf(stderr, "Error getting source file size: %s\n", strerror(errno));
        exit(1);
    }

    char buffer[4096];
    int bytes_read = 0;
    while (bytes_read < total_size) {
        bytes_read += read(source_fd, buffer, sizeof(buffer));
        if (bytes_read == -1) {
            fprintf(stderr, "Error reading from source file: %s\n", strerror(errno));
            exit(1);
        }
        if (write(destination_fd, buffer, bytes_read) == -1) {
            fprintf(stderr, "Error writing to destination file: %s\n", strerror(errno));
            exit(1);
        }
    }

    close(source_fd);
    close(destination_fd);
    return 0;
}