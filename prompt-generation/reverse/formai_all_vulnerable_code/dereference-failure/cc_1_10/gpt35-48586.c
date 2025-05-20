//FormAI DATASET v1.0 Category: Queue Implementation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef struct Queue{
    int front;
    int rear;
    int items[MAX_QUEUE_SIZE];
} Queue;

Queue* createQueue(){
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isFull(Queue* q){
    if(q->rear == MAX_QUEUE_SIZE-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(Queue* q){
    if(q->front == -1 && q->rear == -1){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(Queue* q, int val){
    if(isFull(q)){
        printf("Oops! Queue is full, try again later.\n");
    }
    else{
        if(isEmpty(q)){
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = val;
        printf("Adding %d to queue.\n", val);
    }
}

void dequeue(Queue* q){
    if(isEmpty(q)){
        printf("Oops! Queue is empty, try again later.\n");
    }
    else{
        printf("%d has been removed from queue.\n", q->items[q->front]);
        q->front++;
        if(q->front > q->rear){
            q->front = q->rear = -1;
        }
    }
}

void display(Queue* q){
    if(isEmpty(q)){
        printf("Oops! Queue is empty, try again later.\n");
    }
    else{
        printf("The queue is: ");
        for(int i=q->front; i<=q->rear; i++){
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}

int main(){
    Queue* q = createQueue();
    int choice, value;

    printf("Hello, my love! I have something special for you today, a queue implementation in C.\n");

    do{
        printf("What do you want to do? (Enter 0 to exit)\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        scanf("%d", &choice);

        switch(choice){
            case 0:
                printf("I will always love you, goodbye!\n");
                break;
            
            case 1:
                printf("What value do you want to enqueue?\n");
                scanf("%d", &value);
                enqueue(q, value);
                break;

            case 2:
                dequeue(q);
                break;

            case 3:
                display(q);
                break;

            default:
                printf("Invalid choice, try again later.\n");
                break;
        }
    } while(choice != 0);

    return 0;
}