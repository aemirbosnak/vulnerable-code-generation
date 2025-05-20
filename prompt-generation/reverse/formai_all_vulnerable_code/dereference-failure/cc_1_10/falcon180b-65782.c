//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>

#define PAGE_SIZE 4096
#define MAP_SIZE (10 * 1024 * 1024) // 10MB
#define MAP_MASK (MAP_SIZE - 1)

char *map;

void init() {
    int fd = open("/dev/zero", O_RDWR);
    map = (char *)mmap(NULL, MAP_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    close(fd);
    if (map == MAP_FAILED) {
        fprintf(stderr, "mmap failed\n");
        exit(1);
    }
}

void fini() {
    if (map!= MAP_FAILED) {
        munmap(map, MAP_SIZE);
    }
}

void *my_memcpy(void *dest, const void *src, size_t n) {
    char *d = (char *)dest;
    const char *s = (const char *)src;
    while (n-- > 0) {
        *d++ = *s++;
    }
    return dest;
}

int main() {
    init();

    int i, j;
    for (i = 0; i < MAP_SIZE; i += PAGE_SIZE) {
        for (j = 0; j < PAGE_SIZE; j += 4096) {
            my_memcpy(&map[i + j], &map[i + j - 4096], 4096);
        }
    }

    fini();

    return 0;
}