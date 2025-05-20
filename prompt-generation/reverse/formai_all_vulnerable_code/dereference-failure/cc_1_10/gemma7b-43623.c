//Gemma-7B DATASET v1.0 Category: Queue Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct Node {
    int data;
    struct Node* next;
} Node;

struct Queue {
    Node* head;
    Node* tail;
    int size;
    int capacity;
};

void initializeQueue(struct Queue* queue) {
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
    queue->capacity = MAX_SIZE;
}

int enqueue(struct Queue* queue, int data) {
    if (queue->size == queue->capacity) {
        return -1;
    }

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

    return 0;
}

int dequeue(struct Queue* queue) {
    if (queue->size == 0) {
        return -1;
    }

    int data = queue->head->data;

    Node* oldHead = queue->head;
    queue->head = queue->head->next;

    free(oldHead);

    queue->size--;

    return data;
}

int main() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    initializeQueue(queue);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);

    printf("Elements of the queue:");
    for (struct Node* node = queue->head; node; node = node->next) {
        printf(" %d ", node->data);
    }

    printf("\n");

    printf("Dequed elements:");
    for (int i = 0; i < 3; i++) {
        int data = dequeue(queue);
        printf(" %d ", data);
    }

    printf("\n");

    printf("Elements of the queue after dequeue:");
    for (struct Node* node = queue->head; node; node = node->next) {
        printf(" %d ", node->data);
    }

    free(queue);

    return 0;
}