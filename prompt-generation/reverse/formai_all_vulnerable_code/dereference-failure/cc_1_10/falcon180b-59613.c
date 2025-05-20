//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Node structure definition
typedef struct node {
    int data;
    struct node *next;
} Node;

// Queue structure definition
typedef struct {
    Node *front;
    Node *rear;
} Queue;

// Function to create an empty queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return (q->front == NULL);
}

// Function to add an element to the rear of the queue
void enqueue(Queue* q, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Function to remove an element from the front of the queue
int dequeue(Queue* q) {
    Node* temp = q->front;
    int data = temp->data;

    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }

    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);

    return data;
}

// Function to display the elements of the queue
void display(Queue* q) {
    Node* temp = q->front;

    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements are: ");

    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

// Main function
int main() {
    Queue* q = createQueue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    display(q);

    int data = dequeue(q);
    printf("Dequeued element is: %d\n", data);

    display(q);

    data = dequeue(q);
    printf("Dequeued element is: %d\n", data);

    display(q);

    data = dequeue(q);
    printf("Dequeued element is: %d\n", data);

    display(q);

    return 0;
}