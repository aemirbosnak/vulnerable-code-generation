//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/mman.h>

#define PAGE_SIZE 4096
#define MAX_FILE_SIZE (10 * 1024 * 1024)

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    struct stat st;

    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        return 1;
    }

    if (fstat(fd, &st) == -1) {
        fprintf(stderr, "Error getting file status: %s\n", strerror(errno));
        return 1;
    }

    if (st.st_size > MAX_FILE_SIZE) {
        fprintf(stderr, "File is too large\n");
        return 1;
    }

    void *addr = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (addr == MAP_FAILED) {
        fprintf(stderr, "Error mapping file: %s\n", strerror(errno));
        return 1;
    }

    int count = 0;
    for (int i = 0; i < st.st_size; i += PAGE_SIZE) {
        if (madvise(addr + i, PAGE_SIZE, MADV_WILLNEED) == -1) {
            fprintf(stderr, "Error advising memory: %s\n", strerror(errno));
            return 1;
        }
        count++;
    }

    printf("Optimized %d pages\n", count);

    munmap(addr, st.st_size);
    close(fd);

    return 0;
}