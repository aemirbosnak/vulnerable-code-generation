//Gemma-7B DATASET v1.0 Category: Queue Implementation ; Style: accurate
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
    int capacity;
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
    if (queue->size >= queue->capacity) {
        printf("Queue Overflow!\n");
    }
}

int dequeue(struct Queue* queue) {
    if (queue->size == 0) {
        printf("Queue Underflow!\n");
        return -1;
    }

    int data = queue->head->data;
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

    printf("Elements in the queue:");
    for (Node* node = queue->head; node; node = node->next) {
        printf(" %d ", node->data);
    }

    printf("\n");

    int data = dequeue(queue);
    if (data != -1) {
        printf("Dequed element: %d\n", data);
    }

    data = dequeue(queue);
    if (data != -1) {
        printf("Dequed element: %d\n", data);
    }

    data = dequeue(queue);
    if (data != -1) {
        printf("Dequed element: %d\n", data);
    }

    printf("\n");

    printf("Elements in the queue:");
    for (Node* node = queue->head; node; node = node->next) {
        printf(" %d ", node->data);
    }

    return 0;
}