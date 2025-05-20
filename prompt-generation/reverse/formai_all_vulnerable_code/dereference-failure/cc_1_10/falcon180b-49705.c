//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct node* next;
} Node;

Node* front = NULL;
Node* rear = NULL;

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
    printf("Element %d enqueued\n", data);
}

void dequeue() {
    if (front == NULL) {
        printf("Queue is empty\n");
    } else {
        Node* temp = front;
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        }
        printf("Element %d dequeued\n", temp->data);
        free(temp);
    }
}

void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
    } else {
        Node* temp = front;
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
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
    dequeue();
    enqueue(6);
    display();
    return 0;
}