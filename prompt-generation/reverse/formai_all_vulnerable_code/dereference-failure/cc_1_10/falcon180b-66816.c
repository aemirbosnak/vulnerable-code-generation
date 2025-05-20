//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

// Node structure definition
struct node {
    int data;
    struct node* next;
};

// Queue structure definition
struct queue {
    struct node* front;
    struct node* rear;
};

// Function to create an empty queue
struct queue* createQueue() {
    struct queue* q = (struct queue*) malloc(sizeof(struct queue));
    if (q == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// Function to check if the queue is empty
int isEmpty(struct queue* q) {
    if (q->front == NULL)
        return 1;
    else
        return 0;
}

// Function to enqueue an element
void enqueue(struct queue* q, int x) {
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    temp->data = x;
    temp->next = NULL;
    if (isEmpty(q)) {
        q->front = temp;
        q->rear = temp;
    }
    else {
        q->rear->next = temp;
        q->rear = temp;
    }
}

// Function to dequeue an element
int dequeue(struct queue* q) {
    int x;
    struct node* temp = q->front;
    if (isEmpty(q))
        printf("Queue is empty\n");
    else {
        x = temp->data;
        q->front = temp->next;
        free(temp);
        if (q->front == NULL)
            q->rear = NULL;
    }
    return x;
}

// Function to display the queue
void display(struct queue* q) {
    struct node* temp = q->front;
    if (isEmpty(q))
        printf("Queue is empty\n");
    else {
        printf("Queue: ");
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Driver program to test the above functions
int main() {
    struct queue* q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    display(q);
    int x = dequeue(q);
    printf("Dequeued element: %d\n", x);
    display(q);
    return 0;
}