//Gemma-7B DATASET v1.0 Category: Queue Implementation ; Style: rigorous
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

void enqueue(struct Queue* queue, int data) {
    if (queue->size == queue->capacity) {
        return;
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
}

int dequeue(struct Queue* queue) {
    if (queue->size == 0) {
        return -1;
    }

    int data = queue->head->data;
    free(queue->head);
    queue->head = queue->head->next;
    queue->size--;

    return data;
}

int main() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
    queue->capacity = MAX_SIZE;

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);

    printf("Enqueued data: ");
    for (Node* node = queue->head; node; node = node->next) {
        printf("%d ", node->data);
    }

    printf("\n");

    printf("Dequeued data: ");
    for (int i = 0; i < 3; i++) {
        int data = dequeue(queue);
        if (data != -1) {
            printf("%d ", data);
        }
    }

    printf("\n");

    printf("Enqueued data after dequeue: ");
    for (Node* node = queue->head; node; node = node->next) {
        printf("%d ", node->data);
    }

    free(queue);

    return 0;
}