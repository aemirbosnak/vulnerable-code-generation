//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

struct node{
    int data;
    struct node* next;
};

struct queue{
    struct node* front;
    struct node* rear;
};

void init(struct queue* q){
    q->front = NULL;
    q->rear = NULL;
}

int is_empty(struct queue* q){
    if(q->front == NULL && q->rear == NULL)
        return 1;
    else
        return 0;
}

int is_full(struct queue* q){
    if((q->rear->next == NULL) && (q->rear!= q->front))
        return 0;
    else
        return 1;
}

void enqueue(struct queue* q, int value){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;
    temp->next = NULL;
    if(q->rear == NULL)
        q->front = q->rear = temp;
    else
        q->rear->next = temp;
    q->rear = temp;
}

int dequeue(struct queue* q){
    int value = 0;
    struct node* temp = q->front;
    if(q->front!= NULL)
        value = q->front->data;
    q->front = q->front->next;
    free(temp);
    return value;
}

void display(struct queue* q){
    struct node* temp = q->front;
    if(q->front!= NULL)
        printf("Queue Elements are : ");
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    struct queue q;
    init(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    display(&q);
    printf("After Dequeue :\n");
    printf("Dequeued element is %d\n", dequeue(&q));
    display(&q);
    printf("After Dequeue :\n");
    printf("Dequeued element is %d\n", dequeue(&q));
    display(&q);
    printf("After Dequeue :\n");
    printf("Dequeued element is %d\n", dequeue(&q));
    return 0;
}