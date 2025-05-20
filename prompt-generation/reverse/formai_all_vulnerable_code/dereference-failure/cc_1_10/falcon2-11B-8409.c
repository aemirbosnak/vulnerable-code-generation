//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;

void enqueue(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int dequeue() {
    if (head == NULL) {
        return -1;
    }
    Node* temp = head;
    int data = temp->data;
    head = temp->next;
    free(temp);
    return data;
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
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);

    printQueue();

    printf("Dequeued: %d\n", dequeue());
    printQueue();

    printf("Dequeued: %d\n", dequeue());
    printQueue();

    printf("Dequeued: %d\n", dequeue());
    printQueue();

    printf("Dequeued: %d\n", dequeue());
    printQueue();

    printf("Dequeued: %d\n", dequeue());

    return 0;
}