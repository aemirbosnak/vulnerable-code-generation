//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char item[20];
    int quantity;
    struct Node* next;
};

struct Queue {
    struct Node* head;
    struct Node* tail;
};

void enqueue(struct Queue* queue, char item, int quantity) {
    struct Node* newNode = malloc(sizeof(struct Node));
    strcpy(newNode->item, item);
    newNode->quantity = quantity;
    newNode->next = NULL;

    if (queue->head == NULL) {
        queue->head = newNode;
        queue->tail = newNode;
    } else {
        queue->tail->next = newNode;
        queue->tail = newNode;
    }
}

void dequeue(struct Queue* queue) {
    struct Node* oldHead = queue->head;

    if (queue->head == NULL) {
        return;
    }

    queue->head = oldHead->next;
    free(oldHead);
}

int main() {
    struct Queue* queue = malloc(sizeof(struct Queue));
    queue->head = NULL;
    queue->tail = NULL;

    enqueue(queue, "Apple", 10);
    enqueue(queue, "Banana", 5);
    enqueue(queue, "Orange", 7);

    dequeue(queue);
    dequeue(queue);

    printf("Items in the queue:");
    for (struct Node* node = queue->head; node; node = node->next) {
        printf(" %s", node->item);
    }

    return 0;
}