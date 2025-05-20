//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node structure definition
struct node {
    int data;
    struct node* next;
};

// Queue structure definition
struct Queue {
    struct node* front;
    struct node* rear;
};

// Function to create an empty queue
struct Queue* createQueue(void) {
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    if (queue->front == NULL)
        return 1;
    else
        return 0;
}

// Function to add an element to the rear of the queue
void enqueue(struct Queue* queue, int value) {
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    temp->data = value;
    temp->next = NULL;

    if (isEmpty(queue)) {
        queue->front = temp;
        queue->rear = temp;
    }
    else {
        queue->rear->next = temp;
        queue->rear = temp;
    }
}

// Function to remove an element from the front of the queue
int dequeue(struct Queue* queue) {
    int value;
    struct node* temp = queue->front;

    if (isEmpty(queue))
        return -1;

    value = temp->data;
    queue->front = temp->next;

    if (queue->front == NULL)
        queue->rear = NULL;

    free(temp);
    return value;
}

// Function to display the elements in the queue
void display(struct Queue* queue) {
    struct node* temp = queue->front;

    if (isEmpty(queue))
        printf("Queue is empty\n");
    else {
        printf("Elements in the queue are: ");
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Main function
int main() {
    struct Queue* queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    display(queue);

    int value = dequeue(queue);
    printf("Dequeued value is: %d\n", value);

    display(queue);

    return 0;
}