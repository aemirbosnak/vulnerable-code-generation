//LLAMA2-13B DATASET v1.0 Category: RAM usage monitor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/sysinfo.h>
#include <unistd.h>

#define BUFFER_SIZE (4 * 1024 * 1024)
#define PAGE_SIZE (4 * 1024)

void *buffer;
size_t buffer_used;
size_t buffer_total;

void init_buffer() {
    buffer = mmap(NULL, BUFFER_SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    buffer_used = 0;
    buffer_total = BUFFER_SIZE;
}

void print_usage() {
    printf("RAM Usage: %zu/%zu (%.2f%%)\n", buffer_used, buffer_total, (float)buffer_used / (float)buffer_total * 100);
}

void *malloc_with_usage(size_t size) {
    void *ptr = malloc(size);
    buffer_used += size;
    print_usage();
    return ptr;
}

void free_with_usage(void *ptr) {
    buffer_used -= sizeof(ptr);
    print_usage();
    free(ptr);
}

int main() {
    init_buffer();

    // Allocate some memory
    void *ptr1 = malloc_with_usage(BUFFER_SIZE / 2);
    void *ptr2 = malloc_with_usage(BUFFER_SIZE / 2);

    // Use the memory
    char *ptr1_data = (char *)ptr1;
    char *ptr2_data = (char *)ptr2;
    for (size_t i = 0; i < BUFFER_SIZE / 2; i++) {
        ptr1_data[i] = i % 2 ? 'a' : 'b';
        ptr2_data[i] = i % 2 ? 'c' : 'd';
    }

    // Free the memory
    free_with_usage(ptr1);
    free_with_usage(ptr2);

    // Print the final usage
    print_usage();

    return 0;
}