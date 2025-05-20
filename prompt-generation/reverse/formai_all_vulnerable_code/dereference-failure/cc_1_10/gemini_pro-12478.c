//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// Queue node structure
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Queue structure
typedef struct Queue {
    Node *head;
    Node *tail;
    int size;
} Queue;

// Create a new queue
Queue *create_queue() {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
    return queue;
}

// Check if the queue is empty
int is_empty(Queue *queue) {
    return queue->size == 0;
}

// Get the size of the queue
int get_size(Queue *queue) {
    return queue->size;
}

// Enqueue an element to the queue
void enqueue(Queue *queue, int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    if (is_empty(queue)) {
        queue->head = new_node;
        queue->tail = new_node;
    } else {
        queue->tail->next = new_node;
        queue->tail = new_node;
    }
    queue->size++;
}

// Dequeue an element from the queue
int dequeue(Queue *queue) {
    if (is_empty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    int data = queue->head->data;
    Node *temp = queue->head;
    queue->head = queue->head->next;
    free(temp);
    queue->size--;
    return data;
}

// Print the queue
void print_queue(Queue *queue) {
    if (is_empty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    Node *current = queue->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Destroy the queue
void destroy_queue(Queue *queue) {
    while (!is_empty(queue)) {
        dequeue(queue);
    }
    free(queue);
}

int main() {
    // Create a new queue
    Queue *queue = create_queue();

    // Enqueue some elements
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);

    // Print the queue
    printf("The queue: ");
    print_queue(queue);

    // Dequeue an element
    int data = dequeue(queue);
    printf("Dequeued: %d\n", data);

    // Print the queue again
    printf("The queue after dequeue: ");
    print_queue(queue);

    // Destroy the queue
    destroy_queue(queue);

    return 0;
}