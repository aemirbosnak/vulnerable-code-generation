//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node {
    int data;
    struct node *next;
} node;

// Define the queue structure
typedef struct queue {
    node *front;
    node *rear;
    int size;
} queue;

// Create a new queue
queue *create_queue() {
    queue *q = (queue *)malloc(sizeof(queue));
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

// Check if the queue is empty
int is_empty(queue *q) {
    return q->size == 0;
}

// Enqueue an element into the queue
void enqueue(queue *q, int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    if (is_empty(q)) {
        q->front = new_node;
        q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }

    q->size++;
}

// Dequeue an element from the queue
int dequeue(queue *q) {
    if (is_empty(q)) {
        printf("Error: Queue is empty\n");
        exit(1);
    }

    node *temp = q->front;
    int data = temp->data;

    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    q->size--;

    return data;
}

// Get the size of the queue
int get_size(queue *q) {
    return q->size;
}

// Print the queue
void print_queue(queue *q) {
    node *temp = q->front;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

// Driver code
int main() {
    // Create a queue
    queue *q = create_queue();

    // Enqueue some elements into the queue
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);

    // Print the queue
    printf("Queue: ");
    print_queue(q);

    // Dequeue some elements from the queue
    int dequeued_element = dequeue(q);
    printf("Dequeued element: %d\n", dequeued_element);
    dequeued_element = dequeue(q);
    printf("Dequeued element: %d\n", dequeued_element);

    // Print the queue
    printf("Queue: ");
    print_queue(q);

    // Check if the queue is empty
    if (is_empty(q)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue is not empty\n");
    }

    // Get the size of the queue
    int size = get_size(q);
    printf("Size of the queue: %d\n", size);

    return 0;
}