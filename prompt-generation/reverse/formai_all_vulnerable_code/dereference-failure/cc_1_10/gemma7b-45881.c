//Gemma-7B DATASET v1.0 Category: Queue Implementation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

// Define a Node structure
struct Node {
    int data;
    struct Node* next;
};

// Define a Circular Queue structure
struct CircularQueue {
    struct Node* head;
    struct Node* tail;
    int size;
    int capacity;
};

// Function to insert at the rear of the circular queue
void insertRear(struct CircularQueue* queue, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = queue->head;

    if (queue->head == NULL) {
        queue->head = newNode;
        queue->tail = newNode;
    } else {
        queue->tail->next = newNode;
        queue->tail = newNode;
    }
}

// Function to delete from the front of the circular queue
void deleteFront(struct CircularQueue* queue) {
    if (queue->head == NULL) {
        return;
    }

    struct Node* temp = queue->head;
    queue->head = queue->head->next;

    free(temp);
}

// Function to traverse the circular queue
void traverse(struct CircularQueue* queue) {
    struct Node* current = queue->head;

    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

int main() {
    struct CircularQueue* queue = (struct CircularQueue*)malloc(sizeof(struct CircularQueue));
    queue->size = 5;
    queue->capacity = 5;
    queue->head = NULL;
    queue->tail = NULL;

    insertRear(queue, 10);
    insertRear(queue, 20);
    insertRear(queue, 30);
    insertRear(queue, 40);
    insertRear(queue, 50);

    traverse(queue);

    deleteFront(queue);
    deleteFront(queue);

    traverse(queue);

    return 0;
}