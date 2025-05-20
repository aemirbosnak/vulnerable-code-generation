//MISTRAL-7B DATASET v1.0 Category: Performance-Critical Component ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#define WINDOW_SIZE 10

typedef struct {
    int data[WINDOW_SIZE];
    int index;
} CircularBuffer;

void init_buffer(CircularBuffer *buffer) {
    buffer->index = 0;
}

void push(CircularBuffer *buffer, int value) {
    buffer->data[buffer->index] = value;
    buffer->index = (buffer->index + 1) % WINDOW_SIZE;
}

int pop(CircularBuffer *buffer) {
    int value = buffer->data[buffer->index];
    buffer->index = (buffer->index + 1) % WINDOW_SIZE;
    return value;
}

void moving_average(int *input, int size, float *output) {
    CircularBuffer buffer;
    int i;
    float sum = 0;

    init_buffer(&buffer);

    for (i = 0; i < size; i++) {
        push(&buffer, input[i]);
        if (buffer.index >= WINDOW_SIZE) {
            sum += pop(&buffer) * 1.0;
        }
        if (i >= WINDOW_SIZE - 1) {
            output[i - WINDOW_SIZE + 1] = sum / WINDOW_SIZE;
            sum -= input[i - WINDOW_SIZE] * 1.0;
        }
    }
}

int main() {
    int input[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    float output[WINDOW_SIZE];

    moving_average(input, sizeof(input) / sizeof(int), output);

    for (int i = 0; i < WINDOW_SIZE; i++) {
        printf("Moving average at position %d is %f\n", i, output[i]);
    }

    return 0;
}