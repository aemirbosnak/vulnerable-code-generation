//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// node structure definition
struct node {
    int data;
    struct node* next;
};

struct node* front = NULL;
struct node* rear = NULL;
int count = 0;

void enqueue(int value) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));

    if (new_node == NULL) {
        printf("Memory error\n");
        exit(0);
    }

    new_node->data = value;
    new_node->next = NULL;

    if (front == NULL) {
        front = new_node;
        rear = new_node;
    } else {
        rear->next = new_node;
        rear = new_node;
    }

    count++;
}

void dequeue() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct node* temp = front;
    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
    count--;
}

void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct node* temp = front;

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