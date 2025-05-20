//Gemma-7B DATASET v1.0 Category: Queue Implementation ; Style: mind-bending
#include <stdlib.h>
#include <stdio.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

struct Queue {
    Node* head;
    Node* tail;
};

typedef struct Queue Queue;

Queue* createQueue() {
    Queue* queue = malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}

void enqueue(Queue* queue, int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (queue->head == NULL) {
        queue->head = newNode;
        queue->tail = newNode;
    } else {
        queue->tail->next = newNode;
        queue->tail = newNode;
    }
}

int dequeue(Queue* queue) {
    if (queue->head == NULL) {
        return -1;
    }

    int data = queue->head->data;
    queue->head = queue->head->next;

    return data;
}

int main() {
    Queue* queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    int data = dequeue(queue);
    printf("%d", data);

    data = dequeue(queue);
    printf("%d", data);

    data = dequeue(queue);
    printf("%d", data);

    data = dequeue(queue);
    printf("%d", data);

    return 0;
}