//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// A queue node
struct QNode {
    int data;
    struct QNode *next;
};

// A queue
struct Queue {
    struct QNode *front, *rear;
};

// Create a new queue
struct Queue *createQueue() {
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Check if the queue is empty
bool isEmpty(struct Queue *queue) {
    return (queue->front == NULL);
}

// Enqueue an element into the queue
void enqueue(struct Queue *queue, int data) {
    struct QNode *newNode = (struct QNode *)malloc(sizeof(struct QNode));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Dequeue an element from the queue
int dequeue(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }

    struct QNode *temp = queue->front;
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    int data = temp->data;
    free(temp);
    return data;
}

// Print the queue
void printQueue(struct Queue *queue) {
    struct QNode *temp = queue->front;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

// Get the size of the queue
int size(struct Queue *queue) {
    int count = 0;
    struct QNode *temp = queue->front;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

// Test the queue
int main() {
    struct Queue *queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);

    printf("The queue is: ");
    printQueue(queue);

    printf("The size of the queue is: %d\n", size(queue));

    dequeue(queue);
    dequeue(queue);

    printf("The queue after dequeue is: ");
    printQueue(queue);

    printf("The size of the queue is: %d\n", size(queue));

    return 0;
}