//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// A node in the queue
typedef struct node {
    int data;
    struct node *next;
} Node;

// The queue itself
typedef struct queue {
    Node *head;
    Node *tail;
    int size;
} Queue;

// Create a new queue
Queue *create_queue() {
    Queue *queue = malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
    return queue;
}

// Add an element to the queue
void enqueue(Queue *queue, int data) {
    Node *new_node = malloc(sizeof(Node));
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

// Remove an element from the queue
int dequeue(Queue *queue) {
    if (queue->head == NULL) {
        return -1; // Queue is empty
    }

    int data = queue->head->data;
    Node *old_head = queue->head;
    queue->head = queue->head->next;

    if (queue->head == NULL) {
        queue->tail = NULL;
    }
    free(old_head);
    queue->size--;
    return data;
}

// Get the size of the queue
int size(Queue *queue) {
    return queue->size;
}

// Check if the queue is empty
int is_empty(Queue *queue) {
    return queue->head == NULL;
}

// Print the queue
void print_queue(Queue *queue) {
    Node *curr = queue->head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

// A test function
int main() {
    Queue *queue = create_queue();

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    print_queue(queue); // 1 2 3 4 5

    dequeue(queue); // 1
    dequeue(queue); // 2

    print_queue(queue); // 3 4 5

    enqueue(queue, 6);
    enqueue(queue, 7);

    print_queue(queue); // 3 4 5 6 7

    printf("Size of the queue: %d\n", size(queue)); // 5

    printf("Is the queue empty? %d\n", is_empty(queue)); // 0

    dequeue(queue); // 3
    dequeue(queue); // 4
    dequeue(queue); // 5

    print_queue(queue); // 6 7

    dequeue(queue); // 6
    dequeue(queue); // 7

    printf("Is the queue empty? %d\n", is_empty(queue)); // 1

    return 0;
}