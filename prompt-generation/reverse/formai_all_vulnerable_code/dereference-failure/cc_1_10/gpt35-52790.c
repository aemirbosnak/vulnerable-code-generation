//FormAI DATASET v1.0 Category: Queue Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
 
typedef struct queue {
    int front, rear;
    int capacity;
    int* array;
} queue;
 
queue* createQueue(int size) {
    queue* Q = (queue*)malloc(sizeof(queue));
    Q->capacity = size+1;
    Q->front =0;
    Q->rear =0;
    Q->array = (int*)malloc(Q->capacity*sizeof(int));
    return Q;
}
 
int isFull(queue* Q) {
    if((Q->rear+1) % Q->capacity == Q->front) {
        return 1;
    } else {
        return 0;
    }
}
 
int isEmpty(queue* Q) {
    if(Q->front == Q->rear) {
        return 1;
    } else {
        return 0;
    }
}
 
void enqueue(queue* Q, int data) {
    if(isFull(Q)) {
        printf("Overflow!\n");
    } else {
        Q->rear = (Q->rear+1) % Q->capacity;
        Q->array[Q->rear] = data;
    }
}
 
int dequeue(queue* Q) {
    if(isEmpty(Q)) {
        printf("Underflow!\n");
        return -1;
    } else {
        Q->front = (Q->front+1) % Q->capacity;
        int temp = Q->array[Q->front];
        return temp;
    }
}
 
void display(queue* Q) {
    int i=0;
    i = Q->front+1;
    while(i <= Q->rear) {
        printf("%d ", Q->array[i]);
        i++;
    }
    printf("\n");
}
 
int main() {
    queue* myQueue = createQueue(10);
    enqueue(myQueue, 1);
    enqueue(myQueue, 2);
    enqueue(myQueue, 3);
    printf("Queue Elements=");
    display(myQueue);
    dequeue(myQueue);
    printf("Queue Elements=");
    display(myQueue);
    return 0;
}