//FormAI DATASET v1.0 Category: Queue Implementation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

// defining a structure for the queue data structure
typedef struct Queue {
    int capacity; // capacity of the queue
    int front; // front index of the queue
    int rear; // rear index of the queue
    int size; // size of the queue
    int* elements; // dynamic array to hold the elements of the queue
} Queue;

// function to create a new queue
Queue* createQueue(int capacity) {
    // allocating memory for the new queue
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    // initializing the queue variables
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->elements = (int*) malloc(capacity * sizeof(int));
    return queue;
}

// function to check if the queue is full
int isFull(Queue* queue) {
    return (queue->size == queue->capacity);
}

// function to check if the queue is empty
int isEmpty(Queue* queue) {
    return (queue->size == 0);
}

// function to add an element to the rear of the queue
void enqueue(Queue* queue, int element) {
    // check if the queue is full
    if (isFull(queue)) {
        printf("Queue is full, element %d could not be added\n", element);
        return;
    }
    // update the rear index of the queue
    queue->rear = (queue->rear + 1) % queue->capacity;
    // add the new element to the queue
    queue->elements[queue->rear] = element;
    // increment the size of the queue
    queue->size++;
    printf("Element %d added to the queue\n", element);
}

// function to remove an element from the front of the queue
int dequeue(Queue* queue) {
    // check if the queue is empty
    if (isEmpty(queue)) {
        printf("Queue is empty, cannot dequeue\n");
        return -1;
    }
    // remove the front element from the queue
    int element = queue->elements[queue->front];
    // update the front index of the queue
    queue->front = (queue->front + 1) % queue->capacity;
    // decrement the size of the queue
    queue->size--;
    printf("Element %d removed from queue\n", element);
    return element;
}

// function to get the front element of the queue
int front(Queue* queue) {
    // check if the queue is empty
    if (isEmpty(queue)) {
        printf("Queue is empty, no front element\n");
        return -1;
    }
    // return the front element of the queue
    return queue->elements[queue->front];
}

// function to display the queue elements
void display(Queue* queue) {
    // check if the queue is empty
    if (isEmpty(queue)) {
        printf("Queue is empty, nothing to display\n");
        return;
    }
    // loop through the elements of the queue and print them
    printf("Queue elements: ");
    for (int i = 0; i < queue->size; i++) {
        printf("%d ", queue->elements[(queue->front + i) % queue->capacity]);
    }
    printf("\n");
}

int main() {
    // create a new queue with capacity 5
    Queue* queue = createQueue(5);
    
    // enqueue some elements to the queue
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    // try to enqueue another element but the queue is full
    enqueue(queue, 6);

    // display the queue elements
    display(queue);

    // remove some elements from the queue
    dequeue(queue);
    dequeue(queue);

    // display the queue elements again
    display(queue);

    // get the front element of the queue
    printf("Front element of queue: %d\n", front(queue));

    // remove all elements from the queue
    while (!isEmpty(queue)) {
        dequeue(queue);
    }

    // display the queue elements again
    display(queue);

    // free the memory allocated for the queue
    free(queue);
    return 0;
}