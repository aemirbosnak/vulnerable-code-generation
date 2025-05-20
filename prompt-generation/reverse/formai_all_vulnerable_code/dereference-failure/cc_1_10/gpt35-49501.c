//FormAI DATASET v1.0 Category: Queue Implementation ; Style: retro
#include<stdio.h>
#include<stdlib.h>

#define MAX_QUEUE_SIZE 5

struct Queue {
    int arr[MAX_QUEUE_SIZE];
    int front, rear;
};

struct Queue* createQueue() {
    struct Queue* q = malloc(sizeof(struct Queue));
    q->front = q->rear = -1;
    return q;
}

int isFull(struct Queue* q) {
    return ((q->rear+1)%MAX_QUEUE_SIZE == q->front);
}

int isEmpty(struct Queue* q) {
    return (q->front == -1 && q->rear == -1);
}

void enqueue(struct Queue* q, int val) {
    if(isFull(q)) {
        printf("\nThe queue is full!\n");
        return;
    }
    else if(isEmpty(q)) {
        q->front = 0;
        q->rear = 0;
    }
    else {
        q->rear = (q->rear+1)%MAX_QUEUE_SIZE;
    }
    q->arr[q->rear] = val;
    printf("\n%d has been added to the queue.\n", val);
}

void dequeue(struct Queue* q) {
    if(isEmpty(q)) {
        printf("\nThe queue is empty!\n");
    }
    else if(q->front == q->rear) {
        printf("\n%d has been removed from the queue.\n", q->arr[q->front]);
        q->front = q->rear = -1;
    }
    else {
        printf("\n%d has been removed from the queue.\n", q->arr[q->front]);
        q->front = (q->front+1)%MAX_QUEUE_SIZE;
    }
}

int main() {
    struct Queue* q = createQueue();

    while(1) {
        int choice, val;

        printf("\n------------------------------------\n");
        printf("QUEUE OPERATIONS \n");
        printf("------------------------------------\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Exit\n");
        printf("------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: 
                printf("\nEnter a value to enqueue: ");
                scanf("%d", &val);
                enqueue(q, val);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                printf("\nGoodbye! Thank you for using the queue.\n\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}