//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

// Define the queue structure
struct queue {
    int *array;
    int head;
    int tail;
    int size;
};

// Create a new queue
struct queue *create_queue(int size) {
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->array = (int *)malloc(size * sizeof(int));
    q->head = 0;
    q->tail = 0;
    q->size = size;
    return q;
}

// Destroy a queue
void destroy_queue(struct queue *q) {
    free(q->array);
    free(q);
}

// Enqueue an element into the queue
void enqueue(struct queue *q, int element) {
    q->array[q->tail] = element;
    q->tail++;
    if (q->tail == q->size) {
        q->tail = 0;
    }
    if (q->tail == q->head) {
        printf("Queue is full!\n");
        exit(1);
    }
}

// Dequeue an element from the queue
int dequeue(struct queue *q) {
    if (q->head == q->tail) {
        printf("Queue is empty!\n");
        exit(1);
    }
    int element = q->array[q->head];
    q->head++;
    if (q->head == q->size) {
        q->head = 0;
    }
    return element;
}

// Print the queue
void print_queue(struct queue *q) {
    printf("Queue: ");
    for (int i = q->head; i != q->tail; i++) {
        printf("%d ", q->array[i]);
    }
    printf("\n");
}

// Main function
int main() {
    // Create a new queue
    struct queue *q = create_queue(5);

    // Enqueue some elements into the queue
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);

    // Print the queue
    print_queue(q);

    // Dequeue some elements from the queue
    dequeue(q);
    dequeue(q);

    // Print the queue
    print_queue(q);

    // Destroy the queue
    destroy_queue(q);

    return 0;
}