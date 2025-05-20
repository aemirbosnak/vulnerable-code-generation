//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// Defining the structure of a node in the queue
struct node {
    int data;
    struct node *next;
};

// Defining the structure of the queue
struct queue {
    struct node *front;
    struct node *rear;
};

// Function to create a new queue
struct queue *createQueue() {
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// Function to enqueue an element into the queue
void enqueue(struct queue *q, int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Function to dequeue an element from the queue
int dequeue(struct queue *q) {
    if (q->front == NULL) {
        printf("Queue is empty.\n");
        return -1;
    }

    struct node *temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    int data = temp->data;
    free(temp);
    return data;
}

// Function to display the elements of the queue
void displayQueue(struct queue *q) {
    if (q->front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    struct node *temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    // Creating a new queue
    struct queue *q = createQueue();

    // Enqueuing elements into the queue
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);

    // Displaying the elements of the queue
    printf("Queue: ");
    displayQueue(q);

    // Dequeuing elements from the queue
    int data = dequeue(q);
    printf("Dequeued element: %d\n", data);

    data = dequeue(q);
    printf("Dequeued element: %d\n", data);

    // Displaying the elements of the queue
    printf("Queue: ");
    displayQueue(q);

    // Freeing the memory allocated to the queue
    while (q->front != NULL) {
        struct node *temp = q->front;
        q->front = q->front->next;
        free(temp);
    }

    free(q);

    return 0;
}