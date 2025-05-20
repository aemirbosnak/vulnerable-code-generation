//LLAMA2-13B DATASET v1.0 Category: RAM usage monitor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_MEMORY 4ULL * 1024ULL * 1024ULL * 1024ULL
#define MEMORY_GRANULARITY 4ULL * 1024ULL

struct memory_usage {
    size_t total;
    size_t used;
    size_t free;
};

struct memory_usage *get_memory_usage(void) {
    struct memory_usage *usage;
    size_t pagesize = getpagesize();
    void *addr = mmap(NULL, MAX_MEMORY, PROT_READ | PROT_WRITE, MAP_FILE | MAP_PRIVATE, -1, 0);
    if (addr == MAP_FAILED) {
        perror("mmap");
        return NULL;
    }
    usage = calloc(1, sizeof(struct memory_usage));
    if (usage == NULL) {
        munmap(addr, MAX_MEMORY);
        perror("calloc");
        return NULL;
    }
    usage->total = MAX_MEMORY;
    usage->used = 0;
    usage->free = MAX_MEMORY;
    for (size_t i = 0; i < MAX_MEMORY; i += pagesize) {
        size_t page = i / pagesize;
        size_t remaining = i % pagesize;
        if (remaining != 0) {
            usage->free -= remaining;
            usage->used += remaining;
        }
        if (page == (size_t)addr) {
            usage->used += pagesize;
        }
    }
    return usage;
}

void print_memory_usage(struct memory_usage *usage) {
    printf("Memory usage:\n");
    printf("  Total: %zu bytes\n", usage->total);
    printf("  Used: %zu bytes\n", usage->used);
    printf("  Free: %zu bytes\n", usage->free);
}

int main(void) {
    struct memory_usage *usage;
    while (1) {
        usage = get_memory_usage();
        if (usage == NULL) {
            perror("get_memory_usage");
            return 1;
        }
        print_memory_usage(usage);
        free(usage);
        sleep(1);
    }
    return 0;
}