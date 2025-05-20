//LLAMA2-13B DATASET v1.0 Category: RAM usage monitor ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <unistd.h>

#define MAP_SIZE (1024 * 1024)

struct ram_usage {
    size_t used;
    size_t total;
};

static void *mmap_mem;

void init_ram_usage() {
    mmap_mem = mmap(NULL, MAP_SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE, -1, 0);
    if (mmap_mem == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    struct ram_usage *ru = (struct ram_usage *)mmap_mem;
    ru->used = 0;
    ru->total = MAP_SIZE;
}

void update_ram_usage() {
    size_t curr_used = mmap_mem + 4; // current usage is 4 bytes past the beginning of the mmap'd region
    struct ram_usage *ru = (struct ram_usage *)mmap_mem;
    ru->used = curr_used - ru->total;
}

void print_ram_usage() {
    struct ram_usage *ru = (struct ram_usage *)mmap_mem;
    printf("RAM Usage: Used: %zu MB, Total: %zu MB\n", ru->used / 1024, ru->total / 1024);
}

int main() {
    init_ram_usage();

    while (1) {
        update_ram_usage();
        print_ram_usage();
        usleep(100000); // 100ms
    }

    return 0;
}