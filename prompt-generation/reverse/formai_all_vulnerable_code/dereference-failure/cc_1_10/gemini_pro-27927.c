//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a queue
struct Queue {
    int front, rear, size;
    int *array;
};

// Function to create a queue of given size
struct Queue* createQueue(int size) {
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->front = queue->rear = -1;
    queue->size = size;
    queue->array = (int*) malloc(queue->size * sizeof(int));
    return queue;
}

// Function to check if the queue is full
int isFull(struct Queue* queue) {
    return (queue->rear == queue->size - 1);
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->front == -1);
}

// Function to add an element to the queue
void enqueue(struct Queue* queue, int element) {
    if (isFull(queue))
        return;
    else {
        if (queue->front == -1)
            queue->front = 0;
        queue->rear++;
        queue->array[queue->rear] = element;
    }
}

// Function to remove an element from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue))
        return (-1);
    else {
        int element = queue->array[queue->front];
        queue->front++;
        if (queue->front > queue->rear)
            queue->front = queue->rear = -1;
        return (element);
    }
}

// Function to display the elements of the queue
void display(struct Queue* queue) {
    if (isEmpty(queue))
        printf("Queue is empty.\n");
    else {
        printf("Queue elements:\n");
        int i;
        for (i = queue->front; i <= queue->rear; i++)
            printf("%d  ", queue->array[i]);
        printf("\n");
    }
}

// Main function to test the queue functions
int main() {
    struct Queue* queue = createQueue(5);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);

    display(queue);

    printf("Dequeued element from queue: %d\n", dequeue(queue));
    printf("Dequeued element from queue: %d\n", dequeue(queue));

    display(queue);

    enqueue(queue, 60);
    enqueue(queue, 70);

    display(queue);

    printf("Dequeued element from queue: %d\n", dequeue(queue));
    printf("Dequeued element from queue: %d\n", dequeue(queue));
    printf("Dequeued element from queue: %d\n", dequeue(queue));
    printf("Dequeued element from queue: %d\n", dequeue(queue));
    printf("Dequeued element from queue: %d\n", dequeue(queue));

    if (isEmpty(queue))
        printf("Queue is empty.\n");
    else
        printf("Queue is not empty.\n");

    return 0;
}