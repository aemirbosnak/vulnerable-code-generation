//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int value) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));

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
}

int dequeue() {
    int value;
    struct node *temp_node;

    if (front == NULL) {
        printf("Queue is empty\n");
        exit(0);
    }

    value = front->data;
    temp_node = front;
    front = front->next;

    free(temp_node);

    if (front == NULL) {
        rear = NULL;
    }

    return value;
}

void display() {
    struct node *temp_node;

    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements are: ");
    temp_node = front;

    while (temp_node!= NULL) {
        printf("%d ", temp_node->data);
        temp_node = temp_node->next;
    }

    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    display();

    printf("Deleted element is: %d\n", dequeue());

    display();

    printf("Deleted element is: %d\n", dequeue());

    display();

    printf("Deleted element is: %d\n", dequeue());

    display();

    printf("Deleted element is: %d\n", dequeue());

    return 0;
}