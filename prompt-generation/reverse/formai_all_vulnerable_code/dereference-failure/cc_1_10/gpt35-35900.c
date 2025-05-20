//FormAI DATASET v1.0 Category: Queue Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

struct Queue {
    int items[MAX_QUEUE_SIZE];
    int front;
    int rear;
};

typedef struct Queue queue;

queue* createQueue(){
    queue* q = malloc(sizeof(queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isEmpty(queue* q){
    if(q->rear == -1) 
        return 1;
    else 
        return 0;
}

void enqueue(queue* q, int value){
    if(q->rear == MAX_QUEUE_SIZE-1)
        printf("Queue is full! \n");
    else {
        if(q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
        printf("Inserted %d into the queue \n", value);
    }
}

int dequeue(queue* q){
    int item;
    if(isEmpty(q)){
        printf("Queue is empty! \n");
        item = -1;
    }
    else{
        item = q->items[q->front];
        q->front++;
        if(q->front > q->rear){
            // reset the queue
            q->front = q->rear = -1;
        }
    }
    return item;
}

void printQueue(queue *q) {
    if(isEmpty(q)) {
        printf("Queue is empty! \n");
    } else {
        printf("Queue contains: ");
        for(int i = q->front; i < q->rear + 1; i++) {
            printf("%d ",q->items[i]);
        }
        printf("\n");
    }
}

int main() {
    queue* q = createQueue();

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    enqueue(q, 6);
    enqueue(q, 7);
    enqueue(q, 8);
    enqueue(q, 9);
    enqueue(q, 10);
    enqueue(q, 11);
    printQueue(q);

    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    printQueue(q);

    enqueue(q, 12);
    printQueue(q);

    enqueue(q, 13);
    printQueue(q);

    return 0;
}