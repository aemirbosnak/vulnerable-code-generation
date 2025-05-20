//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void enqueue(Node** frontRef, Node** rearRef, int data) {
    Node* newNode = createNode(data);
    if (*rearRef == NULL) {
        *frontRef = newNode;
        *rearRef = newNode;
    } else {
        (*rearRef)->next = newNode;
        *rearRef = newNode;
    }
}

int dequeue(Node** frontRef, Node** rearRef) {
    Node* temp = *frontRef;
    int data = temp->data;
    if (*frontRef == *rearRef) {
        *frontRef = NULL;
        *rearRef = NULL;
    } else {
        *frontRef = (*frontRef)->next;
    }
    free(temp);
    return data;
}

void display(Node* front) {
    while (front!= NULL) {
        printf("%d ", front->data);
        front = front->next;
    }
}

int main() {
    Node* front = NULL;
    Node* rear = NULL;

    enqueue(&front, &rear, 10);
    enqueue(&front, &rear, 20);
    enqueue(&front, &rear, 30);
    enqueue(&front, &rear, 40);

    printf("Queue after enqueue:\n");
    display(front);

    int dequeuedData = dequeue(&front, &rear);
    printf("\nDequeued data: %d\n", dequeuedData);

    printf("Queue after dequeue:\n");
    display(front);

    dequeuedData = dequeue(&front, &rear);
    printf("\nDequeued data: %d\n", dequeuedData);

    printf("Queue after dequeue:\n");
    display(front);

    dequeuedData = dequeue(&front, &rear);
    printf("\nDequeued data: %d\n", dequeuedData);

    printf("Queue after dequeue:\n");
    display(front);

    dequeuedData = dequeue(&front, &rear);
    printf("\nDequeued data: %d\n", dequeuedData);

    printf("Queue after dequeue:\n");
    display(front);

    return 0;
}