//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// Create a node for the queue
typedef struct node {
    int data;
    struct node *next;
} node;

// Create a queue
typedef struct queue {
    node *front;
    node *rear;
} queue;

// Create a new queue
queue *create_queue() {
    queue *q = malloc(sizeof(queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// Check if the queue is empty
int is_empty(queue *q) {
    return q->front == NULL;
}

// Enqueue an element into the queue
void enqueue(queue *q, int data) {
    node *new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    if (q->rear == NULL) {
        q->front = new_node;
        q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

// Dequeue an element from the queue
int dequeue(queue *q) {
    if (is_empty(q)) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        node *temp = q->front;
        int data = temp->data;
        q->front = q->front->next;
        if (q->front == NULL) {
            q->rear = NULL;
        }
        free(temp);
        return data;
    }
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

// Destroy the queue
void destroy_queue(queue *q) {
    node *temp;
    while (q->front != NULL) {
        temp = q->front;
        q->front = q->front->next;
        free(temp);
    }
    free(q);
}

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
    printf("The queue is: ");
    print_queue(q);

    // Dequeue some elements from the queue
    int data = dequeue(q);
    printf("Dequeued element: %d\n", data);
    data = dequeue(q);
    printf("Dequeued element: %d\n", data);

    // Print the queue
    printf("The queue is: ");
    print_queue(q);

    // Destroy the queue
    destroy_queue(q);

    return 0;
}