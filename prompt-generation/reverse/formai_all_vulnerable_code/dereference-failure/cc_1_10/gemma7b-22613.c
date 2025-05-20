//Gemma-7B DATASET v1.0 Category: Queue Implementation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

// Define a Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define a Circular Queue structure
typedef struct CircularQueue {
    Node* head;
    Node* tail;
    int size;
    int capacity;
} CircularQueue;

// Function to insert at the tail of the circular queue
void insertTail(CircularQueue* queue, int data) {
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

// Function to remove from the head of the circular queue
int removeHead(CircularQueue* queue) {
    if (queue->head == NULL) {
        return -1;
    }

    int data = queue->head->data;
    queue->head = queue->head->next;

    queue->size--;

    return data;
}

// Main function
int main() {
    CircularQueue* queue = (CircularQueue*)malloc(sizeof(CircularQueue));
    queue->size = 0;
    queue->capacity = 5;
    queue->head = NULL;
    queue->tail = NULL;

    insertTail(queue, 10);
    insertTail(queue, 20);
    insertTail(queue, 30);

    printf("Data at the tail: %d\n", removeHead(queue));
    printf("Data at the tail: %d\n", removeHead(queue));
    printf("Data at the tail: %d\n", removeHead(queue));

    return 0;
}