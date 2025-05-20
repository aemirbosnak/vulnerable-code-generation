//Gemma-7B DATASET v1.0 Category: Queue Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

struct Queue {
    Node* head;
    Node* tail;
    int size;
};

void enqueue(struct Queue* queue, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (queue->head == NULL) {
        queue->head = newNode;
        queue->tail = newNode;
    } else {
        queue->tail->next = newNode;
        queue->tail = newNode;
    }

    queue->size++;
}

int dequeue(struct Queue* queue) {
    if (queue->head == NULL) {
        return -1;
    }

    int data = queue->head->data;
    queue->head = queue->head->next;
    queue->size--;

    return data;
}

void printQueue(struct Queue* queue) {
    Node* current = queue->head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

int main() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);

    printQueue(queue);

    int data = dequeue(queue);
    printQueue(queue);

    data = dequeue(queue);
    printQueue(queue);

    return 0;
}