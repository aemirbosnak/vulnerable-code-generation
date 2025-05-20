//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    struct Node* next;
} Node;

Node* front = NULL;
Node* rear = NULL;

void init() {
    front = rear = NULL;
}

bool isEmpty() {
    return front == NULL;
}

bool isFull() {
    Node* temp = front;
    int count = 0;
    while (temp!= NULL) {
        count++;
        temp = temp->next;
    }
    return count == MAX_SIZE;
}

void enqueue(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(0);
    }
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

int dequeue() {
    if (isEmpty()) {
        printf("Error: Queue is empty\n");
        exit(0);
    }
    int value = front->data;
    Node* temp = front;
    front = front->next;
    free(temp);

    if (isEmpty()) {
        rear = NULL;
    }
    return value;
}

int peek() {
    if (isEmpty()) {
        printf("Error: Queue is empty\n");
        exit(0);
    }
    return front->data;
}

void display() {
    Node* temp = front;
    printf("Queue elements are: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    init();
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display();
    printf("Dequeued element is: %d\n", dequeue());
    display();
    printf("Peek element is: %d\n", peek());
    return 0;
}