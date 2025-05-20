//Falcon-180B DATASET v1.0 Category: System administration ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    char *src_file = argv[1];
    char *dest_file = argv[2];

    int src_fd = open(src_file, O_RDONLY);
    if (src_fd == -1) {
        printf("Error opening source file: %s\n", strerror(errno));
        return 1;
    }

    struct stat src_stat;
    if (fstat(src_fd, &src_stat) == -1) {
        printf("Error getting source file status: %s\n", strerror(errno));
        close(src_fd);
        return 1;
    }

    int dest_fd = open(dest_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd == -1) {
        printf("Error opening destination file: %s\n", strerror(errno));
        close(src_fd);
        return 1;
    }

    char buf[BUF_SIZE];
    ssize_t bytes_read;
    while ((bytes_read = read(src_fd, buf, BUF_SIZE)) > 0) {
        ssize_t bytes_written;
        if ((bytes_written = write(dest_fd, buf, bytes_read))!= bytes_read) {
            printf("Error writing to destination file: %s\n", strerror(errno));
            close(src_fd);
            close(dest_fd);
            unlink(dest_file);
            return 1;
        }
    }

    if (bytes_read == -1) {
        printf("Error reading from source file: %s\n", strerror(errno));
        close(src_fd);
        close(dest_fd);
        unlink(dest_file);
        return 1;
    }

    close(src_fd);
    close(dest_fd);

    printf("File copied successfully!\n");
    return 0;
}