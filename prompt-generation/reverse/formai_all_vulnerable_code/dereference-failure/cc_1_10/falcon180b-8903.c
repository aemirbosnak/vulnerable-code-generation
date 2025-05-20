//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        fprintf(stderr, "Usage: %s <source_file> <destination_file> <backup_file>\n", argv[0]);
        return 1;
    }

    char *source_file = argv[1];
    char *destination_file = argv[2];
    char *backup_file = argv[3];

    int source_fd = open(source_file, O_RDONLY);
    if (source_fd == -1) {
        fprintf(stderr, "Error opening source file: %s\n", strerror(errno));
        return 1;
    }

    int destination_fd = open(destination_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (destination_fd == -1) {
        fprintf(stderr, "Error opening destination file: %s\n", strerror(errno));
        return 1;
    }

    int backup_fd = open(backup_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (backup_fd == -1) {
        fprintf(stderr, "Error opening backup file: %s\n", strerror(errno));
        return 1;
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    while ((bytes_read = read(source_fd, buffer, BUFFER_SIZE)) > 0) {
        ssize_t bytes_written;

        if (write(destination_fd, buffer, bytes_read)!= bytes_read) {
            fprintf(stderr, "Error writing to destination file: %s\n", strerror(errno));
            return 1;
        }

        if (write(backup_fd, buffer, bytes_read)!= bytes_read) {
            fprintf(stderr, "Error writing to backup file: %s\n", strerror(errno));
            return 1;
        }
    }

    if (bytes_read == -1) {
        fprintf(stderr, "Error reading from source file: %s\n", strerror(errno));
        return 1;
    }

    close(source_fd);
    close(destination_fd);
    close(backup_fd);

    fprintf(stdout, "File backup completed successfully.\n");

    return 0;
}