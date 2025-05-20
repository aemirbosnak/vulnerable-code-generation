//GEMINI-pro DATASET v1.0 Category: System boot optimizer ; Style: portable
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/mman.h>

#define PAGE_SIZE 4096

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    struct stat st;
    if (fstat(fd, &st) == -1) {
        perror("fstat");
        return 1;
    }

    if (!S_ISREG(st.st_mode)) {
        fprintf(stderr, "%s is not a regular file\n", argv[1]);
        return 1;
    }

    void *map = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (map == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    close(fd);

    // Find the first non-zero byte in the file.
    uint8_t *p = map;
    while (*p == 0) {
        p++;
    }

    // Find the last non-zero byte in the file.
    uint8_t *q = p;
    while (*q != 0) {
        q++;
    }

    // Truncate the file to the size of the non-zero data.
    if (ftruncate(fd, q - p) == -1) {
        perror("ftruncate");
        return 1;
    }

    // Unmap the file from memory.
    if (munmap(map, st.st_size) == -1) {
        perror("munmap");
        return 1;
    }

    return 0;
}