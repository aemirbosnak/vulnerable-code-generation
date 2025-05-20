//FormAI DATASET v1.0 Category: Queue Implementation ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
typedef struct queue{
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;
}queue;

queue* createQueue(int capacity){
    queue* q=(queue*)malloc(sizeof(queue));
    q->arr=(int*)malloc(sizeof(int)*capacity);
    q->front=q->size=0;
    q->rear=capacity-1;
    q->capacity=capacity;
    return q;
}

void enQueue(queue* q,int item){
    if(q->size==q->capacity){
        printf("Queue Full\n");
        return;
    }
    
    q->rear=(q->rear+1)%q->capacity;
    q->arr[q->rear]=item;
    q->size++;
    printf("%d inserted successfully\n",item);
}

int deQueue(queue* q){
    if(q->size==0){
        printf("Queue Empty\n");
        return -1;
    }
    
    int item=q->arr[q->front];
    q->front=(q->front+1)%q->capacity;
    q->size--;
    printf("%d deleted successfully\n",item);
    return item;
}

int main(){
    queue* q=createQueue(5);
    enQueue(q,10);
    enQueue(q,20);
    enQueue(q,30);
    enQueue(q,40);
    enQueue(q,50);
    enQueue(q,60);
    deQueue(q);
    deQueue(q);
    deQueue(q);
    deQueue(q);
    deQueue(q);
    deQueue(q);
    return 0;
}