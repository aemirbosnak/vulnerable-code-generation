//FormAI DATASET v1.0 Category: Queue Implementation ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>

struct queue{
    int front, rear, capacity;
    int *array;
};

struct queue *createQueue(int size){
    struct queue *q = (struct queue*) malloc(sizeof(struct queue));
    q->front = q->rear = -1;
    q->capacity = size;
    q->array = (int*)malloc(sizeof(int)*q->capacity);
    return q;
}

int isFull(struct queue *q){
    return ((q->rear+1)%q->capacity == q->front);
}

int isEmpty(struct queue *q){
    return (q->front == -1);
}

void enqueue(struct queue *q, int data){
    if(isFull(q)){
        printf("Queue is full. Can't enqueue.");
        return;
    }else{
        q->rear = (q->rear+1)%q->capacity;
        q->array[q->rear] = data;
        if(q->front == -1)
           q->front = q->rear;
    }
}

int dequeue(struct queue *q){
    int data;
    if(isEmpty(q)){
        printf("Queue is empty. Can't dequeue.");
        return -1;
    }else{
        data = q->array[q->front];
        if(q->front == q->rear)
           q->front = q->rear = -1;
        else
           q->front = (q->front+1)%q->capacity;
        return data;
    }
}

void displayQueue(struct queue *q){
    if(q->front == -1)
       return;
    else{
        int i = q->front;
        printf("\nElements in Queue are: ");
        while(i != q->rear){
            printf("%d ", q->array[i]);
            i = (i+1)%q->capacity;
        }
        printf("%d", q->array[i]);
    }
}

int main(){
    struct queue *q = createQueue(5);
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    displayQueue(q);
    printf("\nDequeuing element %d", dequeue(q));
    printf("\nDequeuing element %d", dequeue(q));
    displayQueue(q);
    enqueue(q, 40);
    enqueue(q, 50);
    enqueue(q, 60);
    displayQueue(q);
    return 0;
}