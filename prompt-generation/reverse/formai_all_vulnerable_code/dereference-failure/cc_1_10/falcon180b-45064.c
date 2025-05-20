//Falcon-180B DATASET v1.0 Category: System administration ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    char *source_file = argv[1];
    char *destination_file = argv[2];

    int source_fd = open(source_file, O_RDONLY);
    if (source_fd == -1) {
        printf("Error opening %s: %s\n", source_file, strerror(errno));
        return 1;
    }

    struct stat source_stat;
    if (fstat(source_fd, &source_stat) == -1) {
        printf("Error getting source file status: %s\n", strerror(errno));
        close(source_fd);
        return 1;
    }

    int destination_fd = open(destination_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (destination_fd == -1) {
        printf("Error opening %s: %s\n", destination_file, strerror(errno));
        close(source_fd);
        return 1;
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;
    while ((bytes_read = read(source_fd, buffer, BUFFER_SIZE)) > 0) {
        ssize_t bytes_written = write(destination_fd, buffer, bytes_read);
        if (bytes_written!= bytes_read) {
            printf("Error writing to %s: %s\n", destination_file, strerror(errno));
            close(source_fd);
            close(destination_fd);
            unlink(destination_file);
            return 1;
        }
    }

    if (bytes_read == -1) {
        printf("Error reading from %s: %s\n", source_file, strerror(errno));
        close(source_fd);
        close(destination_fd);
        unlink(destination_file);
        return 1;
    }

    close(source_fd);
    close(destination_fd);

    printf("File %s copied to %s\n", source_file, destination_file);

    return 0;
}