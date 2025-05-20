//Gemma-7B DATASET v1.0 Category: Queue Implementation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define the queue structure
typedef struct Queue {
    Node* head;
    Node* tail;
} Queue;

// Function to insert at the rear of the queue
void insertRear(Queue* queue, int data) {
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

// Function to delete from the front of the queue
void deleteFront(Queue* queue) {
    if (queue->head == NULL) {
        printf("Queue is empty\n");
        return;
    }

    Node* temp = queue->head;
    queue->head = queue->head->next;
    free(temp);
}

int main() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;

    insertRear(queue, 10);
    insertRear(queue, 20);
    insertRear(queue, 30);
    insertRear(queue, 40);
    insertRear(queue, 50);

    deleteFront(queue);
    deleteFront(queue);

    insertRear(queue, 60);
    insertRear(queue, 70);

    deleteFront(queue);
    deleteFront(queue);

    printf("Queue elements: ");
    for (Node* current = queue->head; current; current = current->next) {
        printf("%d ", current->data);
    }

    printf("\n");

    return 0;
}