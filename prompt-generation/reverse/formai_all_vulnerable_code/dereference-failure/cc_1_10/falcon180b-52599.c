//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    struct node* next;
} node;

node* front = NULL;
node* rear = NULL;

void enqueue(int data) {
    node* new_node = (node*)malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    new_node->data = data;
    new_node->next = NULL;
    if (rear == NULL) {
        front = rear = new_node;
    } else {
        rear->next = new_node;
        rear = new_node;
    }
}

int dequeue() {
    if (front == NULL) {
        printf("Queue is empty\n");
        exit(0);
    }
    int data = front->data;
    node* temp = front;
    front = front->next;
    free(temp);
    if (front == NULL) {
        rear = NULL;
    }
    return data;
}

int peek() {
    if (front == NULL) {
        printf("Queue is empty\n");
        exit(0);
    }
    return front->data;
}

int is_empty() {
    return front == NULL;
}

void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are: ");
    node* temp = front;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    display();
    printf("Dequeued element: %d\n", dequeue());
    display();
    printf("Peek element: %d\n", peek());
    printf("Is queue empty? %s\n", is_empty()? "Yes" : "No");
    return 0;
}