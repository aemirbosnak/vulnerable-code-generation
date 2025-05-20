//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list implementation of queue
struct Node {
    int data;
    struct Node* next;
};

// Queue structure using linked list implementation
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to create an empty queue
void createQueue(struct Queue* q) {
    q->front = q->rear = NULL;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* q) {
    if (q->front == NULL)
        return 1;
    else
        return 0;
}

// Function to add an element to the rear of the queue
void enqueue(struct Queue* q, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    if (isEmpty(q)) {
        q->front = q->rear = new_node;
    }
    else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

// Function to remove an element from the front of the queue
int dequeue(struct Queue* q) {
    int data;
    struct Node* temp = q->front;

    if (isEmpty(q))
        return -1;

    data = q->front->data;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);

    return data;
}

// Function to display the contents of the queue
void display(struct Queue* q) {
    struct Node* temp = q->front;

    if (isEmpty(q))
        printf("Queue is empty\n");
    else {
        printf("Queue elements are: ");
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Main function to demonstrate the usage of queue operations
int main() {
    struct Queue q;
    createQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    display(&q);

    int dequeued_element = dequeue(&q);
    printf("Dequeued element: %d\n", dequeued_element);

    display(&q);

    return 0;
}