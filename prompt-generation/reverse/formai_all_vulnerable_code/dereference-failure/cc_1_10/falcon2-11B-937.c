//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* createQueue() {
    Node* front = NULL;
    Node* rear = NULL;
    return front;
}

void enqueue(Node** frontRef, int data) {
    Node* newNode = createNode(data);
    if (*frontRef == NULL) {
        *frontRef = newNode;
        *frontRef = newNode;
        return;
    }
    newNode->next = NULL;
    Node* temp = *frontRef;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

int dequeue(Node** frontRef) {
    if (*frontRef == NULL) {
        printf("Queue is empty.\n");
        return -1;
    }
    Node* temp = *frontRef;
    int data = temp->data;
    if (*frontRef == temp) {
        *frontRef = NULL;
    } else {
        Node* temp2 = *frontRef;
        while (temp2->next!= NULL) {
            temp2 = temp2->next;
        }
        temp2->next = NULL;
    }
    free(temp);
    return data;
}

int isEmpty(Node* front) {
    if (front == NULL) {
        return 1;
    }
    return 0;
}

int main() {
    Node* front = NULL;
    enqueue(&front, 10);
    enqueue(&front, 20);
    enqueue(&front, 30);
    printf("Queue: ");
    while (front!= NULL) {
        printf("%d ", front->data);
        front = front->next;
    }
    printf("\n");
    dequeue(&front);
    printf("Dequeued: %d\n", dequeue(&front));
    printf("Queue after dequeue: ");
    while (front!= NULL) {
        printf("%d ", front->data);
        front = front->next;
    }
    printf("\n");
    printf("Is Queue empty? %d\n", isEmpty(front));
    return 0;
}