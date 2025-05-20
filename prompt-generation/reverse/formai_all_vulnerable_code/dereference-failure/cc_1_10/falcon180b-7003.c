//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: relaxed
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
    node* new_node = (node*) malloc(sizeof(node));

    if (new_node == NULL) {
        printf("Queue is full!\n");
        return;
    }

    new_node->data = data;
    new_node->next = NULL;

    if (rear == NULL) {
        front = new_node;
        rear = new_node;
    } else {
        rear->next = new_node;
        rear = new_node;
    }

    printf("%d enqueued to the queue.\n", data);
}

void dequeue() {
    if (front == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    node* temp = front;
    int data = temp->data;

    printf("%d dequeued from the queue.\n", data);

    if (front == rear) {
        front = NULL;
        rear = NULL;
    } else {
        front = front->next;
    }

    free(temp);
}

void display() {
    node* temp = front;

    if (front == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Elements in the queue are: ");

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

    display();

    dequeue();
    dequeue();

    display();

    return 0;
}