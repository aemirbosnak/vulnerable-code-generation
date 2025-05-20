//FormAI DATASET v1.0 Category: Queue ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Define a structure for our circular queue
typedef struct {
    int *elements;  // stores the elements of the queue
    int front;      // index of the front element of the queue
    int rear;       // index of the rear element of the queue
    int maxSize;    // maximum number of elements that can be stored in the queue
    int currSize;   // current number of elements in the queue
} Queue;

// Create a new queue with a given max size
Queue* createQueue(int maxSize) {
    Queue *queue = (Queue*) malloc(sizeof(Queue));
    queue->elements = (int*) malloc(sizeof(int) * maxSize);
    queue->maxSize = maxSize;
    queue->currSize = 0;
    queue->front = 0;
    queue->rear = -1;
    return queue;
}

// Enqueue a new element into the queue
void enqueue(Queue *queue, int data) {
    if (queue->currSize == queue->maxSize) {
        printf("Sorry, but this queue is full.\n");
        return;
    }
    queue->rear = (queue->rear + 1) % queue->maxSize;
    queue->elements[queue->rear] = data;
    queue->currSize++;
    printf("Thank you for enqueuing %d into the queue!\n", data);
}

// Dequeue an element from the queue
void dequeue(Queue *queue) {
    if (queue->currSize == 0) {
        printf("Sorry, but there are no elements in this queue to dequeue.\n");
        return;
    }
    int data = queue->elements[queue->front];
    queue->front = (queue->front + 1) % queue->maxSize;
    queue->currSize--;
    printf("Thank you for dequeuing %d from the queue!\n", data);
}

// Print out the elements of the queue
void printQueue(Queue *queue) {
    printf("Current elements in the queue: ");
    int i;
    for (i = 0; i < queue->currSize; i++) {
        int index = (queue->front + i) % queue->maxSize;
        printf("%d ", queue->elements[index]);
    }
    printf("\n");
}

// Example usage of the queue
int main() {
    Queue *myQueue = createQueue(5);
    enqueue(myQueue, 1);
    printQueue(myQueue);  // 1
    enqueue(myQueue, 2);
    printQueue(myQueue);  // 1 2
    enqueue(myQueue, 3);
    printQueue(myQueue);  // 1 2 3
    enqueue(myQueue, 4);
    printQueue(myQueue);  // 1 2 3 4
    enqueue(myQueue, 5);
    printQueue(myQueue);  // 1 2 3 4 5
    enqueue(myQueue, 6);  // Sorry, but this queue is full
    dequeue(myQueue);
    printQueue(myQueue);  // 2 3 4 5
    dequeue(myQueue);
    printQueue(myQueue);  // 3 4 5
    dequeue(myQueue);
    printQueue(myQueue);  // 4 5
    enqueue(myQueue, 6);
    printQueue(myQueue);  // 4 5 6
    dequeue(myQueue);
    dequeue(myQueue);
    dequeue(myQueue);
    dequeue(myQueue);  // Sorry, but there are no elements in this queue to dequeue
    return 0;
}