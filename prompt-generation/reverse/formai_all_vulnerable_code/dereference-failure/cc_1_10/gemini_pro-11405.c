//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

// A queue is a first-in, first-out data structure.
// It is implemented using a linked list.

// A node in the queue.
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// The queue itself.
typedef struct Queue {
    Node *head; // The first node in the queue.
    Node *tail; // The last node in the queue.
} Queue;

// Create a new queue.
Queue *createQueue() {
    Queue *queue = malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}

// Enqueue an item into the queue.
void enqueue(Queue *queue, int item) {
    Node *new_node = malloc(sizeof(Node));
    new_node->data = item;
    new_node->next = NULL;
    if (queue->head == NULL) {
        queue->head = new_node;
        queue->tail = new_node;
    } else {
        queue->tail->next = new_node;
        queue->tail = new_node;
    }
}

// Dequeue an item from the queue.
int dequeue(Queue *queue) {
    if (queue->head == NULL) {
        return -1; // Queue is empty.
    } else {
        int item = queue->head->data;
        Node *new_head = queue->head->next;
        free(queue->head);
        queue->head = new_head;
        if (queue->head == NULL) {
            queue->tail = NULL;
        }
        return item;
    }
}

// Print the queue.
void printQueue(Queue *queue) {
    Node *current = queue->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Destroy the queue.
void destroyQueue(Queue *queue) {
    while (queue->head != NULL) {
        Node *current = queue->head;
        queue->head = queue->head->next;
        free(current);
    }
    free(queue);
}

int main() {
    // Create a new queue.
    Queue *queue = createQueue();

    // Enqueue some items into the queue.
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    // Print the queue.
    printQueue(queue);

    // Dequeue some items from the queue.
    int item1 = dequeue(queue);
    int item2 = dequeue(queue);
    int item3 = dequeue(queue);

    // Print the queue again.
    printQueue(queue);

    // Destroy the queue.
    destroyQueue(queue);

    return 0;
}