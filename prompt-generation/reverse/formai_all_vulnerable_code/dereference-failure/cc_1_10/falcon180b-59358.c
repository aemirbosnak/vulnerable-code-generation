//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct node* next;
} node;

node* front = NULL;
node* rear = NULL;

void enqueue(int data) {
    node* newNode = (node*) malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    if (rear == NULL) {
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

int dequeue() {
    int data;
    if (front == NULL) {
        printf("Queue is empty.\n");
        return -1;
    }
    node* temp = front;
    data = temp->data;
    front = front->next;
    free(temp);
    return data;
}

int peek() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return -1;
    }
    return front->data;
}

void display() {
    node* temp = front;
    printf("Queue: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    display();
    printf("Dequeued element: %d\n", dequeue());
    display();
    printf("Peek element: %d\n", peek());
    return 0;
}