//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 5

typedef struct _node {
    int data;
    struct _node *next;
} node;

node* head = NULL;

int isEmpty() {
    return head == NULL;
}

void enqueue(int data) {
    node* newNode = (node*) malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty()) {
        head = newNode;
    } else {
        node* current = head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return -1;
    }

    node* temp = head;
    int data = temp->data;
    head = temp->next;
    free(temp);

    return data;
}

void printQueue() {
    node* current = head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
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

    printf("Dequeued %d\n", dequeue());
    printQueue();

    printf("Dequeued %d\n", dequeue());
    printQueue();

    printf("Dequeued %d\n", dequeue());
    printQueue();

    printf("Dequeued %d\n", dequeue());
    printQueue();

    printf("Dequeued %d\n", dequeue());
    printQueue();

    printf("Dequeued %d\n", dequeue());
    printQueue();

    return 0;
}