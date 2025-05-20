//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node structure definition
struct Node {
    int data;
    struct Node* next;
};

// Queue structure definition
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to create an empty queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    if (queue->front == NULL)
        return 1;
    else
        return 0;
}

// Function to add an element to the rear of the queue
void enqueue(struct Queue* queue, int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = value;
    node->next = NULL;

    if (isEmpty(queue)) {
        queue->front = node;
        queue->rear = node;
    }
    else {
        queue->rear->next = node;
        queue->rear = node;
    }
}

// Function to remove an element from the front of the queue
int dequeue(struct Queue* queue) {
    int value = 0;
    struct Node* node = queue->front;

    if (!isEmpty(queue)) {
        value = node->data;
        queue->front = node->next;

        if (queue->front == NULL)
            queue->rear = NULL;

        free(node);
    }

    return value;
}

// Function to display the elements in the queue
void display(struct Queue* queue) {
    struct Node* node = queue->front;

    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Elements in the queue are:\n");
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Queue* queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    display(queue);

    int value = dequeue(queue);
    printf("Dequeued value: %d\n", value);

    display(queue);

    value = dequeue(queue);
    printf("Dequeued value: %d\n", value);

    display(queue);

    value = dequeue(queue);
    printf("Dequeued value: %d\n", value);

    display(queue);

    value = dequeue(queue);
    printf("Dequeued value: %d\n", value);

    display(queue);

    return 0;
}