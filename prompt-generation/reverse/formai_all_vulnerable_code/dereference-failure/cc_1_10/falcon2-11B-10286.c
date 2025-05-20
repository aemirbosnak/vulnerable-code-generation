//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: optimized
#include <stdio.h>

// Structure for a node in the queue
struct Node {
    int data;
    struct Node* next;
};

// Structure for the queue
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the queue
void initQueue(struct Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

// Function to enqueue a new element
void enqueue(struct Queue* q, int data) {
    struct Node* newNode = createNode(data);

    if (q->rear == NULL) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Function to dequeue an element
int dequeue(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }

    struct Node* temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return temp->data;
}

// Function to peek at the first element
int peek(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }

    return q->front->data;
}

// Function to print the queue
void printQueue(struct Queue* q) {
    struct Node* current = q->front;

    printf("Queue: ");
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    printQueue(&q);

    printf("Dequeue: %d\n", dequeue(&q));

    printQueue(&q);

    printf("Peek: %d\n", peek(&q));

    printQueue(&q);

    return 0;
}