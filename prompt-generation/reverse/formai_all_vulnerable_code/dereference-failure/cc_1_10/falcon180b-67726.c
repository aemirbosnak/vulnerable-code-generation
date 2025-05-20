//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Define the size of the queue
#define QUEUE_SIZE 10

// Define the structure of the queue
typedef struct Queue {
    int data;
    struct Queue* next;
} Queue;

// Function to create a new node
Queue* newNode(int data) {
    Queue* node = (Queue*)malloc(sizeof(Queue));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to add an element to the end of the queue
void enqueue(Queue** front, Queue** rear, int data) {
    Queue* node = newNode(data);
    if (*rear == NULL) {
        *front = *rear = node;
        return;
    }
    (*rear)->next = node;
    (*rear) = node;
}

// Function to remove an element from the front of the queue
int dequeue(Queue** front, Queue** rear) {
    Queue* temp = *front;
    int data = temp->data;
    if (*front == *rear) {
        *front = *rear = NULL;
        return data;
    }
    *front = temp->next;
    free(temp);
    return data;
}

// Function to check if the queue is empty
int isEmpty(Queue* front, Queue* rear) {
    if (front == rear) {
        return 1;
    }
    return 0;
}

// Function to print the contents of the queue
void printQueue(Queue* front) {
    while (front!= NULL) {
        printf("%d ", front->data);
        front = front->next;
    }
    printf("\n");
}

int main() {
    Queue* front = NULL;
    Queue* rear = NULL;
    int choice, data;

    // Initialize the queue
    enqueue(&front, &rear, 1);
    enqueue(&front, &rear, 2);
    enqueue(&front, &rear, 3);
    enqueue(&front, &rear, 4);
    enqueue(&front, &rear, 5);

    // Display the contents of the queue
    printf("Queue before deletion:\n");
    printQueue(front);

    // Remove elements from the queue
    data = dequeue(&front, &rear);
    printf("Deleted element: %d\n", data);

    data = dequeue(&front, &rear);
    printf("Deleted element: %d\n", data);

    data = dequeue(&front, &rear);
    printf("Deleted element: %d\n", data);

    // Display the contents of the queue
    printf("Queue after deletion:\n");
    printQueue(front);

    // Check if the queue is empty
    if (isEmpty(front, rear)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue is not empty.\n");
    }

    return 0;
}