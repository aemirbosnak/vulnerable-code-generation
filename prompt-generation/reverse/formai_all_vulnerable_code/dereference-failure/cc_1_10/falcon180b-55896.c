//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void enqueue(Node** frontRef, int data) {
    Node* newNode = createNode(data);
    if (*frontRef == NULL) {
        *frontRef = newNode;
    } else {
        Node* last = *frontRef;
        while (last->next!= NULL) {
            last = last->next;
        }
        last->next = newNode;
    }
}

int dequeue(Node** frontRef) {
    if (*frontRef == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    Node* temp = *frontRef;
    int data = temp->data;
    *frontRef = temp->next;
    free(temp);
    return data;
}

void display(Node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    Node* front = NULL;
    Node* rear = NULL;

    enqueue(&front, 10);
    enqueue(&rear, 20);
    enqueue(&rear, 30);
    enqueue(&rear, 40);

    printf("Queue: ");
    display(front);

    int dequeuedData = dequeue(&front);
    printf("\nDequeued element: %d\n", dequeuedData);

    printf("Queue after dequeue: ");
    display(front);

    return 0;
}