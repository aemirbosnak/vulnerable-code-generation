//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct node {
    int data;
    struct node* next;
} node;

node* front = NULL;
node* rear = NULL;

void enqueue(int value) {
    node* newNode = (node*) malloc(sizeof(node));
    newNode->data = value;
    newNode->next = NULL;

    if (front == NULL) {
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue() {
    node* temp = front;
    front = front->next;
    free(temp);

    if (front == NULL) {
        rear = NULL;
    }
}

void display() {
    node* temp = front;
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

    dequeue();
    dequeue();

    display();

    return 0;
}