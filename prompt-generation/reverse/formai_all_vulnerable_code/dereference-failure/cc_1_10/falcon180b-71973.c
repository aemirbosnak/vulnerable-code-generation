//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    int source_fd = open(argv[1], O_RDONLY);
    if (source_fd == -1) {
        printf("Error opening source file: %s\n", strerror(errno));
        return 1;
    }

    int dest_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (dest_fd == -1) {
        printf("Error opening destination file: %s\n", strerror(errno));
        return 1;
    }

    struct stat source_stat;
    if (fstat(source_fd, &source_stat) == -1) {
        printf("Error getting source file status: %s\n", strerror(errno));
        return 1;
    }

    char *buffer = malloc(BUFFER_SIZE);
    if (buffer == NULL) {
        printf("Error allocating memory for buffer\n");
        return 1;
    }

    int bytes_read = 0;
    int bytes_written = 0;
    while ((bytes_read = read(source_fd, buffer, BUFFER_SIZE)) > 0) {
        if (write(dest_fd, buffer, bytes_read)!= bytes_read) {
            printf("Error writing to destination file: %s\n", strerror(errno));
            return 1;
        }
        bytes_written += bytes_read;
    }

    if (bytes_read == -1) {
        printf("Error reading from source file: %s\n", strerror(errno));
        return 1;
    }

    printf("Recovered %d bytes to %s\n", bytes_written, argv[2]);

    close(source_fd);
    close(dest_fd);
    free(buffer);

    return 0;
}