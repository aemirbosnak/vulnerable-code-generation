//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the queue
struct Node {
    int data;
    struct Node* next;
};

// Define the queue structure with a pointer to the front and rear nodes, and the size of the queue
struct Queue {
    struct Node* front;
    struct Node* rear;
    int size;
};

// Function to initialize an empty queue
void initQueue(struct Queue* q) {
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* q) {
    return q->front == NULL;
}

// Function to add an element to the rear of the queue
void enqueue(struct Queue* q, int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }

    q->size++;
}

// Function to remove and return the element at the front of the queue
int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Error: The queue is empty.\n");
        return -1;
    }

    int data = q->front->data;
    struct Node* temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    q->size--;

    return data;
}

// Function to print the elements of the queue
void printQueue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("The queue is empty.\n");
        return;
    }

    printf("The queue contains the following elements:\n");
    struct Node* temp = q->front;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Queue q;
    initQueue(&q);

    // Enqueue some elements
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);

    // Print the queue
    printQueue(&q);

    // Dequeue some elements
    int data1 = dequeue(&q);
    int data2 = dequeue(&q);
    int data3 = dequeue(&q);

    // Print the queue again
    printQueue(&q);

    // Dequeue the remaining elements
    while (!isEmpty(&q)) {
        int data = dequeue(&q);
        printf("Dequeued element: %d\n", data);
    }

    return 0;
}