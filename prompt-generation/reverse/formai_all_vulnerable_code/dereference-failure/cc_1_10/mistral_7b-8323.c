//MISTRAL-7B DATASET v1.0 Category: RAM usage monitor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/sysinfo.h>
#include <errno.h>

typedef struct MemoryMapTag {
    char filename[128];
    size_t size;
    size_t start;
    size_t end;
} MemoryMap;

void print_memory_map(MemoryMap *map, size_t size) {
    printf("\nMemory Map:\n");
    for (size_t i = 0; i < size; ++i) {
        printf("%s: 0x%lx - 0x%lx, size: %ld bytes\n", map[i].filename, map[i].start, map[i].end, map[i].size);
    }
}

int main() {
    struct stat file_stat;
    int fd;
    size_t size;
    MemoryMap *memory_map;
    size_t num_maps;

    fd = open("/proc/self/maps", O_RDONLY);
    if (fd < 0) {
        perror("Error opening /proc/self/maps");
        exit(EXIT_FAILURE);
    }

    fstat(fd, &file_stat);
    size = file_stat.st_size;
    memory_map = mmap(NULL, size, PROT_READ, MAP_PRIVATE, fd, 0);
    close(fd);

    if (memory_map == MAP_FAILED) {
        perror("Error mmaping /proc/self/maps");
        exit(EXIT_FAILURE);
    }

    num_maps = size / sizeof(MemoryMap);

    print_memory_map(memory_map, num_maps);

    munmap(memory_map, size);

    return EXIT_SUCCESS;
}