//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure for a node
struct node {
    int data;
    struct node* next;
};

// Structure for a queue
struct queue {
    struct node* front;
    struct node* rear;
};

// Function to create an empty queue
void create_queue(struct queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

// Function to check if the queue is empty
int is_empty(struct queue* q) {
    return (q->front == NULL && q->rear == NULL);
}

// Function to check if the queue is full
int is_full(struct queue* q) {
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    if (temp == NULL) {
        return 1;
    } else {
        free(temp);
        return 0;
    }
}

// Function to enqueue an element
void enqueue(struct queue* q, int value) {
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Queue is full. Cannot enqueue %d\n", value);
        return;
    }
    temp->data = value;
    temp->next = NULL;
    if (is_empty(q)) {
        q->front = temp;
        q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
}

// Function to dequeue an element
int dequeue(struct queue* q) {
    if (is_empty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int value = q->front->data;
    struct node* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return value;
}

// Function to display the elements in the queue
void display(struct queue* q) {
    if (is_empty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Elements in the queue are: ");
    struct node* temp = q->front;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct queue q;
    create_queue(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    display(&q);
    int value = dequeue(&q);
    printf("Dequeued value: %d\n", value);
    display(&q);
    enqueue(&q, 40);
    display(&q);
    return 0;
}