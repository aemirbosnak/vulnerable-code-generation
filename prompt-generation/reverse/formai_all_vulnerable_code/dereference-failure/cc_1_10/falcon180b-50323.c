//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s source_file target_file\n", argv[0]);
        return 1;
    }

    int source_fd = open(argv[1], O_RDONLY);
    if (source_fd == -1) {
        fprintf(stderr, "Error opening source file: %s\n", strerror(errno));
        return 1;
    }

    int target_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (target_fd == -1) {
        fprintf(stderr, "Error opening target file: %s\n", strerror(errno));
        close(source_fd);
        return 1;
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    while ((bytes_read = read(source_fd, buffer, BUFFER_SIZE)) > 0) {
        if (write(target_fd, buffer, bytes_read)!= bytes_read) {
            fprintf(stderr, "Error writing to target file: %s\n", strerror(errno));
            close(source_fd);
            close(target_fd);
            unlink(argv[2]);
            return 1;
        }
    }

    if (bytes_read == -1) {
        fprintf(stderr, "Error reading from source file: %s\n", strerror(errno));
        close(source_fd);
        close(target_fd);
        unlink(argv[2]);
        return 1;
    }

    close(source_fd);
    close(target_fd);

    printf("File synchronization complete.\n");
    return 0;
}