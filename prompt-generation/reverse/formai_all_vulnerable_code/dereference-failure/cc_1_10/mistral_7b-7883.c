//MISTRAL-7B DATASET v1.0 Category: Performance-Critical Component ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <time.h>

#define BLOCK_SIZE 1024
#define NUM_BLOCKS 1024
#define STR_LEN 256

typedef struct {
    char data[STR_LEN];
    int counter;
} block_t;

void init_blocks(void *addr) {
    block_t *blocks = (block_t *) addr;
    for (int i = 0; i < NUM_BLOCKS; ++i) {
        blocks[i].counter = 0;
    }
}

int main() {
    clock_t start, end;
    double elapsed_time;

    int size = NUM_BLOCKS * sizeof(block_t);
    void *shared_mem = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANON, -1, 0);
    if (shared_mem == MAP_FAILED) {
        perror("mmap failed");
        exit(1);
    }

    init_blocks(shared_mem);

    start = clock();
    for (int i = 0; i < 1000000; ++i) {
        int idx = i % NUM_BLOCKS;
        block_t *block = (block_t *) (shared_mem + idx * sizeof(block_t));
        strcpy(block->data, "Hello World");
        block->counter++;
    }

    end = clock();
    elapsed_time = (double) (end - start) / CLOCKS_PER_SEC;
    printf("Time elapsed: %.6f seconds\n", elapsed_time);

    munmap(shared_mem, size);

    return 0;
}