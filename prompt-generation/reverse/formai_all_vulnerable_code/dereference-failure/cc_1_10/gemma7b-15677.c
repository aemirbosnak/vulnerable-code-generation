//Gemma-7B DATASET v1.0 Category: Queue Implementation ; Style: protected
#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* head;
    Node* tail;
    int size;
} Queue;

Queue* queue_create() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
    return queue;
}

void queue_add(Queue* queue, int data) {
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

int queue_peek(Queue* queue) {
    if (queue->head == NULL) {
        return -1;
    } else {
        return queue->head->data;
    }
}

int queue_pop(Queue* queue) {
    if (queue->head == NULL) {
        return -1;
    } else {
        int data = queue->head->data;
        queue->head = queue->head->next;
        queue->size--;
        return data;
    }
}

void queue_print(Queue* queue) {
    Node* current = queue->head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Queue* queue = queue_create();
    queue_add(queue, 10);
    queue_add(queue, 20);
    queue_add(queue, 30);
    queue_add(queue, 40);
    queue_add(queue, 50);

    queue_print(queue);

    int popped_data = queue_pop(queue);
    printf("Popped data: %d\n", popped_data);

    queue_print(queue);

    popped_data = queue_pop(queue);
    printf("Popped data: %d\n", popped_data);

    queue_print(queue);

    return 0;
}