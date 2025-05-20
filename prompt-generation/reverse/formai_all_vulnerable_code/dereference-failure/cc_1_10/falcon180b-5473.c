//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *front = NULL;
Node *rear = NULL;

void enqueue(int data) {
    Node *temp = (Node *) malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;

    if (front == NULL && rear == NULL) {
        front = temp;
        rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }

    printf("%d enqueued to the queue\n", data);
}

void dequeue() {
    if (front == NULL && rear == NULL) {
        printf("Queue is empty\n");
    } else if (front == rear) {
        Node *temp = front;
        front = NULL;
        rear = NULL;
        free(temp);
        printf("%d dequeued from the queue\n", temp->data);
    } else {
        Node *temp = front;
        front = front->next;
        free(temp);
        printf("%d dequeued from the queue\n", temp->data);
    }
}

void display() {
    Node *temp = front;
    if (front == NULL && rear == NULL) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are: ");
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
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