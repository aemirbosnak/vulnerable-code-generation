//FormAI DATASET v1.0 Category: Queue Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// Define structure of the Queue
typedef struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* arr;
}Queue;

// Create a new Queue
Queue* createQueue(unsigned capacity) {
    Queue* newQueue = (Queue*)malloc(sizeof(Queue));
    newQueue->capacity = capacity;
    newQueue->front = newQueue->size = 0;
    newQueue->rear = capacity - 1;
    newQueue->arr = (int*)malloc(newQueue->capacity * sizeof(int));
    return newQueue;
}

// Check if the Queue is full
int isFull(Queue* queue) {
    return (queue->size == queue->capacity);
}

// Check if the Queue is empty
int isEmpty(Queue* queue) {
    return (queue->size == 0);
}

// Enqueue an element to the Queue and return 1 if successful
int enqueue(Queue* queue, int item) {
    if (isFull(queue)){
        return 0;
    }
    queue->rear = (queue->rear + 1)%queue->capacity;
    queue->arr[queue->rear] = item;
    queue->size++;
    return 1;
}

// Dequeue the first element from the Queue and return its value
int dequeue(Queue* queue) {
    if (isEmpty(queue)){
        return -1;
    }
    int item = queue->arr[queue->front];
    queue->front = (queue->front + 1)%queue->capacity;
    queue->size--;
    return item;
}

// Display the elements of the Queue
void display(Queue* queue) {
    int i;
    for (i = 0; i < queue->size; i++) {
        printf("%d ", queue->arr[(queue->front + i) % queue->capacity]);
    }
    printf("\n");
}

// Driver function to test the Queue implementation
int main() {
    Queue* queue = createQueue(5);

    printf("Enqueue to the Queue: \n");
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    display(queue);
    printf("\n");

    printf("Dequeue from the Queue: \n");
    int val = dequeue(queue);
    printf("%d was dequeued\n", val);
    display(queue);
    printf("\n");

    printf("Enqueue to the Queue: \n");
    enqueue(queue, 4);
    enqueue(queue, 5);
    display(queue);
    printf("\n");

    printf("Try to enqueue to the full Queue: \n");
    if (enqueue(queue, 6)) {
        printf("Successfully enqueued 6.\n");
    }
    else {
        printf("Failed to enqueue 6. Queue is full\n");
    }

    return 0;
}