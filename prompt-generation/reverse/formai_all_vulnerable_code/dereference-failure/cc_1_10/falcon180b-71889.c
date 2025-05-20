//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

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
struct Queue* createQueue(void) {
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->front == NULL && queue->rear == NULL);
}

// Function to add an element to the rear of the queue
void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Function to remove an element from the front of the queue
int dequeue(struct Queue* queue) {
    int data;
    struct Node* tempNode = queue->front;

    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1;
    }

    data = tempNode->data;
    queue->front = tempNode->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(tempNode);
    return data;
}

// Function to display the elements in the queue
void display(struct Queue* queue) {
    struct Node* tempNode = queue->front;

    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements are: ");
    while (tempNode!= NULL) {
        printf("%d ", tempNode->data);
        tempNode = tempNode->next;
    }
    printf("\n");
}

int main() {
    struct Queue* queue = createQueue();

    // Adding elements to the queue
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    // Displaying the queue
    printf("Queue after adding elements: ");
    display(queue);

    // Removing elements from the queue
    printf("\nElements removed from the queue: ");
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);

    // Displaying the queue after removing elements
    printf("\nQueue after removing elements: ");
    display(queue);

    return 0;
}