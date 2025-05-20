//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Node {
    char item_name[20];
    int quantity;
    struct Node* next;
};

struct Queue {
    struct Node* head;
    struct Node* tail;
};

void enqueue(struct Queue* queue, char item_name, int quantity) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->item_name, item_name);
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

int dequeue(struct Queue* queue) {
    if (queue->head == NULL) {
        return -1;
    }

    struct Node* oldHead = queue->head;
    queue->head = oldHead->next;
    free(oldHead);

    return 0;
}

int main() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->head = NULL;
    queue->tail = NULL;

    enqueue(queue, "Apple", 10);
    enqueue(queue, "Banana", 20);
    enqueue(queue, "Orange", 30);

    int quantity = dequeue(queue);
    if (quantity != -1) {
        printf("Dequed item: %s, quantity: %d\n", queue->head->item_name, quantity);
    }

    quantity = dequeue(queue);
    if (quantity != -1) {
        printf("Dequed item: %s, quantity: %d\n", queue->head->item_name, quantity);
    }

    quantity = dequeue(queue);
    if (quantity != -1) {
        printf("Dequed item: %s, quantity: %d\n", queue->head->item_name, quantity);
    }

    return 0;
}