//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        exit(1);
    }

    int src_fd, dest_fd;
    struct stat src_stat, dest_stat;

    src_fd = open(argv[1], O_RDONLY);
    if (src_fd == -1) {
        printf("Error opening source file: %s\n", strerror(errno));
        exit(1);
    }

    dest_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd == -1) {
        printf("Error opening destination file: %s\n", strerror(errno));
        exit(1);
    }

    if (fstat(src_fd, &src_stat) == -1) {
        printf("Error getting source file status: %s\n", strerror(errno));
        exit(1);
    }

    if (fstat(dest_fd, &dest_stat) == -1) {
        printf("Error getting destination file status: %s\n", strerror(errno));
        exit(1);
    }

    if (src_stat.st_size!= dest_stat.st_size) {
        printf("Source and destination files are not the same size.\n");
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    int bytes_read, bytes_written;

    while ((bytes_read = read(src_fd, buffer, BUFFER_SIZE)) > 0) {
        bytes_written = write(dest_fd, buffer, bytes_read);
        if (bytes_written!= bytes_read) {
            printf("Error writing to destination file: %s\n", strerror(errno));
            exit(1);
        }
    }

    close(src_fd);
    close(dest_fd);

    printf("File synchronization complete.\n");

    return 0;
}