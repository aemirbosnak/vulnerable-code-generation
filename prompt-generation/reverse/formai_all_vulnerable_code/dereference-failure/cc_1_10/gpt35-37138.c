//FormAI DATASET v1.0 Category: Queue Implementation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

/* Define the structure for queue */
struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

/* Function to create a queue */
struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;  /* Important point of consideration while implementing circular queue */
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

/* Function to check if queue is full */
int isFull(struct Queue* queue) {
    return (queue->size == queue->capacity);
}

/* Function to check if queue is empty */
int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

/* Function to add an element to the queue (enqueue) */
void enqueue(struct Queue* queue, int item) {
    if (isFull(queue))
        return;  // Overflow condition
    queue->rear = (queue->rear + 1) % queue->capacity;  // Circular increment to provide array like behavior
    queue->array[queue->rear] = item;
    queue->size++;
    printf("%d enqueued to queue\n", item);
}

/* Function to remove an element from the queue (dequeue) */
int dequeue(struct Queue* queue) {
    if (isEmpty(queue))
        return -1;  // Underflow condition
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;  // Circular increment to provide array like behavior
    queue->size--;
    printf("%d dequeued from queue\n", item);
    return item;
}

/* Function to obtain the front element of the queue (peek) */
int front(struct Queue* queue) {
    if (isEmpty(queue))
        return -1;  // Underflow condition
    return queue->array[queue->front];
}

/* Function to obtain the rear element of the queue */
int rear(struct Queue* queue) {
    if (isEmpty(queue))
        return -1;  // Underflow condition
    return queue->array[queue->rear];
}

/* Driver code */
int main() {
    struct Queue* queue = createQueue(100);
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    printf("Front element is %d\n", front(queue));
    printf("Rear element is %d\n", rear(queue));
    dequeue(queue);
    printf("Front element is %d\n", front(queue));
    printf("Rear element is %d\n", rear(queue));
    return 0;
}