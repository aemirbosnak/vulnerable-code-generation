//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node {
    int data;
    struct node *next;
} Node;

// Define the queue structure
typedef struct queue {
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

// Enqueue an element
void enqueue(Queue *queue, int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (queue->tail == NULL) {
        queue->head = new_node;
        queue->tail = new_node;
    } else {
        queue->tail->next = new_node;
        queue->tail = new_node;
    }

    queue->size++;
}

// Dequeue an element
int dequeue(Queue *queue) {
    if (is_empty(queue)) {
        return -1;
    }

    Node *temp = queue->head;
    int data = temp->data;

    queue->head = temp->next;
    if (queue->head == NULL) {
        queue->tail = NULL;
    }

    free(temp);
    queue->size--;

    return data;
}

// Peek at the front of the queue
int peek(Queue *queue) {
    if (is_empty(queue)) {
        return -1;
    }

    return queue->head->data;
}

// Print the queue
void print_queue(Queue *queue) {
    Node *temp = queue->head;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

// Destroy the queue
void destroy_queue(Queue *queue) {
    Node *temp;

    while (queue->head != NULL) {
        temp = queue->head;
        queue->head = temp->next;
        free(temp);
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
    enqueue(queue, 4);
    enqueue(queue, 5);

    // Print the queue
    printf("Queue: ");
    print_queue(queue);

    // Dequeue an element
    int data = dequeue(queue);

    // Print the dequeued element
    printf("Dequeued element: %d\n", data);

    // Peek at the front of the queue
    data = peek(queue);

    // Print the front element
    printf("Front element: %d\n", data);

    // Destroy the queue
    destroy_queue(queue);

    return 0;
}