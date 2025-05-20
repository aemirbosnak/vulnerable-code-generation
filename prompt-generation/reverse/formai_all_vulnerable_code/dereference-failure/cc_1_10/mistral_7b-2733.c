//MISTRAL-7B DATASET v1.0 Category: Performance-Critical Component ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <time.h>

#define BLOCK_SIZE 4096
#define NUM_BLOCKS 1024
#define BUFFER_SIZE 16384
#define NUM_ITERATIONS 100000
#define ALIGNMENT 64

typedef struct {
    void *data;
    size_t size;
    size_t allocated;
} my_mem_block;

void *my_malloc(size_t size) {
    size_t total_size = ALIGNMENT + size + ALIGNMENT;
    void *ptr = mmap(NULL, total_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

    if (ptr == MAP_FAILED) {
        perror("mmap failed");
        exit(1);
    }

    my_mem_block *mem_block = (my_mem_block *) ptr;
    mem_block->size = size;
    mem_block->allocated = total_size;

    return (char *) ptr + ALIGNMENT;
}

void my_free(void *ptr) {
    munmap((void *) ((char *) ptr - ALIGNMENT), ((my_mem_block *) ptr)->allocated);
}

void *buffer;
my_mem_block *blocks;

void init() {
    clock_t start, end;
    double duration;

    start = clock();

    buffer = my_malloc(BUFFER_SIZE);
    blocks = (my_mem_block *) malloc(NUM_BLOCKS * sizeof(my_mem_block));

    for (size_t i = 0; i < NUM_BLOCKS; i++) {
        blocks[i].size = BLOCK_SIZE;
        blocks[i].allocated = BLOCK_SIZE + ALIGNMENT;
        blocks[i].data = (char *) my_malloc(BLOCK_SIZE);
    }

    end = clock();
    duration = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Initialization time: %.6f seconds\n", duration);
}

void fill_and_copy() {
    clock_t start, end;
    double duration;

    start = clock();

    for (size_t i = 0; i < NUM_ITERATIONS; i++) {
        void *src = (void *) ((char *) buffer + (i % BUFFER_SIZE));
        size_t j = i / BUFFER_SIZE;

        memmove(blocks[j].data, src, BLOCK_SIZE);
    }

    end = clock();
    duration = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Fill and copy time: %.6f seconds\n", duration);
}

void print_results() {
    for (size_t i = 0; i < NUM_BLOCKS; i++) {
        size_t sum = 0;
        char *data = (char *) blocks[i].data;

        for (size_t j = 0; j < BLOCK_SIZE; j += 4) {
            sum += *(int *) (data + j);
        }

        printf("Block %d: sum = %d\n", i, sum);
    }
}

int main() {
    init();
    fill_and_copy();
    print_results();
    my_free(buffer);
    free(blocks);

    return 0;
}