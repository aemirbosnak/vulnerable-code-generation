//Gemma-7B DATASET v1.0 Category: Queue Implementation ; Style: retro
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
};

void enqueue(int data, struct Queue* queue) {
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

void dequeue(struct Queue* queue) {
    if (queue->head == NULL) {
        printf("Queue is empty\n");
        return;
    }

    Node* temp = queue->head;
    queue->head = queue->head->next;
    free(temp);

    queue->size--;
}

int peek(struct Queue* queue) {
    if (queue->head == NULL) {
        printf("Queue is empty\n");
        return -1;
    }

    return queue->head->data;
}

int main() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;

    enqueue(10, queue);
    enqueue(20, queue);
    enqueue(30, queue);
    enqueue(40, queue);
    enqueue(50, queue);

    printf("Front element: %d\n", peek(queue));

    dequeue(queue);
    printf("Front element after dequeue: %d\n", peek(queue));

    return 0;
}