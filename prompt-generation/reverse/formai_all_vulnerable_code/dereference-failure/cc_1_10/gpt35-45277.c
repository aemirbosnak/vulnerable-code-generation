//FormAI DATASET v1.0 Category: Queue Implementation ; Style: Ada Lovelace
#include<stdio.h>
#include<stdlib.h>

// Defining the structure for each element of the queue
struct queue_node {
    int data;
    struct queue_node *next;
};

// Defining the structure for the queue
struct queue {
    struct queue_node *front, *rear;
};

// Function to create a new node with given data
struct queue_node* new_node(int data) {
    struct queue_node *temp = (struct queue_node*)malloc(sizeof(struct queue_node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to create a new queue
struct queue* create_queue() {
    struct queue *q = (struct queue*)malloc(sizeof(struct queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to add an element to the queue
void enqueue(struct queue *q, int data) {
    struct queue_node *temp = new_node(data);

    if(q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

// Function to remove an element from the queue
int dequeue(struct queue *q) {
    if(q->front == NULL)
        return -1;

    struct queue_node *temp = q->front;
    q->front = q->front->next;

    if(q->front == NULL)
        q->rear = NULL;

    int data = temp->data;
    free(temp);
    return data;
}

// Function to print the queue
void print_queue(struct queue *q) {
    printf("Queue: ");
    struct queue_node *temp = q->front;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    // Creating a new queue
    struct queue *q = create_queue();

    // Adding elements to the queue
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);

    // Printing the queue
    print_queue(q);

    // Removing elements from the queue
    dequeue(q);
    dequeue(q);

    // Printing the queue after removal
    print_queue(q);

    return 0;
}