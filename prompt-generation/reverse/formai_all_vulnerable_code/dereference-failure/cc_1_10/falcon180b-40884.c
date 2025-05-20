//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    if (argc!= 4) {
        printf("Usage: %s <source_file> <destination_file> <mode>\n", argv[0]);
        return 1;
    }

    char *source_file = argv[1];
    char *destination_file = argv[2];
    char *mode = argv[3];

    int source_fd = open(source_file, O_RDONLY);
    if (source_fd == -1) {
        printf("Error opening source file: %s\n", strerror(errno));
        return 1;
    }

    int destination_fd = open(destination_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (destination_fd == -1) {
        printf("Error opening destination file: %s\n", strerror(errno));
        close(source_fd);
        return 1;
    }

    if (strcmp(mode, "append") == 0) {
        lseek(destination_fd, 0, SEEK_END);
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    while ((bytes_read = read(source_fd, buffer, BUFFER_SIZE)) > 0) {
        if (write(destination_fd, buffer, bytes_read)!= bytes_read) {
            printf("Error writing to destination file: %s\n", strerror(errno));
            close(source_fd);
            close(destination_fd);
            return 1;
        }
    }

    close(source_fd);
    close(destination_fd);

    printf("File synchronization completed successfully.\n");
    return 0;
}