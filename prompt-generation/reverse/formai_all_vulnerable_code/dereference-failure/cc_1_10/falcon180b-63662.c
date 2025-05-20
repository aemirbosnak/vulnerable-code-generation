//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct node* next;
} Node;

Node* front = NULL;
Node* rear = NULL;
int currentSize = 0;

void enqueue(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (rear == NULL) {
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    currentSize++;
}

int dequeue() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    int data = front->data;
    Node* temp = front;
    front = front->next;
    free(temp);
    currentSize--;
    return data;
}

int peek() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    return front->data;
}

int isEmpty() {
    return (front == NULL);
}

int isFull() {
    return (currentSize == MAX_SIZE);
}

void printQueue() {
    Node* temp = front;
    printf("Queue: ");
    while (temp!= NULL) {
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
    printQueue();
    printf("Size of the queue: %d\n", currentSize);
    dequeue();
    dequeue();
    printQueue();
    printf("Size of the queue: %d\n", currentSize);
    return 0;
}