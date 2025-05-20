//FormAI DATASET v1.0 Category: Queue Implementation ; Style: decentralized
// A decentralized implementation of Circular Queue in C

#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 50

// Define the node structure to hold the data and the next node
typedef struct q_node {
    int data;
    struct q_node* next;
} queue_node;

// Define the circular queue structure
typedef struct queue {
    queue_node* head;
    queue_node* tail;
    int size;
} queue;

// Initialize the circular queue
void create_queue(queue** q) {
    *q = (queue*) malloc(sizeof(queue));
    (*q)->head = (*q)->tail = NULL;
    (*q)->size = 0;
}

// Check if the queue is empty
int check_empty(queue* q) {
    return q->head == NULL;
}

// Check if the queue is full
int check_full(queue* q) {
    return q->size == MAX_SIZE;
}

// Add an element to the queue
void enqueue(queue** q, int data) {
    queue_node* new_node = (queue_node*) malloc(sizeof(queue_node));
    new_node->data = data;
    new_node->next = NULL;
    if (check_full(*q)) {
        printf("Queue is full\n");
        return;
    }
    else if (check_empty(*q)) {
        (*q)->head = (*q)->tail = new_node;
    }
    else {
        (*q)->tail->next = new_node;
        (*q)->tail = new_node;
    }
    (*q)->size++;
}

// Remove an element from the queue
void dequeue(queue** q) {
    if (check_empty(*q)) {
        printf("Queue is empty\n");
        return;
    }
    queue_node* temp_node = (*q)->head;
    (*q)->head = (*q)->head->next;
    printf("%d removed from the queue\n", temp_node->data);
    free(temp_node);
    (*q)->size--;
    if (check_empty(*q)) {
        (*q)->head = (*q)->tail = NULL;
    }
}

// Get the front element of the queue
void front(queue* q) {
    if (check_empty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Front element of queue is %d\n", q->head->data);
}

// Get the rear element of the queue
void rear(queue* q) {
    if (check_empty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Rear element of queue is %d\n", q->tail->data);
}

// Print the elements of the queue
void display(queue* q) {
    if (check_empty(q)) {
        printf("Queue is empty\n");
        return;
    }
    queue_node* current = q->head;
    printf("Elements of the queue are: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Main function for testing the circular queue implementation
int main() {
    queue* q;
    create_queue(&q);
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);
    enqueue(&q, 6);
    display(q);
    front(q);
    rear(q);
    dequeue(&q);
    display(q);
    dequeue(&q);
    dequeue(&q);
    display(q);
    front(q);
    rear(q);
    return 0;
}