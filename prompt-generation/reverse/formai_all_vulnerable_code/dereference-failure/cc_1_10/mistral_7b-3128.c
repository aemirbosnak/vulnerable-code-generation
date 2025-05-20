//MISTRAL-7B DATASET v1.0 Category: System boot optimizer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/mman.h>

#define BUF_SIZE 4096
#define NUM_BUFS 128

void* mempool;
unsigned char* buf[NUM_BUFS];
unsigned char buf_free[NUM_BUFS];
unsigned int buf_used = 0;
unsigned int buf_total = NUM_BUFS;

void init_memory() {
    mempool = mmap(NULL, BUF_SIZE * NUM_BUFS, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (mempool == MAP_FAILED) {
        fprintf(stderr, "Error initializing memory pool\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < NUM_BUFS; i++) {
        buf[i] = mempool + i * BUF_SIZE;
        buf_free[i] = 1;
    }
}

void* get_buffer() {
    if (buf_used >= buf_total) {
        fprintf(stderr, "Error: No more free buffers\n");
        exit(EXIT_FAILURE);
    }

    int index = buf_used++;
    buf_free[index] = 0;

    return buf[index];
}

void free_buffer(void* buffer) {
    int index = (unsigned long) buffer / BUF_SIZE;
    buf_free[index] = 1;
}

int main() {
    clock_t start, end;

    init_memory();

    start = clock();

    for (int i = 0; i < 10000; i++) {
        void* buffer = get_buffer();
        memset(buffer, 0, BUF_SIZE);
        free_buffer(buffer);
    }

    end = clock();

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", time_taken);

    munmap(mempool, BUF_SIZE * NUM_BUFS);

    return 0;
}