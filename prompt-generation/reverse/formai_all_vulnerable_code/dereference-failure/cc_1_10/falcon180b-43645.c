//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *front = NULL;
Node *rear = NULL;

void enqueue(int value) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;
    if (rear == NULL) {
        front = new_node;
        rear = new_node;
    } else {
        rear->next = new_node;
        rear = new_node;
    }
}

int dequeue() {
    int value = -1;
    if (front == NULL) {
        printf("Queue is empty\n");
    } else {
        Node *temp = front;
        value = front->data;
        front = front->next;
        free(temp);
    }
    return value;
}

void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
    } else {
        Node *temp = front;
        printf("Queue: ");
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

    int value = dequeue();
    printf("Dequeued value: %d\n", value);

    display();

    enqueue(50);

    display();

    return 0;
}