//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TRUE 1
#define FALSE 0
#define MAX 100

typedef struct node{
    int data;
    struct node* next;
}node;

typedef struct{
    node* front;
    node* rear;
}queue;

void enqueue(queue* q, int value){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = value;
    temp->next = NULL;
    if(q->front == NULL){
        q->front = temp;
        q->rear = temp;
    }
    else{
        q->rear->next = temp;
        q->rear = temp;
    }
}

int dequeue(queue* q){
    node* temp = q->front;
    int value = temp->data;
    q->front = q->front->next;
    free(temp);
    return value;
}

void display(queue* q){
    node* temp = q->front;
    printf("Queue elements are: ");
    while(temp!= NULL){
        printf(" %d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    queue q;
    q.front = NULL;
    q.rear = NULL;
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    display(&q);
    printf("Dequeued element is: %d\n", dequeue(&q));
    display(&q);
    return 0;
}