//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: creative
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
        printf("Queue is full\n");
        return;
    }

    new_node->data = data;
    new_node->next = NULL;

    if (front == NULL) {
        front = new_node;
        rear = new_node;
    } else {
        rear->next = new_node;
        rear = new_node;
    }
}

void dequeue() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    node* temp = front;
    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
}

void display() {
    node* current = front;

    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
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

    enqueue(50);
    enqueue(60);
    display();

    dequeue();
    dequeue();
    dequeue();
    display();

    return 0;
}