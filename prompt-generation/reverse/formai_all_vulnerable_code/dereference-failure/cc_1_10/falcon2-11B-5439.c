//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Structure to define a node in a queue
struct Node {
    int data;
    struct Node *next;
};

// Structure to define a queue
struct Queue {
    struct Node *front;
    struct Node *rear;
    int size;
};

// Function to initialize a queue
void initializeQueue(struct Queue *q) {
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

// Function to check if the queue is empty
int isEmptyQueue(struct Queue *q) {
    return (q->front == NULL && q->rear == NULL);
}

// Function to enqueue an element into the queue
void enqueue(struct Queue *q, int data) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmptyQueue(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
}

// Function to dequeue an element from the queue
int dequeue(struct Queue *q) {
    if (isEmptyQueue(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    int data = q->front->data;
    struct Node *temp = q->front;
    q->front = q->front->next;
    free(temp);
    q->size--;
    if (q->size == 0) {
        q->rear = NULL;
    }
    return data;
}

// Function to print the elements of the queue
void printQueue(struct Queue *q) {
    if (isEmptyQueue(q)) {
        printf("Queue is empty\n");
        return;
    }
    struct Node *temp = q->front;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to get the size of the queue
int getQueueSize(struct Queue *q) {
    return q->size;
}

// Function to check if the queue is full
int isQueueFull(struct Queue *q) {
    return (q->size == 10);
}

// Function to check if the queue is empty
int isQueueEmpty(struct Queue *q) {
    return (q->front == NULL && q->rear == NULL);
}

// Function to display the entire queue
void displayQueue(struct Queue *q) {
    printf("Queue elements are:\n");
    struct Node *temp = q->front;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Queue *q = (struct Queue*) malloc(sizeof(struct Queue));
    initializeQueue(q);

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    enqueue(q, 60);
    enqueue(q, 70);
    enqueue(q, 80);
    enqueue(q, 90);
    enqueue(q, 100);

    printf("Queue elements are:\n");
    displayQueue(q);

    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);

    printf("Queue elements are:\n");
    displayQueue(q);

    printf("Queue size: %d\n", getQueueSize(q));

    if (isQueueEmpty(q)) {
        printf("Queue is empty\n");
    } else if (isQueueFull(q)) {
        printf("Queue is full\n");
    } else {
        printf("Queue is not empty and not full\n");
    }

    return 0;
}