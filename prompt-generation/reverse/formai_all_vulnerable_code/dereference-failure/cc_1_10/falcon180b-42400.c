//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    int priority;
} QueueElement;

typedef struct {
    QueueElement *elements[MAX_SIZE];
    int front;
    int rear;
    int size;
} Queue;

// Function to create a new empty queue
Queue* createQueue() {
    Queue *queue = (Queue*) malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
    return queue;
}

// Function to add an element to the rear of the queue
void enqueue(Queue* queue, int data, int priority) {
    QueueElement *element = (QueueElement*) malloc(sizeof(QueueElement));
    element->data = data;
    element->priority = priority;
    if (queue->rear == -1) {
        queue->front = 0;
        queue->rear = 0;
        queue->elements[0] = element;
    } else {
        queue->rear++;
        queue->elements[queue->rear] = element;
    }
    queue->size++;
}

// Function to remove an element from the front of the queue
QueueElement* dequeue(Queue* queue) {
    QueueElement *element = NULL;
    if (queue->front!= -1) {
        element = queue->elements[queue->front];
        if (queue->front == queue->rear) {
            queue->front = -1;
            queue->rear = -1;
        } else {
            queue->front++;
        }
        queue->size--;
    }
    return element;
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    return queue->front == -1;
}

// Function to print the contents of the queue
void printQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
    } else {
        printf("Elements in the queue:\n");
        for (int i = queue->front; i <= queue->rear; i++) {
            printf("Data: %d, Priority: %d\n", queue->elements[i]->data, queue->elements[i]->priority);
        }
    }
}

int main() {
    Queue* queue = createQueue();
    enqueue(queue, 1, 2);
    enqueue(queue, 2, 1);
    enqueue(queue, 3, 3);
    enqueue(queue, 4, 1);
    enqueue(queue, 5, 2);
    printQueue(queue);
    QueueElement* element = dequeue(queue);
    printf("Dequeued element: Data: %d, Priority: %d\n", element->data, element->priority);
    printQueue(queue);
    free(element);
    return 0;
}