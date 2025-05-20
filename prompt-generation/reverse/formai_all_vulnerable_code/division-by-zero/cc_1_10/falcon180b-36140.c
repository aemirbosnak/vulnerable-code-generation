//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

#define PAGE_SIZE 4096

int main() {
    int fd;
    char *filename = "test.txt";
    struct stat statbuf;
    void *addr;
    int pagesize = getpagesize();
    int pages = 0;
    int i;

    fd = open(filename, O_RDWR);
    if (fd == -1) {
        perror("Error opening file");
        exit(1);
    }

    if (fstat(fd, &statbuf) == -1) {
        perror("Error getting file status");
        exit(1);
    }

    addr = mmap(NULL, statbuf.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (addr == MAP_FAILED) {
        perror("Error mapping file to memory");
        exit(1);
    }

    for (i = 0; i < statbuf.st_size; i += pagesize) {
        if (i % pagesize == 0) {
            pages++;
        }
    }

    printf("Pages used: %d\n", pages);

    if (munmap(addr, statbuf.st_size) == -1) {
        perror("Error unmapping file from memory");
        exit(1);
    }

    if (close(fd) == -1) {
        perror("Error closing file");
        exit(1);
    }

    return 0;
}