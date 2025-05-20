//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
        return 1;
    }

    char source_path[256] = {0};
    char dest_path[256] = {0};

    strcpy(source_path, argv[1]);
    strcpy(dest_path, argv[2]);

    int source_fd = open(source_path, O_RDONLY);
    if (source_fd == -1) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        return 1;
    }

    int dest_fd = open(dest_path, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    if (dest_fd == -1) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        close(source_fd);
        return 1;
    }

    struct stat source_stat;
    if (fstat(source_fd, &source_stat) == -1) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        close(source_fd);
        close(dest_fd);
        return 1;
    }

    char buffer[BUFFER_SIZE];
    int bytes_read;
    while ((bytes_read = read(source_fd, buffer, BUFFER_SIZE)) > 0) {
        if (write(dest_fd, buffer, bytes_read)!= bytes_read) {
            fprintf(stderr, "Error: %s\n", strerror(errno));
            close(source_fd);
            close(dest_fd);
            return 1;
        }
    }

    close(source_fd);
    close(dest_fd);

    return 0;
}