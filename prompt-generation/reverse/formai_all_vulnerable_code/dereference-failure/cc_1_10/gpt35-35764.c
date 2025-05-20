//FormAI DATASET v1.0 Category: Queue ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

// Define the Queue structure
struct Queue {
    int front, rear, size;
    int* array;
};

// Function to create a queue
struct Queue* createQueue(int size) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->size = 0;
    queue->rear = size - 1;
    queue->array = (int*)malloc(size * sizeof(int));
    return queue;
}

// Function to check if the queue is full
int isFull(struct Queue* queue) {
    return (queue->size == MAX_QUEUE_SIZE);
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

// Function to add an element to the queue
void enqueue(struct Queue* queue, int item) {
    if (isFull(queue)) {
        printf("\nOops, the queue is already full!");
        return;
    }
    queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
    queue->array[queue->rear] = item;
    queue->size++;
    printf("\nYay! '%d' has been added to the queue!",item);
}

// Function to remove an element from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("\nAwww, the queue is already empty!");
        return -1;
    }
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
    queue->size--;
    printf("\nYay! '%d' has been removed from the queue!",item);
    return item;
}

int main() {
    // create a queue of capacity MAX_QUEUE_SIZE
    struct Queue* queue = createQueue(MAX_QUEUE_SIZE);

    // add some elements to the queue
    enqueue(queue, 5);
    enqueue(queue, 10);
    enqueue(queue, 15);
    enqueue(queue, 20);

    // remove an element from the queue
    int item = dequeue(queue);

    // display the dequeued item
    printf("\n\nThe dequeued item is: %d", item);

    // add some more elements to the queue
    enqueue(queue, 25);
    enqueue(queue, 30);

    return 0;
}