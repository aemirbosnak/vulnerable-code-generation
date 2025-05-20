//FormAI DATASET v1.0 Category: Queue Implementation ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>

/* defining the limit for the queue */
#define LIMIT 10

/* defining the queue structure */
struct queue {
    int data[LIMIT];
    int front, rear;
};

/* function to check if the queue is empty */
int isEmpty(struct queue *q) {
    if(q->front == -1) {
        return 1;
    } else {
        return 0;
    }
}

/* function to check if the queue is full */
int isFull(struct queue *q) {
    if(q->rear == LIMIT-1) {
        return 1;
    } else {
        return 0;
    }
}

/* function to insert an element into the queue */
void enqueue(struct queue *q, int element) {
    if(isFull(q)) {
        printf("Queue is full! Cannot insert element.\n");
    } else {
        if(q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->data[q->rear] = element;
        printf("Element %d inserted into the queue.\n", element);
    }
}

/* function to remove an element from the queue */
void dequeue(struct queue *q) {
    if(isEmpty(q)) {
        printf("Queue is empty! Cannot remove element.\n");
    } else {
        printf("Element %d removed from the queue.\n", q->data[q->front]);
        q->front++;
        if(q->front > q->rear) {
            q->front = q->rear = -1;
        }
    }
}

/* function to display the elements in the queue */
void display(struct queue *q) {
    if(isEmpty(q)) {
        printf("Queue is empty!\n");
    } else {
        printf("Elements in the queue are: ");
        for(int i=q->front; i<=q->rear; i++) {
            printf("%d ", q->data[i]);
        }
        printf("\n");
    }
}

/* main function */
int main() {
    /* creating an instance of the queue structure */
    struct queue *q = (struct queue*)malloc(sizeof(struct queue));
    q->front = -1;
    q->rear = -1;
    
    /* inserting elements into the queue */
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    
    /* displaying the elements in the queue */
    display(q);
    
    /* removing an element from the queue */
    dequeue(q);
    
    /* displaying the elements in the queue */
    display(q);
    
    return 0;
}