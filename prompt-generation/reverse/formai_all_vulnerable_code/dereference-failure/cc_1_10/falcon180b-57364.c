//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_FILE_SIZE (1024 * 1024 * 10)
#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s source_file destination_file\n", argv[0]);
        exit(1);
    }

    char *source_file = argv[1];
    char *dest_file = argv[2];

    int source_fd = open(source_file, O_RDONLY);
    if (source_fd == -1) {
        fprintf(stderr, "Error opening source file: %s\n", strerror(errno));
        exit(1);
    }

    struct stat source_stat;
    if (fstat(source_fd, &source_stat) == -1) {
        fprintf(stderr, "Error getting source file status: %s\n", strerror(errno));
        exit(1);
    }

    if (source_stat.st_size > MAX_FILE_SIZE) {
        fprintf(stderr, "Source file is too large.\n");
        exit(1);
    }

    int dest_fd = open(dest_file, O_WRONLY | O_CREAT, 0644);
    if (dest_fd == -1) {
        fprintf(stderr, "Error opening destination file: %s\n", strerror(errno));
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    int bytes_read, bytes_written;

    while ((bytes_read = read(source_fd, buffer, BUFFER_SIZE)) > 0) {
        bytes_written = write(dest_fd, buffer, bytes_read);
        if (bytes_written!= bytes_read) {
            fprintf(stderr, "Error writing to destination file: %s\n", strerror(errno));
            exit(1);
        }
    }

    if (bytes_read == -1) {
        fprintf(stderr, "Error reading from source file: %s\n", strerror(errno));
        exit(1);
    }

    close(source_fd);
    close(dest_fd);

    fprintf(stdout, "File synchronization completed successfully.\n");

    return 0;
}