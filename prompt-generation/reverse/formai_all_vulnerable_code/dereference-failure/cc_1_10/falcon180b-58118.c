//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
    int data;
    struct node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
} Queue;

// Function to create an empty queue
Queue *createQueue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to check if the queue is empty
bool isEmpty(Queue *q) {
    if (q->front == NULL && q->rear == NULL)
        return true;
    else
        return false;
}

// Function to check if the queue is full
bool isFull(Queue *q) {
    Node *temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL)
        return true;
    else {
        free(temp);
        return false;
    }
}

// Function to add an element to the queue
void enqueue(Queue *q, int data) {
    Node *temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL) {
        printf("Queue is full\n");
        return;
    }
    temp->data = data;
    temp->next = NULL;
    if (isEmpty(q)) {
        q->front = q->rear = temp;
    }
    else {
        q->rear->next = temp;
        q->rear = temp;
    }
}

// Function to remove an element from the queue
int dequeue(Queue *q) {
    int data;
    Node *temp = q->front;
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    data = temp->data;
    q->front = q->front->next;
    free(temp);
    return data;
}

// Function to display the elements of the queue
void display(Queue *q) {
    Node *temp = q->front;
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Elements in the queue are: ");
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
    display(q);
    int x = dequeue(q);
    printf("Dequeued element is: %d\n", x);
    display(q);
    return 0;
}