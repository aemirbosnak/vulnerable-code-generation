//LLAMA2-13B DATASET v1.0 Category: RAM usage monitor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER_SIZE 4096

struct mem_info {
    unsigned long used;
    unsigned long free;
    unsigned long total;
};

void get_mem_info(struct mem_info *info) {
    info->used = (unsigned long)sysconf(_SC_PHYS_PAGES);
    info->free = (unsigned long)sysconf(_SC_AVPHYS_PAGES);
    info->total = info->used + info->free;
}

void print_mem_info(struct mem_info info) {
    printf("Memory usage: \n");
    printf("  Used: %lu MB (%u%%)\n", info.used / 1024 / 1024,
           (info.used * 100) / info.total);
    printf("  Free: %lu MB (%u%%)\n", info.free / 1024 / 1024,
           (info.free * 100) / info.total);
    printf("  Total: %lu MB\n", info.total / 1024 / 1024);
}

int main() {
    struct mem_info info;

    while (1) {
        get_mem_info(&info);
        print_mem_info(info);

        // Mmap a buffer to monitor memory usage
        int fd = open("/dev/null", O_RDONLY);
        char *buffer = mmap(NULL, BUFFER_SIZE, PROT_READ, MAP_FILE | MAP_PRIVATE, fd, 0);
        if (buffer == MAP_FAILED) {
            perror("mmap failed");
            exit(EXIT_FAILURE);
        }

        // Unmap the buffer to free up memory
        munmap(buffer, BUFFER_SIZE);
    }

    return 0;
}