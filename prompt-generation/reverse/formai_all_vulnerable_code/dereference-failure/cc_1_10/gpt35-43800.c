//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/mman.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s file_name\n", argv[0]);
        return -1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open");
        return -1;
    }

    struct stat st;
    if (fstat(fd, &st) == -1) {
        perror("fstat");
        return -1;
    }

    char *map = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (map == MAP_FAILED) {
        perror("mmap");
        return -1;
    }

    char buffer[BUFFER_SIZE];
    strncpy(buffer, map, BUFFER_SIZE);
    buffer[BUFFER_SIZE - 1] = '\0';
    printf("Metadata: %s\n", buffer);

    if (munmap(map, st.st_size) == -1) {
        perror("munmap");
        return -1;
    }

    if (close(fd) == -1) {
        perror("close");
        return -1;
    }

    return 0;
}