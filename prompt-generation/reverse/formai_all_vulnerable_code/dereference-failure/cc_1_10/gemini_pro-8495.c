//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of elements in the queue
#define MAX_SIZE 10

// Define the structure of a queue element
typedef struct QueueElement {
    int data;
    struct QueueElement *next;
} QueueElement;

// Define the structure of a queue
typedef struct Queue {
    QueueElement *front;
    QueueElement *rear;
    int size;
} Queue;

// Create a new queue
Queue *createQueue() {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

// Check if the queue is empty
int isEmpty(Queue *queue) {
    return queue->size == 0;
}

// Add an element to the rear of the queue
void enqueue(Queue *queue, int data) {
    QueueElement *newElement = (QueueElement *)malloc(sizeof(QueueElement));
    newElement->data = data;
    newElement->next = NULL;

    if (isEmpty(queue)) {
        queue->front = newElement;
        queue->rear = newElement;
    } else {
        queue->rear->next = newElement;
        queue->rear = newElement;
    }

    queue->size++;
}

// Remove an element from the front of the queue
int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("The queue is empty.\n");
        return -1;
    }

    QueueElement *temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;
    free(temp);

    queue->size--;

    if (queue->size == 0) {
        queue->rear = NULL;
    }

    return data;
}

// Get the front element of the queue
int front(Queue *queue) {
    if (isEmpty(queue)) {
        printf("The queue is empty.\n");
        return -1;
    }

    return queue->front->data;
}

// Get the rear element of the queue
int rear(Queue *queue) {
    if (isEmpty(queue)) {
        printf("The queue is empty.\n");
        return -1;
    }

    return queue->rear->data;
}

// Print the queue
void printQueue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("The queue is empty.\n");
        return;
    }

    QueueElement *temp = queue->front;
    printf("The queue is: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Get the size of the queue
int size(Queue *queue) {
    return queue->size;
}

// Destroy the queue
void destroyQueue(Queue *queue) {
    while (!isEmpty(queue)) {
        dequeue(queue);
    }
    free(queue);
}

// Main function
int main() {
    // Create a queue
    Queue *queue = createQueue();

    // Enqueue some elements
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    // Print the queue
    printQueue(queue);

    // Get the front element
    printf("The front element is: %d\n", front(queue));

    // Get the rear element
    printf("The rear element is: %d\n", rear(queue));

    // Get the size of the queue
    printf("The size of the queue is: %d\n", size(queue));

    // Dequeue some elements
    dequeue(queue);
    dequeue(queue);

    // Print the queue
    printQueue(queue);

    // Get the front element
    printf("The front element is: %d\n", front(queue));

    // Get the rear element
    printf("The rear element is: %d\n", rear(queue));

    // Get the size of the queue
    printf("The size of the queue is: %d\n", size(queue));

    // Destroy the queue
    destroyQueue(queue);

    return 0;
}