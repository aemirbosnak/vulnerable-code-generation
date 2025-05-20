//FormAI DATASET v1.0 Category: Queue Implementation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

// Defining the Queue data structure
typedef struct queue {
    int front, rear, size;
    unsigned int capacity;
    int* array;
} Queue;

// Creating a Queue function to create a new queue with maximum capacity
Queue* createQueue(unsigned int capacity) {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*) malloc(queue->capacity * sizeof(int));
    return queue;
}

// Queue is full when size equals capacity
int isFull(Queue* queue) {
    return (queue->size == queue->capacity);
}

// Queue is empty when size equals 0
int isEmpty(Queue* queue) {
    return (queue->size == 0);
}

// Adding an element to the Queue
void enqueue(Queue* queue, int item) {
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
    printf("%d added to the Queue\n", item);
}

// Removing an element from the Queue
int dequeue(Queue* queue) {
    if (isEmpty(queue))
        return -1;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

// Displaying the contents of the Queue
void display(Queue* queue) {
    if (isEmpty(queue))
        printf("The Queue is empty\n");
    else {
        printf("The Queue contains: ");
        for (int i = queue->front; i <= queue->rear; i++)
            printf("%d ", queue->array[i]);
        printf("\n");
    }
}

// Driver function to test the Queue functions
int main() {
    Queue* queue = createQueue(5);
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);
    display(queue);
    printf("%d removed from the Queue\n", dequeue(queue));
    printf("%d removed from the Queue\n", dequeue(queue));
    display(queue);
    printf("Adding 60 to the queue\n");
    enqueue(queue, 60);
    display(queue);
    free(queue->array);
    free(queue);
    return 0;
}