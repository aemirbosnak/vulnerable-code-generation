//MISTRAL-7B DATASET v1.0 Category: Performance-Critical Component ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <time.h>

#define BUF_SIZE 1024
#define NUM_BUFS 16

typedef struct {
    char data[BUF_SIZE];
    int head;
    int tail;
} circular_buffer_t;

void* shared_mem = NULL;
circular_buffer_t* cb = NULL;

void init_buffers() {
    int i;
    cb = mmap(NULL, NUM_BUFS * sizeof(circular_buffer_t), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANON, -1, 0);
    if (cb == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < NUM_BUFS; i++) {
        cb[i].head = -1;
        cb[i].tail = -1;
    }
}

int push_data(int buffer_index, char* data) {
    circular_buffer_t* cur_buf = &cb[buffer_index];

    if ((cur_buf->head + 1) % NUM_BUFS == buffer_index || (cur_buf->tail + 1) % NUM_BUFS == buffer_index) {
        perror("Buffer full");
        return -1;
    }

    int bytes_written = 0;
    while (bytes_written < BUF_SIZE - 1 && data[bytes_written] != '\0') {
        cur_buf->data[cur_buf->tail % BUF_SIZE] = data[bytes_written];
        bytes_written++;
        cur_buf->tail++;
    }

    cur_buf->data[cur_buf->tail % BUF_SIZE] = '\0';

    if (cur_buf->head == -1) {
        cur_buf->head = cur_buf->tail;
    }

    return bytes_written;
}

int main() {
    init_buffers();

    clock_t start = clock();

    int i, j, k;
    char str[BUF_SIZE];

    for (i = 0; i < 100000; i++) {
        for (j = 0; j < 128; j++) {
            snprintf(str, BUF_SIZE, "Hello, World! %d", j);
            push_data(i % NUM_BUFS, str);
        }
    }

    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %.6f seconds\n", time_taken);

    munmap(cb, NUM_BUFS * sizeof(circular_buffer_t));

    return 0;
}