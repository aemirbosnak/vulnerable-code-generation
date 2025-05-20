//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// A node in a queue
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// A queue
typedef struct Queue {
    Node *head;
    Node *tail;
    int size;
} Queue;

// Create a new queue
Queue *createQueue() {
    Queue *queue = malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
    return queue;
}

// Add an element to the end of the queue
void enqueue(Queue *queue, int data) {
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (queue->head == NULL) {
        queue->head = new_node;
        queue->tail = new_node;
    } else {
        queue->tail->next = new_node;
        queue->tail = new_node;
    }
    queue->size++;
}

// Remove the element at the front of the queue
int dequeue(Queue *queue) {
    if (queue->head == NULL) {
        return -1;
    }

    int data = queue->head->data;
    Node *old_head = queue->head;
    queue->head = queue->head->next;
    free(old_head);
    queue->size--;
    return data;
}

// Get the element at the front of the queue without removing it
int peek(Queue *queue) {
    if (queue->head == NULL) {
        return -1;
    }

    return queue->head->data;
}

// Check if the queue is empty
int isEmpty(Queue *queue) {
    return queue->size == 0;
}

// Get the size of the queue
int size(Queue *queue) {
    return queue->size;
}

// Print the queue
void printQueue(Queue *queue) {
    Node *current = queue->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Queue *queue = createQueue();

    // Enqueue some elements
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);

    // Print the queue
    printQueue(queue);

    // Dequeue an element
    dequeue(queue);

    // Print the queue again
    printQueue(queue);

    // Check if the queue is empty
    printf("Is the queue empty? %d\n", isEmpty(queue));

    // Get the size of the queue
    printf("The size of the queue is %d\n", size(queue));

    return 0;
}