//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 4096

void sync_file(const char* source_file, const char* dest_file)
{
    int src_fd = open(source_file, O_RDONLY);
    if (src_fd == -1) {
        printf("Error opening source file: %s\n", strerror(errno));
        exit(1);
    }

    int dest_fd = open(dest_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd == -1) {
        printf("Error opening destination file: %s\n", strerror(errno));
        exit(1);
    }

    char buf[BUF_SIZE];
    ssize_t bytes_read, bytes_written;

    while ((bytes_read = read(src_fd, buf, BUF_SIZE)) > 0) {
        bytes_written = write(dest_fd, buf, bytes_read);
        if (bytes_written!= bytes_read) {
            printf("Error writing to destination file: %s\n", strerror(errno));
            exit(1);
        }
    }

    if (bytes_read == -1) {
        printf("Error reading from source file: %s\n", strerror(errno));
        exit(1);
    }

    close(src_fd);
    close(dest_fd);
}

int main(int argc, char* argv[])
{
    if (argc!= 3) {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        exit(1);
    }

    sync_file(argv[1], argv[2]);
    printf("File synchronization complete.\n");

    return 0;
}