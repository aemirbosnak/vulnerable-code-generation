//Gemma-7B DATASET v1.0 Category: Queue Implementation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* head;
    Node* tail;
} Queue;

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}

void enqueue(Queue* queue, char data) {
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
}

char dequeue(Queue* queue) {
    if (queue->head == NULL) {
        return -1;
    }

    char data = queue->head->data;
    queue->head = queue->head->next;

    return data;
}

int main() {
    Queue* queue = createQueue();

    enqueue(queue, 'a');
    enqueue(queue, 'b');
    enqueue(queue, 'c');
    enqueue(queue, 'd');

    char data = dequeue(queue);

    if (data != -1) {
        printf("%c", data);
    } else {
        printf("Queue is empty");
    }

    return 0;
}