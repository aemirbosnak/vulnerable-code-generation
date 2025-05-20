//Gemma-7B DATASET v1.0 Category: Queue Implementation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* head;
    Node* tail;
} Queue;

void enqueue(Queue* queue, char data) {
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

char dequeue(Queue* queue) {
    if (queue->head == NULL) {
        return -1;
    }

    Node* oldHead = queue->head;
    queue->head = queue->head->next;
    free(oldHead);

    return queue->head->data;
}

int main() {
    Queue* queue = malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;

    enqueue(queue, 'a');
    enqueue(queue, 'b');
    enqueue(queue, 'c');

    char data = dequeue(queue);
    printf("%c", data);

    data = dequeue(queue);
    printf("%c", data);

    data = dequeue(queue);
    printf("%c", data);

    data = dequeue(queue);
    printf("%c", data);

    return 0;
}