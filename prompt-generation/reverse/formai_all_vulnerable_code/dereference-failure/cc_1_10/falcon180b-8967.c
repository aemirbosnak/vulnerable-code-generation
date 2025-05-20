//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct node* next;
} node;

node* front = NULL;
node* rear = NULL;

void enqueue(int data) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    if (front == NULL && rear == NULL) {
        front = new_node;
        rear = new_node;
    } else if (rear == NULL) {
        rear = new_node;
        rear->next = front;
    } else {
        rear->next = new_node;
        rear = new_node;
    }

    printf("Enqueued element: %d\n", data);
}

void dequeue() {
    if (front == NULL && rear == NULL) {
        printf("Queue is empty\n");
        return;
    }

    node* temp = front;
    printf("Dequeued element: %d\n", temp->data);

    if (front == rear) {
        front = NULL;
        rear = NULL;
    } else {
        front = front->next;
        rear->next = front;
    }

    free(temp);
}

void display() {
    if (front == NULL && rear == NULL) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    node* temp = front;
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
    enqueue(50);

    display();

    dequeue();
    dequeue();

    display();

    return 0;
}