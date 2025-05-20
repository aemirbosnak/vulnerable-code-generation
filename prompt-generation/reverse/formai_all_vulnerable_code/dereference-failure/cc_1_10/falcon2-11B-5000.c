//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>

struct QueueNode {
    int data;
    struct QueueNode* next;
};

typedef struct QueueNode QueueNode;

QueueNode* createQueueNode(int data) {
    QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
    node->data = data;
    node->next = NULL;
    return node;
}

QueueNode* enqueue(QueueNode* front, QueueNode* rear, int data) {
    QueueNode* newNode = createQueueNode(data);
    if (front == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    return front;
}

QueueNode* dequeue(QueueNode* front, QueueNode* rear) {
    if (front == rear) {
        front = rear = NULL;
    } else {
        QueueNode* temp = front;
        front = front->next;
        free(temp);
    }
    return front;
}

void printQueue(QueueNode* front) {
    QueueNode* temp = front;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    QueueNode* front = NULL;
    QueueNode* rear = NULL;
    enqueue(front, rear, 1);
    enqueue(front, rear, 2);
    enqueue(front, rear, 3);
    printQueue(front);
    printf("Dequeue: ");
    dequeue(front, rear);
    printQueue(front);
    printf("Dequeue: ");
    dequeue(front, rear);
    printf("Dequeue: ");
    dequeue(front, rear);
    return 0;
}