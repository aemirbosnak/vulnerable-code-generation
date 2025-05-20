//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure definition
struct Node {
    int data;
    struct Node* next;
};

// Queue structure definition
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to create an empty queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    if(q == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// Function to check if the queue is empty
bool isEmpty(struct Queue* q) {
    if(q->front == NULL)
        return true;
    else
        return false;
}

// Function to add an element to the rear of the queue
void enqueue(struct Queue* q, int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if(temp == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    temp->data = data;
    temp->next = NULL;
    if(isEmpty(q)) {
        q->front = temp;
        q->rear = temp;
    }
    else {
        q->rear->next = temp;
        q->rear = temp;
    }
}

// Function to remove an element from the front of the queue
int dequeue(struct Queue* q) {
    int data = -1;
    if(isEmpty(q))
        return data;
    struct Node* temp = q->front;
    data = temp->data;
    q->front = q->front->next;
    free(temp);
    return data;
}

// Function to display the elements of the queue
void display(struct Queue* q) {
    struct Node* temp = q->front;
    if(isEmpty(q))
        printf("Queue is empty\n");
    else {
        printf("Elements of the queue are: ");
        while(temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    struct Queue* q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    display(q);
    int x = dequeue(q);
    printf("Dequeued element is: %d\n", x);
    display(q);
    return 0;
}