//FormAI DATASET v1.0 Category: Queue Implementation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

// define struct for queue
typedef struct Queue {
    int front;
    int rear;
    int size;
    int* array;
} Queue;

// function to create queue
Queue* createQueue(int size) {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    queue->size = size;
    queue->array = (int*) malloc(size * sizeof(int));
    return queue;
}

// function to check if queue is empty
int isEmpty(Queue* queue) {
    return queue->front == -1;
}

// function to check if queue is full
int isFull(Queue* queue) {
    return queue->rear == queue->size - 1;
}

// function to add element to queue
void enqueue(Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full, cannot enqueue element.\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear++;
    queue->array[queue->rear] = item;
}

// function to remove element from queue
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty, cannot dequeue element.\n");
        return -1;
    }
    int item = queue->array[queue->front];
    queue->front++;
    if (queue->front > queue->rear) {
        queue->front = queue->rear = -1;
    }
    return item;
}

// function to peek front element of queue
int peek(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty, no front element to peek.\n");
        return -1;
    }
    return queue->array[queue->front];
}

// function to print queue
void printQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->array[i]);
    }
    printf("\n");
}

int main() {
    // create queue of size 5
    Queue* queue = createQueue(5);
    
    // enqueue some elements
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    
    // print the queue
    printQueue(queue);
    
    // peek front element
    int front = peek(queue);
    printf("Front element = %d\n", front);
    
    // dequeue an element
    int elem = dequeue(queue);
    printf("Dequeued element = %d\n", elem);
    
    // print the queue
    printQueue(queue);
    
    // enqueue some more elements
    enqueue(queue, 40);
    enqueue(queue, 50);
    enqueue(queue, 60);
    
    // attempt to enqueue an element while queue is full
    enqueue(queue, 70);
    
    // print the queue
    printQueue(queue);
    
    // dequeue all elements
    while (!isEmpty(queue)) {
        int elem = dequeue(queue);
        printf("Dequeued element = %d\n", elem);
    }
    
    // print the queue
    printQueue(queue);
    
    // free memory
    free(queue->array);
    free(queue);
    
    return 0;
}