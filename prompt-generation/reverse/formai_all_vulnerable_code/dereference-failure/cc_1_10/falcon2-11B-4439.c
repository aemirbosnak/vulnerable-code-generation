//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the queue
#define MAX_SIZE 10

// Define the structure for the queue node
typedef struct {
    int data;
    struct queue *next;
} queue_node;

// Define the structure for the queue
typedef struct {
    queue_node *front;
    queue_node *rear;
    int size;
} queue;

// Function to initialize the queue
void init_queue(queue *q) {
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

// Function to enqueue a new element to the queue
void enqueue(queue *q, int data) {
    // Allocate memory for a new node
    queue_node *new_node = (queue_node*)malloc(sizeof(queue_node));
    
    // Check if the queue is full
    if (q->size == MAX_SIZE) {
        printf("Queue is full\n");
        return;
    }
    
    // Set the data and next pointer of the new node
    new_node->data = data;
    new_node->next = NULL;
    
    // Check if the queue is empty
    if (q->size == 0) {
        q->front = new_node;
        q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
    
    // Increment the size of the queue
    q->size++;
}

// Function to dequeue an element from the queue
int dequeue(queue *q) {
    // Check if the queue is empty
    if (q->size == 0) {
        printf("Queue is empty\n");
        return -1;
    }
    
    // Set the front pointer to the rear pointer
    queue_node *temp = q->front;
    q->front = q->rear;
    q->rear = temp;
    
    // Decrement the size of the queue
    q->size--;
    
    // Free the memory allocated for the dequeued element
    free(temp);
    
    return temp->data;
}

// Function to print the elements in the queue
void print_queue(queue *q) {
    queue_node *ptr = q->front;
    
    while (ptr!= NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    
    printf("\n");
}

// Function to check if the queue is empty
int is_empty(queue *q) {
    return q->size == 0;
}

// Function to check if the queue is full
int is_full(queue *q) {
    return q->size == MAX_SIZE;
}

int main() {
    queue q;
    
    // Initialize the queue
    init_queue(&q);
    
    // Enqueue some elements to the queue
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);
    enqueue(&q, 6);
    enqueue(&q, 7);
    enqueue(&q, 8);
    enqueue(&q, 9);
    enqueue(&q, 10);
    
    // Print the elements in the queue
    print_queue(&q);
    
    // Dequeue an element from the queue
    int element = dequeue(&q);
    printf("Dequeued element: %d\n", element);
    
    // Print the elements in the queue after dequeuing
    print_queue(&q);
    
    // Check if the queue is empty
    if (is_empty(&q)) {
        printf("Queue is empty\n");
    }
    
    // Check if the queue is full
    if (is_full(&q)) {
        printf("Queue is full\n");
    }
    
    return 0;
}