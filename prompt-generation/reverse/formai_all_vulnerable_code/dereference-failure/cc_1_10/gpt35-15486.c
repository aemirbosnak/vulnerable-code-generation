//FormAI DATASET v1.0 Category: Queue Implementation ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Create structure for Queue
struct Queue {
    int front, rear, size;
    unsigned capacity;
    int *array;
};

// Create function to create a Queue
struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

// Create function to check if Queue is full
int isFull(struct Queue* queue) {
    return (queue->size == queue->capacity);
}

// Create function to check if Queue is empty.
int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

// Create function to add a number to the back of the Queue
void enqueue(struct Queue* queue, int item) {
    if (isFull(queue)) {
        printf("\nQueue is full, unable to add item %d\n", item);
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
    printf("%d added to the Queue\n", item);
}

// Create function to remove number from the front of the Queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue))
        return -1; // Return error code since Queue is empty
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

// The Main function
int main() {
    struct Queue* queue = createQueue(5);

    // Add values to the Queue
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);
    enqueue(queue, 6);
    enqueue(queue, 7); // This will not be able to add since queue is full
    
    // Remove values from the Queue
    printf("Front value of Queue: %d\n", dequeue(queue));
    printf("Front value of Queue: %d\n", dequeue(queue));
    printf("Front value of Queue: %d\n", dequeue(queue));
    printf("Front value of Queue: %d\n", dequeue(queue));
    printf("Front value of Queue: %d\n", dequeue(queue));
    printf("Front value of Queue: %d\n", dequeue(queue)); // This will not be able to remove since queue is empty 
    
    return 0;
}