//GEMINI-pro DATASET v1.0 Category: Audio processing ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BUFSIZE 256

typedef struct {
    int n;
    short *buf;
} buffer_t;

void init_buffer(buffer_t *buf, int n) {
    buf->n = n;
    buf->buf = malloc(sizeof(short) * n);
}

void free_buffer(buffer_t *buf) {
    free(buf->buf);
}

void process_buffer(buffer_t *buf, int start, int end) {
    if (start >= end) {
        return;
    }

    int mid = (start + end) / 2;
    process_buffer(buf, start, mid);
    process_buffer(buf, mid + 1, end);

    for (int i = start; i < end; i++) {
        buf->buf[i] = buf->buf[i] * 0.5;
    }
}

int main(void) {
    buffer_t buf;
    init_buffer(&buf, BUFSIZE);

    // Fill the buffer with some data
    for (int i = 0; i < BUFSIZE; i++) {
        buf.buf[i] = i;
    }

    // Process the buffer recursively
    process_buffer(&buf, 0, BUFSIZE - 1);

    // Print the processed data
    for (int i = 0; i < BUFSIZE; i++) {
        printf("%d ", buf.buf[i]);
    }
    printf("\n");

    free_buffer(&buf);

    return 0;
}