//Gemma-7B DATASET v1.0 Category: Queue Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define the Queue structure
typedef struct Queue {
    Node* head;
    Node* tail;
} Queue;

// Function to insert at the tail of the queue
void insert_tail(Queue* queue, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (queue->head == NULL) {
        queue->head = new_node;
        queue->tail = new_node;
    } else {
        queue->tail->next = new_node;
        queue->tail = new_node;
    }
}

// Function to delete from the front of the queue
void delete_front(Queue* queue) {
    if (queue->head == NULL) {
        return;
    }

    Node* temp = queue->head;
    queue->head = queue->head->next;
    free(temp);
}

// Function to traverse the queue
void traverse_queue(Queue* queue) {
    Node* current = queue->head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;

    insert_tail(queue, 10);
    insert_tail(queue, 20);
    insert_tail(queue, 30);
    insert_tail(queue, 40);
    insert_tail(queue, 50);

    traverse_queue(queue);

    delete_front(queue);
    delete_front(queue);

    traverse_queue(queue);

    return 0;
}