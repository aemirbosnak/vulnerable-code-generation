//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

struct QueueNode {
    int data;
    struct QueueNode *next;
};

struct Queue {
    struct QueueNode *front;
    struct QueueNode *rear;
};

// Function to initialize the Queue
void initQueue(struct Queue *q) {
    q->front = NULL;
    q->rear = NULL;
}

// Function to insert an element at the rear of the queue
void enQueue(struct Queue *q, int data) {
    struct QueueNode *newNode = (struct QueueNode*) malloc(sizeof(struct QueueNode));
    newNode->data = data;
    newNode->next = NULL;
    
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Function to remove an element from the front of the queue
int deQueue(struct Queue *q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    
    int data = q->front->data;
    struct QueueNode *temp = q->front;
    q->front = q->front->next;
    
    free(temp);
    
    if (q->front == NULL) {
        q->rear = NULL;
    }
    
    return data;
}

// Function to display the elements in the queue
void displayQueue(struct Queue *q) {
    struct QueueNode *temp = q->front;
    
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    struct Queue q;
    initQueue(&q);
    
    enQueue(&q, 10);
    enQueue(&q, 20);
    enQueue(&q, 30);
    enQueue(&q, 40);
    
    displayQueue(&q);
    printf("Removed element %d\n", deQueue(&q));
    displayQueue(&q);
    
    return 0;
}