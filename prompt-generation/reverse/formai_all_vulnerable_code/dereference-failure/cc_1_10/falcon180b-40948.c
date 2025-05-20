//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *front = NULL;
Node *rear = NULL;

// Function to create a new node with the given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add an element to the rear of the queue
void enqueue(int data) {
    Node* newNode = createNode(data);
    if (rear == NULL) {
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

// Function to remove an element from the front of the queue
int dequeue() {
    if (front == NULL) {
        printf("Queue is empty\n");
        exit(0);
    }
    Node* temp = front;
    int data = front->data;
    front = front->next;
    free(temp);
    return data;
}

// Function to display the elements in the queue
void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    Node* temp = front;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to test the implementation
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display();
    dequeue();
    dequeue();
    display();
    return 0;
}