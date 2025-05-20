//FormAI DATASET v1.0 Category: Queue ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Defining the Capacity of the Queue
#define QUEUE_CAPACITY 5

// Defining the Queue Structure
typedef struct {
    int data[QUEUE_CAPACITY];
    int front, rear;
    int size;
} Queue;

// Function to create a Queue
Queue* createQueue(){
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
    return queue;
}

// Function to check if the Queue is Empty
int isEmpty(Queue* queue) {
    return queue->size == 0;
}

// Function to check if the Queue is Full
int isFull(Queue* queue) {
    return queue->size == QUEUE_CAPACITY;
}

// Function to Enqueue an element into the Queue
void enqueue(Queue* queue, int element) {

    if(isFull(queue)) {
        printf("Queue overflow!\n");
        return;
    }

    if(queue->front == -1) {
        queue->front = 0;
    }

    queue->rear++;
    queue->data[queue->rear] = element;
    queue->size++;

    printf("%d enqueued to the queue.\n", element);
}

// Function to Dequeue an element from the Queue
int dequeue(Queue* queue) {

    if(isEmpty(queue)) {
        printf("Queue underflow!\n");
        return -1;
    }

    int element = queue->data[queue->front];
    queue->front++;
    queue->size--;

    if(queue->front > queue->rear) {
        queue->front = queue->rear = -1;
    }

    printf("%d dequeued from the queue.\n", element);
    return element;
}

// Function to Display the Queue elements
void display(Queue* queue) {

    if(isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Elements in Queue are: ");
    for(int i=queue->front; i<=queue->rear; i++) {
        printf("%d ", queue->data[i]);
    }
    printf("\n");
}

// Testing the C Queue Example program
int main() {

    Queue* queue = createQueue();

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);
    enqueue(queue, 6); // Trying to Enqueue another element when the Queue is Full

    display(queue);

    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue); // Trying to Dequeue another element when the Queue is Empty

    display(queue);

    free(queue);

    return 0;
}