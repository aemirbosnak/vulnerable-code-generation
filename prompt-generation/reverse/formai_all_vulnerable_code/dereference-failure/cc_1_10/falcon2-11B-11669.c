//Falcon2-11B DATASET v1.0 Category: RAM usage monitor ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <errno.h>
#include <string.h>

#define PAGE_SIZE 4096

void print_ram_usage(int fd) {
    uint8_t* map;
    char buffer[PAGE_SIZE];

    if (ftruncate(fd, 0) < 0) {
        perror("ftruncate");
        exit(1);
    }

    if (posix_memalign((void**)&map, PAGE_SIZE, PAGE_SIZE)) {
        perror("posix_memalign");
        exit(1);
    }

    if (mmap(map, PAGE_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0)) {
        perror("mmap");
        exit(1);
    }

    while (read(fd, buffer, PAGE_SIZE) > 0) {
        uint64_t total = 0;
        uint64_t free = 0;

        for (size_t i = 0; i < PAGE_SIZE; i++) {
            if (buffer[i] & (1 << 7)) {
                total += 1;
            } else {
                free += 1;
            }
        }

        printf("RAM Usage: Total: %lu, Free: %lu\n", total, free);
    }

    munmap(map, PAGE_SIZE);
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(1);
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        perror("open");
        exit(1);
    }

    print_ram_usage(fd);

    return 0;
}