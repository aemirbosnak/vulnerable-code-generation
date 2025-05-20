//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *front = NULL, *rear = NULL;

void enqueue(int data) {
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = NULL;
    if (front == NULL) {
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
}

void dequeue() {
    if (front == NULL)
        printf("Queue is empty\n");
    else {
        Node *temp = front;
        front = front->next;
        printf("Deleted element is %d\n", temp->data);
        free(temp);
    }
}

void display() {
    if (front == NULL)
        printf("Queue is empty\n");
    else {
        Node *temp = front;
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
    display();
    dequeue();
    dequeue();
    display();
    return 0;
}