//MISTRAL-7B DATASET v1.0 Category: Queue Implementation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int size;
    int top;
    int* queue;
} LovelaceQueue;

void lovelace_queue_init(LovelaceQueue* q, int size) {
    q->size = size;
    q->top = -1;
    q->queue = malloc(q->size * sizeof(int));
}

int lovelace_queue_is_empty(LovelaceQueue* q) {
    return q->top == -1;
}

void lovelace_queue_enqueue(LovelaceQueue* q, int data) {
    if (q->top >= q->size - 1) {
        printf("Error: Queue is full.\n");
        return;
    }
    q->queue[++q->top] = data;
}

int lovelace_queue_dequeue(LovelaceQueue* q) {
    if (lovelace_queue_is_empty(q)) {
        printf("Error: Queue is empty.\n");
        return -1;
    }
    return q->queue[q->top--];
}

void lovelace_queue_display(LovelaceQueue* q) {
    printf("Queue content: ");
    for (int i = 0; i <= q->top; ++i) {
        printf("%d ", q->queue[i]);
    }
    printf("\n");
}

void lovelace_queue_destroy(LovelaceQueue* q) {
    free(q->queue);
}

int main() {
    LovelaceQueue queue;
    lovelace_queue_init(&queue, 5);

    lovelace_queue_enqueue(&queue, 3);
    lovelace_queue_enqueue(&queue, 5);
    lovelace_queue_enqueue(&queue, 1);
    lovelace_queue_enqueue(&queue, 4);
    lovelace_queue_enqueue(&queue, 2);

    lovelace_queue_display(&queue);

    lovelace_queue_dequeue(&queue);
    lovelace_queue_display(&queue);

    lovelace_queue_destroy(&queue);

    return 0;
}