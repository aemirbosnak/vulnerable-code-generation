//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    int priority;
    struct node *next;
} Node;

Node *front = NULL;
Node *rear = NULL;

void enqueue(int data, int priority) {
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->data = data;
    newnode->priority = priority;
    newnode->next = NULL;

    if (rear == NULL) {
        front = newnode;
        rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
}

void dequeue() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    Node *temp = front;
    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
}

void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    Node *temp = front;
    printf("Queue elements are: ");

    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main() {
    enqueue(10, 3);
    enqueue(20, 2);
    enqueue(30, 1);
    enqueue(40, 1);

    printf("Queue elements after enqueue: ");
    display();

    dequeue();

    printf("Queue elements after dequeue: ");
    display();

    dequeue();

    printf("Queue elements after dequeue: ");
    display();

    dequeue();

    printf("Queue elements after dequeue: ");
    display();

    dequeue();

    printf("Queue elements after dequeue: ");
    display();

    return 0;
}