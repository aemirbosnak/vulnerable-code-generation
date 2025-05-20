//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Node structure definition
typedef struct node {
    int data;
    struct node* next;
} Node;

// Queue structure definition
typedef struct {
    Node* front;
    Node* rear;
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
    if (q->front == NULL && q->rear == NULL) {
        return 1;
    } else {
        return 0;
    }
}

// Function to check if the queue is full
int isFull(Queue* q) {
    Node* temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL) {
        return 1;
    } else {
        free(temp);
        return 0;
    }
}

// Function to add an element to the rear of the queue
void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
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
    int value;
    Node* temp = q->front;

    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    } else {
        value = temp->data;
        q->front = temp->next;
        free(temp);
    }

    return value;
}

// Function to display the contents of the queue
void display(Queue* q) {
    Node* temp = q->front;

    if (isEmpty(q)) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are: ");
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    Queue* q = createQueue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);

    display(q);

    int value = dequeue(q);
    printf("Dequeued value is: %d\n", value);

    display(q);

    return 0;
}