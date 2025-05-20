//FormAI DATASET v1.0 Category: Queue ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

/* define the structure of the queue */
struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

/* function to create a queue */
struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*) malloc(queue->capacity * sizeof(int));
    return queue;
}

/* function to check if the queue is full */
int isFull(struct Queue* queue) {
    return (queue->size == queue->capacity);
}

/* function to check if the queue is empty */
int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

/* function to add an element to the queue */
void enqueue(struct Queue* queue, int item) {
    if (isFull(queue))
        printf("Queue is full. Cannot add element.\n");
    else {
        queue->rear = (queue->rear + 1) % queue->capacity;
        queue->array[queue->rear] = item;
        queue->size++;
        printf("%d added to the queue. Size of queue: %d\n", item, queue->size);
    }
}

/* function to remove an element from the queue */
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot remove element.\n");
        return -1;
    }
    else {
        int item = queue->array[queue->front];
        queue->front = (queue->front + 1) % queue->capacity;
        queue->size--;
        printf("%d removed from the queue. Size of queue: %d\n", item, queue->size);
        return item;
    }
}

/* main function */
int main() {

    struct Queue* queue = createQueue(5);

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);
    enqueue(queue, 6);

    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);

    return 0;
}