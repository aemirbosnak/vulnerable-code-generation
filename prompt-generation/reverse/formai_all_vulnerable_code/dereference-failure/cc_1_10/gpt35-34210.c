//FormAI DATASET v1.0 Category: Queue Implementation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 5

struct queue {
    int front;
    int rear;
    int items[MAX_QUEUE_SIZE];
};

typedef struct queue Queue;

Queue* createQueue() {
    Queue *q = (Queue*) malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;

    return q;
}

int isFull(Queue *q) {
    if(q->rear == MAX_QUEUE_SIZE-1) {
        return 1;
    } else {
        return 0;
    }
}

int isEmpty(Queue *q) {
    if(q->front == -1 || q->front > q->rear) {
        return 1;
    } else {
        return 0;
    }
}

void enqueue(Queue *q, int value) {
    if(isFull(q)) {
        printf("Sorry, our queue is full.\n");
        return;
    }

    q->rear++;
    q->items[q->rear] = value;

    if(q->front == -1) {
        q->front = 0;
    }

    printf("My darling, I have added a new element to our queue.\n");
}

int dequeue(Queue *q) {
    if(isEmpty(q)) {
        printf("My love, our queue is empty.\n");
        return -1;
    }

    int item = q->items[q->front];
    q->front++;

    printf("My sweet, I have removed an element from our queue.\n");

    return item;
}

void display(Queue *q) {
    int i;
    if(isEmpty(q)) {
        printf("My dear, our queue is empty.\n");
    } else {
        printf("My love, this is our queue:\n");
        for(i=q->front; i<=q->rear; i++) {
            printf("%d ",q->items[i]);
        }
        printf("\n");
    }
}

int main() {
    Queue *myQueue = createQueue();

    int choice, val;

    do {
        printf("My love, what would you like to do with our queue?\n");
        printf("1. Enqueue an element\n");
        printf("2. Dequeue an element\n");
        printf("3. Display the queue\n");
        printf("4. Exit\n");

        scanf("%d",&choice);

        switch (choice) {
            case 1:
                printf("My darling, enter the element you want to enqueue: ");
                scanf("%d",&val);
                enqueue(myQueue,val);
                break;
            case 2:
                dequeue(myQueue);
                break;
            case 3:
                display(myQueue);
                break;
            case 4:
                printf("Goodbye my love, see you soon.\n");
                exit(0);
                break;
            default:
                printf("My love, that is an invalid choice. Please try again.\n");
        }
    } while(choice != 4);

    return 0;
}