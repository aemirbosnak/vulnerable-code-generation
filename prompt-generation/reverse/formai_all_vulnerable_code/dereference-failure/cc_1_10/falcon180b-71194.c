//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

// Node structure for queue
typedef struct node {
    int data;
    struct node *next;
} Node;

// Queue structure
typedef struct {
    Node *front;
    Node *rear;
} Queue;

// Function to create an empty queue
Queue* createQueue() {
    Queue *q = (Queue*) malloc(sizeof(Queue));
    if (q == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    q->front = q->rear = NULL;
    return q;
}

// Function to check if the queue is empty
int isEmpty(Queue *q) {
    return (q->front == NULL);
}

// Function to enqueue an element
void enqueue(Queue *q, int data) {
    Node *newnode = (Node*) malloc(sizeof(Node));
    if (newnode == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    newnode->data = data;
    newnode->next = NULL;
    if (isEmpty(q)) {
        q->front = newnode;
        q->rear = newnode;
    } else {
        q->rear->next = newnode;
        q->rear = newnode;
    }
}

// Function to dequeue an element
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        exit(1);
    }
    Node *temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return data;
}

// Function to display the queue
void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    Node *temp = q->front;
    printf("Queue: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue *q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    display(q);
    int dequeued_data = dequeue(q);
    printf("Dequeued element: %d\n", dequeued_data);
    display(q);
    return 0;
}