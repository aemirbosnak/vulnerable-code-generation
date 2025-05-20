//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

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
void createQueue(struct Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->front == NULL && queue->rear == NULL);
}

// Function to check if the queue is full
int isFull(struct Queue* queue) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if (temp == NULL) {
        return 1;
    }
    free(temp);
    return 0;
}

// Function to add an element to the queue
void enqueue(struct Queue* queue, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Queue is full. Cannot enqueue %d\n", value);
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    }
    else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Function to remove an element from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    struct Node* temp = queue->front;
    int value = temp->data;
    queue->front = temp->next;
    free(temp);
    return value;
}

// Function to display the contents of the queue
void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    struct Node* temp = queue->front;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct Queue queue;
    createQueue(&queue);
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 40);
    display(&queue);
    printf("Dequeued: %d\n", dequeue(&queue));
    display(&queue);
    printf("Dequeued: %d\n", dequeue(&queue));
    display(&queue);
    printf("Dequeued: %d\n", dequeue(&queue));
    display(&queue);
    printf("Dequeued: %d\n", dequeue(&queue));
    return 0;
}