//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void enqueue(Node** front, Node** rear, int data) {
    Node* newNode = createNode(data);
    if (*rear == NULL) {
        *front = newNode;
        *rear = newNode;
    } else {
        (*rear)->next = newNode;
        *rear = newNode;
    }
}

int dequeue(Node** front, Node** rear) {
    int data = (*front)->data;
    Node* temp = *front;
    *front = (*front)->next;
    free(temp);

    if (*front == NULL) {
        *rear = NULL;
    }

    return data;
}

bool isEmpty(Node* front) {
    return front == NULL;
}

void display(Node* front) {
    while (front!= NULL) {
        printf("%d ", front->data);
        front = front->next;
    }
    printf("\n");
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
    printf("Dequeued data: %d\n", dequeuedData);

    printf("Queue after dequeue:\n");
    display(front);

    return 0;
}