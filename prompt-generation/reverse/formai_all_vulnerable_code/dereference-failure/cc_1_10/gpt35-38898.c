//FormAI DATASET v1.0 Category: Queue Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Define Queue struct
typedef struct {
    int front;
    int rear;
    int size;
    int* data;
} Queue;

// Define functions
void enqueue(Queue* q, int element);
int dequeue(Queue* q);
void print_queue(Queue* q);

int main() {
    Queue my_queue;
    my_queue.front = 0;
    my_queue.rear = -1;
    my_queue.size = 5;
    my_queue.data = malloc(my_queue.size * sizeof(int));

    printf("Hello, I'm a happy Queue Implementation!\n");

    // Enqueue elements
    enqueue(&my_queue, 1);
    enqueue(&my_queue, 2);
    enqueue(&my_queue, 3);
    enqueue(&my_queue, 4);
    enqueue(&my_queue, 5);

    printf("\nAfter enqueueing 5 elements: ");
    print_queue(&my_queue);

    // Dequeue elements
    dequeue(&my_queue);
    dequeue(&my_queue);

    printf("\nAfter dequeueing 2 elements: ");
    print_queue(&my_queue);

    // Enqueue more elements
    enqueue(&my_queue, 6);
    enqueue(&my_queue, 7);

    printf("\nAfter enqueueing 2 more elements: ");
    print_queue(&my_queue);

    printf("\nYay, I'm a happy Queue and my job is done! :D");

    return 0;
}

void enqueue(Queue* q, int element) {
    if (q->rear == q->size - 1) {
        printf("\nSorry, the queue is full!");
    }
    else {
        q->rear++;
        q->data[q->rear] = element;
        printf("\nElement %d enqueued successfully!", element);
    }
}

int dequeue(Queue* q) {
    if (q->front > q->rear) {
        printf("\nSorry, the queue is empty!");
        return -1;
    }
    else {
        int element = q->data[q->front];
        q->front++;
        printf("\nElement %d dequeued successfully!", element);
        return element;
    }
}

void print_queue(Queue* q) {
    int i;
    printf("\nQueue: ");
    for (i = q->front; i <= q->rear; i++) {
        printf("%d ", q->data[i]);
    }
}