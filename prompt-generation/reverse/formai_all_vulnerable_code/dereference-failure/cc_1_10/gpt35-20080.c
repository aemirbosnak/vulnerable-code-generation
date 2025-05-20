//FormAI DATASET v1.0 Category: Queue Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Define queue node
struct queue_node {
    int data;
    struct queue_node* next;
};

// Define queue struct
struct queue {
    struct queue_node *front, *rear; 
};

// Create empty queue
struct queue* create_queue() {
    struct queue* q = (struct queue*) malloc(sizeof(struct queue)); 
    q->front = q->rear = NULL; 
    return q; 
}

// Check if queue is empty
int is_empty(struct queue* q) {
    return (q->front == NULL);
}

// Enqueue element to queue
void enqueue(struct queue* q, int item) {
    struct queue_node* new_node = (struct queue_node*) malloc(sizeof(struct queue_node));
    new_node->data = item;
    new_node->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = new_node;
        return;
    }

    q->rear->next = new_node;
    q->rear = new_node;
}

// Dequeue element from queue
int dequeue(struct queue* q) {
    if (is_empty(q))
        return -1;

    struct queue_node* temp = q->front;
    int item = temp->data;

    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return item;
}

// Print queue elements
void print_queue(struct queue* q) {
    if (is_empty(q)) {
        printf("Queue is empty\n");
        return;
    }

    struct queue_node* temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// entry point
int main() {
    struct queue* q = create_queue();

    // Enqueue elements
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);

    // Print queue
    print_queue(q);
    printf("\n");

    // Dequeue element
    printf("Dequeued element: %d\n", dequeue(q));

    // Print queue
    print_queue(q);
    printf("\n");

    return 0;
}