//Gemma-7B DATASET v1.0 Category: Queue Implementation ; Style: Cyberpunk
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
        return '\0';
    }

    char data = queue->head->data;
    queue->head = queue->head->next;

    return data;
}

int main() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;

    enqueue(queue, 'a');
    enqueue(queue, 'b');
    enqueue(queue, 'c');
    enqueue(queue, 'd');

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