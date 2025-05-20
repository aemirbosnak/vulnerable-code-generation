//FormAI DATASET v1.0 Category: Queue Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10 // Maximum number of elements in the queue

struct Queue { // Queue structure
    int front, rear;
    int array[MAX_SIZE];
};

struct Queue* createQueue() { // Function to initialize the queue
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = -1;
    return queue;
}

int isFull(struct Queue* queue) { // Function to check if the queue is full
    return queue->rear == MAX_SIZE-1;
}

int isEmpty(struct Queue* queue) { // Function to check if the queue is empty
    return queue->front == -1 || queue->front > queue->rear;
}

void enqueue(struct Queue* queue, int data) { // Function to insert an element in the queue
    if(isFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if(isEmpty(queue))
        queue->front = 0;
    queue->array[++queue->rear] = data;
}

int dequeue(struct Queue* queue) { // Function to remove an element from the queue
    if(isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    return queue->array[queue->front++];
}

int front(struct Queue* queue) { // Function to get the front element of the queue
    if(isEmpty(queue)) {
        printf("Queue is empty. Cannot get front element.\n");
        return -1;
    }
    return queue->array[queue->front];
}

int rear(struct Queue* queue) { // Function to get the rear element of the queue
    if(isEmpty(queue)) {
        printf("Queue is empty. Cannot get rear element.\n");
        return -1;
    }
    return queue->array[queue->rear];
}

int main() {
    struct Queue* queue = createQueue(); // Creating a queue
    printf("Initial queue: \n");
    
    // Enqueuing elements
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);
    enqueue(queue, 60);
    
    // Dequeuing elements
    printf("Dequeuing elements: \n");
    printf("%d dequeued from queue.\n", dequeue(queue));
    printf("%d dequeued from queue.\n", dequeue(queue));
    
    // Front and Rear elements
    printf("Front element of queue: %d\n", front(queue));
    printf("Rear element of queue: %d\n", rear(queue));
    
    // Enqueuing more elements
    enqueue(queue, 70);
    enqueue(queue, 80);
    enqueue(queue, 90);
    printf("Final queue: \n");
    
    // Dequeuing all elements
    while(!isEmpty(queue)) {
        printf("%d dequeued from queue.\n", dequeue(queue));
    }

    return 0;
}