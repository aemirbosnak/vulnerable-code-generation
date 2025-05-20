//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

Node* head = NULL;
Node* tail = NULL;

void enqueue(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void dequeue() {
    if (head == NULL) {
        printf("Queue is empty\n");
        return;
    }
    Node* temp = head;
    head = head->next;
    if (head == NULL) {
        tail = NULL;
    }
    free(temp);
}

void printQueue() {
    Node* temp = head;
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
    dequeue();
    dequeue();
    dequeue();
    printQueue();
    return 0;
}