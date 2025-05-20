//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *front, *rear;

void init() {
    front = NULL;
    rear = NULL;
}

void enqueue(int data) {
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    if (rear == NULL) {
        front = temp;
        rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
}

void dequeue() {
    if (front == NULL) {
        printf("\nQueue is empty");
    } else {
        Node *temp = front;
        front = front->next;
        printf("\nDeleted element is %d", temp->data);
        free(temp);
    }
}

void display() {
    if (front == NULL) {
        printf("\nQueue is empty");
    } else {
        printf("\nElements in the queue are: ");
        Node *temp = front;
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

int main() {
    init();
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