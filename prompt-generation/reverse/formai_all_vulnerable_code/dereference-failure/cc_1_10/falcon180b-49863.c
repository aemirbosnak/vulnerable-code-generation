//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <errno.h>

#define BUFFER_SIZE (1024 * 1024)

int main(int argc, char *argv[]) {
    int fd;
    void *buffer;
    ssize_t bytes_read;

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        printf("Error opening file: %s\n", strerror(errno));
        return 1;
    }

    buffer = mmap(NULL, BUFFER_SIZE, PROT_READ, MAP_SHARED, fd, 0);
    if (buffer == MAP_FAILED) {
        printf("Error mapping file: %s\n", strerror(errno));
        close(fd);
        return 1;
    }

    printf("Reading file '%s'...\n", argv[1]);

    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0) {
        printf(".");
        fflush(stdout);
    }

    if (bytes_read == -1) {
        printf("Error reading file: %s\n", strerror(errno));
        munmap(buffer, BUFFER_SIZE);
        close(fd);
        return 1;
    }

    printf("\nFile read successfully!\n");

    munmap(buffer, BUFFER_SIZE);
    close(fd);

    return 0;
}