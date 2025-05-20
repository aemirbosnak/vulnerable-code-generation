//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* front = NULL;
Node* rear = NULL;

void enqueue(int value) {
    Node* temp = (Node*)malloc(sizeof(Node));

    if (temp == NULL) {
        printf("Queue is full!\n");
        exit(0);
    }

    temp->data = value;
    temp->next = NULL;

    if (front == NULL && rear == NULL) {
        front = temp;
        rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
}

void dequeue() {
    if (front == NULL) {
        printf("Queue is empty!\n");
        exit(0);
    }

    Node* temp = front;
    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
}

void display() {
    if (front == NULL) {
        printf("Queue is empty!\n");
        exit(0);
    }

    Node* temp = front;

    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    printf("Queue after enqueue:\n");
    display();

    dequeue();
    dequeue();

    printf("\nQueue after dequeue:\n");
    display();

    return 0;
}