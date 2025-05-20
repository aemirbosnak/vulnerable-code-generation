//Gemma-7B DATASET v1.0 Category: Queue Implementation ; Style: ephemeral
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
    int size;
} Queue;

Queue* enqueue(Queue* queue, char data) {
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

    return queue;
}

char dequeue(Queue* queue) {
    if (queue->head == NULL) {
        return -1;
    }

    char data = queue->head->data;
    queue->head = queue->head->next;
    queue->size--;

    return data;
}

int main() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;

    enqueue(queue, 'a');
    enqueue(queue, 'b');
    enqueue(queue, 'c');

    char data = dequeue(queue);
    printf("%c\n", data);

    data = dequeue(queue);
    printf("%c\n", data);

    data = dequeue(queue);
    printf("%c\n", data);

    data = dequeue(queue);
    printf("%c\n", data);

    return 0;
}