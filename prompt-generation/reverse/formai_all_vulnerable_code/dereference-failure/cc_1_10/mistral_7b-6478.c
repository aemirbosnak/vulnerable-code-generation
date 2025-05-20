//MISTRAL-7B DATASET v1.0 Category: Queue Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 10
#define QUEUE_NAME "Queue of the Wise"
#define EMPTY "-1"

typedef struct QueueNode {
    int data;
    struct QueueNode *next;
} QueueNode;

QueueNode* createNode(int data) {
    QueueNode* newNode = (QueueNode*) malloc(sizeof(QueueNode));
    if (!newNode) {
        printf("Error: Out of memory\n");
        return NULL;
    }

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

QueueNode* enqueue(QueueNode* front, QueueNode* rear, int data) {
    QueueNode* newNode = createNode(data);
    if (!newNode) {
        return front;
    }

    if (rear == NULL) {
        rear = newNode;
    }

    if (front == NULL) {
        front = newNode;
    } else {
        rear->next = newNode;
    }

    return rear;
}

int dequeue(QueueNode** front, QueueNode** rear) {
    QueueNode* tempNode = *front;

    if (*front == NULL) {
        printf("Error: Queue is empty\n");
        return -1;
    }

    if (*front == *rear) {
        *front = *rear = NULL;
    } else {
        *front = (*front)->next;
    }

    int data = tempNode->data;
    free(tempNode);

    return data;
}

int size(QueueNode* front) {
    QueueNode* current = front;
    int size = 0;

    while (current != NULL) {
        size++;
        current = current->next;
    }

    return size;
}

void display(QueueNode* front) {
    printf("%s: [", QUEUE_NAME);

    if (front == NULL) {
        printf("Empty]");
        return;
    }

    QueueNode* current = front;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("]\n");
}

int main() {
    QueueNode* front = NULL;
    QueueNode* rear = NULL;

    printf("%s: Medieval Queue Implementation\n", QUEUE_NAME);

    enqueue(&front, &rear, 5);
    enqueue(&front, &rear, 12);
    enqueue(&front, &rear, 15);

    display(front);

    printf("Dequeued: %d\n", dequeue(&front, &rear));
    display(front);

    printf("Size: %d\n", size(front));

    return 0;
}