//FormAI DATASET v1.0 Category: Queue Implementation ; Style: Ada Lovelace
#include <stdio.h> 
#include <stdlib.h> 

// define the queue data structure
typedef struct Queue {
    int front;
    int rear;
    int capacity;
    int* array;
} Queue;

// function to create a queue
Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = 0;
    queue->rear = -1;
    queue->capacity = capacity;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

// function to check if the queue is full
int isFull(Queue* queue) {
    return queue->rear == queue->capacity - 1;
}

// function to check if the queue is empty
int isEmpty(Queue* queue) {
    return queue->front == queue->rear + 1;
}

// function to add an element to the queue
void enqueue(Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full\n");
        return;
    }
    queue->rear++;
    queue->array[queue->rear] = item;
    printf("%d added to the queue\n", item);
}

// function to remove an element from the queue
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    int item = queue->array[queue->front];
    queue->front++;
    printf("%d removed from the queue\n", item);
    return item;
}

int main() {
    Queue* queue = createQueue(5);
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);

    dequeue(queue);
    dequeue(queue);
    dequeue(queue);

    enqueue(queue, 60);
    enqueue(queue, 70);

    return 0;
}