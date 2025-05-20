//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// node structure for queue
struct node {
    int data;
    struct node* next;
};

// queue structure
struct queue {
    struct node* front;
    struct node* rear;
    int count;
};

// function to create an empty queue
void createQueue(struct queue* q) {
    q->front = NULL;
    q->rear = NULL;
    q->count = 0;
}

// function to check if the queue is empty
int isEmpty(struct queue* q) {
    if (q->front == NULL && q->rear == NULL)
        return 1;
    else
        return 0;
}

// function to check if the queue is full
int isFull(struct queue* q) {
    if (q->count == MAX_SIZE)
        return 1;
    else
        return 0;
}

// function to add an element to the rear of the queue
void enqueue(struct queue* q, int data) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = newNode;
        q->rear = newNode;
    }
    else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->count++;
}

// function to remove an element from the front of the queue
int dequeue(struct queue* q) {
    if (isEmpty(q))
        return -1;
    struct node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    free(temp);
    q->count--;
    return data;
}

// function to display the elements of the queue
void display(struct queue* q) {
    if (isEmpty(q))
        printf("Queue is empty\n");
    else {
        struct node* temp = q->front;
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// main function
int main() {
    struct queue q;
    createQueue(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    display(&q);
    dequeue(&q);
    dequeue(&q);
    display(&q);
    enqueue(&q, 40);
    display(&q);
    return 0;
}