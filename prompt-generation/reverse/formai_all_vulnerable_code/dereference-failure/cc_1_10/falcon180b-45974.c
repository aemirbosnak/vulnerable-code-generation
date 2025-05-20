//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct node* next;
} Node;

Node* front = NULL;
Node* rear = NULL;
int count = 0;

void enqueue(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Memory allocation failed.\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    if (rear == NULL) {
        front = newNode;
    } else {
        rear->next = newNode;
    }
    rear = newNode;
    count++;
}

int dequeue() {
    int value;
    Node* temp = front;
    if (front == NULL) {
        printf("Error: Queue is empty.\n");
        return -1;
    }
    value = front->data;
    front = front->next;
    free(temp);
    count--;
    return value;
}

int peek() {
    if (front == NULL) {
        printf("Error: Queue is empty.\n");
        return -1;
    }
    return front->data;
}

int isEmpty() {
    return (front == NULL);
}

int isFull() {
    return (count == MAX_SIZE);
}

void display() {
    Node* temp = front;
    printf("Queue: ");
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
    printf("Front element is: %d\n", peek());
    printf("Dequeued element is: %d\n", dequeue());
    display();
    printf("Is queue empty? %s\n", isEmpty()? "Yes" : "No");
    printf("Is queue full? %s\n", isFull()? "Yes" : "No");
    return 0;
}