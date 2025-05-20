//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head = NULL;
Node *tail = NULL;

void enqueue(int data) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

int dequeue() {
    if (head == NULL) {
        return -1;
    }
    
    int data = head->data;
    Node *temp = head;
    head = head->next;
    free(temp);
    
    if (head == NULL) {
        tail = NULL;
    }
    
    return data;
}

void printQueue() {
    Node *temp = head;
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
    
    printf("Queue: ");
    printQueue();
    
    printf("\nDequeue: ");
    printf("%d ", dequeue());
    printf("\nDequeue: ");
    printf("%d ", dequeue());
    printf("\nDequeue: ");
    printf("%d ", dequeue());
    
    printf("\nQueue: ");
    printQueue();
    
    return 0;
}