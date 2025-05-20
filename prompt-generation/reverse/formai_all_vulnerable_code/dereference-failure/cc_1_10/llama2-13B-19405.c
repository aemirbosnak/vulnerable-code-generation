//LLAMA2-13B DATASET v1.0 Category: Benchmarking ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/mman.h>

#define BENCHMARK_ITERATIONS 10000
#define BENCHMARK_MEMORY_SIZE (1024 * 1024)

void *mmap_memory(size_t size) {
    void *ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE, -1, 0);
    if (ptr == MAP_FAILED) {
        perror("mmap failed");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

void benchmark_memory(size_t size) {
    void *ptr = mmap_memory(size);
    if (ptr == MAP_FAILED) {
        perror("mmap failed");
        exit(EXIT_FAILURE);
    }
    char *memory = ptr;
    for (int i = 0; i < BENCHMARK_ITERATIONS; i++) {
        memory[i] = i % 2 ? 'A' : 'B';
    }
    munmap(ptr, size);
}

int main() {
    clock_t start, end;
    double elapsed_time;

    printf("Benchmarking memory allocation and manipulation...\n");

    // Warm up the memory
    benchmark_memory(BENCHMARK_MEMORY_SIZE);

    // Measure the time taken for 10,000 iterations
    start = clock();
    for (int i = 0; i < BENCHMARK_ITERATIONS; i++) {
        benchmark_memory(BENCHMARK_MEMORY_SIZE);
    }
    end = clock();
    elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Elapsed time: %f seconds\n", elapsed_time);

    return 0;
}