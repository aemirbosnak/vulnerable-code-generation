//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Maximum size of the queue

typedef struct {
    int data;
    struct Node* next;
} Node;

Node* front = NULL; // Pointer to the front of the queue
Node* rear = NULL; // Pointer to the rear of the queue

void enqueue(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // Allocate memory for the new node
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) { // If the queue is empty, set the front and rear pointers to the new node
        front = newNode;
        rear = newNode;
    }
    else { // Otherwise, add the new node to the rear of the queue
        rear->next = newNode;
        rear = newNode;
    }
}

int dequeue() {
    int value = -1; // Initialize the value to -1, which indicates that the queue is empty

    if (front!= NULL) { // If the queue is not empty, remove the front node and update the front pointer
        value = front->data;
        Node* temp = front;
        front = front->next;
        free(temp); // Free the memory allocated for the removed node
    }

    if (front == NULL && rear == NULL) { // If the queue is now empty, reset the rear pointer
        rear = NULL;
    }

    return value;
}

void display() {
    Node* temp = front; // Start at the front of the queue
    printf("Queue: ");

    while (temp!= NULL) { // Iterate through the nodes in the queue and print their values
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    printf("Queue after enqueue: ");
    display();

    int value = dequeue();
    printf("Dequeued value: %d\n", value);

    printf("Queue after dequeue: ");
    display();

    value = dequeue();
    printf("Dequeued value: %d\n", value);

    printf("Queue after dequeue: ");
    display();

    value = dequeue();
    printf("Dequeued value: %d\n", value);

    printf("Queue after dequeue: ");
    display();

    value = dequeue();
    printf("Dequeued value: %d\n", value);

    printf("Queue after dequeue: ");
    display();

    value = dequeue();
    printf("Dequeued value: %d\n", value);

    printf("Queue after dequeue: ");
    display();

    value = dequeue();
    printf("Dequeued value: %d\n", value);

    return 0;
}