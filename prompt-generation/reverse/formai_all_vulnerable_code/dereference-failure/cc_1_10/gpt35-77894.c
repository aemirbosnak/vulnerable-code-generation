//FormAI DATASET v1.0 Category: Queue ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

// defining the queue structure
typedef struct {
    int* items;
    int max_size;
    int head;
    int tail;
    int size;
} Queue;

// function to create a new queue
Queue* create_queue(int max_size) {
    Queue* q = malloc(sizeof(Queue));
    q->items = malloc(max_size * sizeof(int));
    q->max_size = max_size;
    q->head = 0;
    q->tail = -1;
    q->size = 0;
    return q;
}

// function to destroy the queue
void destroy_queue(Queue* q) {
    free(q->items);
    free(q);
}

// function to check if the queue is empty
int is_queue_empty(Queue* q) {
    return q->size == 0;
}

// function to check if the queue is full
int is_queue_full(Queue* q) {
    return q->size == q->max_size;
}

// function to add an item to the queue
void enqueue(Queue* q, int item) {
    if (is_queue_full(q)) {
        printf("The queue is full!");
        return;
    }
    q->tail = (q->tail + 1) % q->max_size;
    q->items[q->tail] = item;
    q->size++;
}

// function to remove an item from the queue
int dequeue(Queue* q) {
    if (is_queue_empty(q)) {
        printf("The queue is empty!");
        return -1;
    }
    int item = q->items[q->head];
    q->head = (q->head + 1) % q->max_size;
    q->size--;
    return item;
}

int main() {

    Queue* q = create_queue(5);

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);

    printf("First item in queue: %d\n", dequeue(q)); // should print 1

    enqueue(q, 4);
    enqueue(q, 5);

    printf("Current queue:\n");
    while (!is_queue_empty(q)) {
        printf("%d\n", dequeue(q));
    }

    destroy_queue(q);

    return 0;
}