//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

#define MAP_FAILED  (-1)
#define MAP_ANONYMOUS (-2)
#define MAP_PRIVATE (-3)

#define BUFFER_SIZE 1024

void* alloc_mem(size_t size) {
    void* mem = malloc(size);
    if (mem == NULL) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    return mem;
}

void free_mem(void* mem) {
    free(mem);
}

int main() {
    // Create an anonymous mapping
    void* mem = mmap(NULL, BUFFER_SIZE, PROT_READ | PROT_WRITE, MAP_ANONYMOUS, -1, 0);
    if (mem == MAP_FAILED) {
        perror("mmap failed");
        exit(EXIT_FAILURE);
    }

    // Write some data to the mapping
    char* data = (char*)mem;
    for (int i = 0; i < BUFFER_SIZE; i++) {
        data[i] = 'A' + i % 26;
    }

    // Unmap the memory
    munmap(mem, BUFFER_SIZE);

    // Create a private mapping
    mem = mmap(NULL, BUFFER_SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE, -1, 0);
    if (mem == MAP_FAILED) {
        perror("mmap failed");
        exit(EXIT_FAILURE);
    }

    // Write some more data to the mapping
    data = (char*)mem;
    for (int i = 0; i < BUFFER_SIZE; i++) {
        data[i] = 'B' + i % 26;
    }

    // Unmap the memory
    munmap(mem, BUFFER_SIZE);

    return 0;
}