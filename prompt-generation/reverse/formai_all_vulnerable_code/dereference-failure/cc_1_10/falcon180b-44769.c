//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX 100

// node structure definition
typedef struct node{
    int data;
    struct node* next;
}node;

// queue structure definition
typedef struct{
    node* front;
    node* rear;
}queue;

// function to create an empty queue
void createQueue(queue* q){
    q->front = q->rear = NULL;
}

// function to check if the queue is empty
int isEmpty(queue* q){
    if(q->front == NULL && q->rear == NULL)
        return TRUE;
    else
        return FALSE;
}

// function to check if the queue is full
int isFull(queue* q){
    node* temp = (node*)malloc(sizeof(node));
    if(temp == NULL)
        return TRUE;
    else{
        free(temp);
        return FALSE;
    }
}

// function to add an element to the rear of the queue
void enqueue(queue* q, int value){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = value;
    temp->next = NULL;

    if(isEmpty(q))
        q->front = q->rear = temp;
    else
        q->rear->next = temp;

    q->rear = temp;
}

// function to remove an element from the front of the queue
int dequeue(queue* q){
    node* temp = q->front;
    int value = temp->data;

    if(isEmpty(q))
        return -1;

    q->front = q->front->next;

    if(q->front == NULL)
        q->rear = NULL;

    free(temp);

    return value;
}

// function to display the contents of the queue
void display(queue* q){
    node* temp = q->front;
    printf("Queue: ");

    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main(){
    queue q;
    createQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    display(&q);

    int value = dequeue(&q);
    printf("Dequeued value: %d\n", value);

    display(&q);

    value = dequeue(&q);
    printf("Dequeued value: %d\n", value);

    display(&q);

    value = dequeue(&q);
    printf("Dequeued value: %d\n", value);

    display(&q);

    value = dequeue(&q);
    printf("Dequeued value: %d\n", value);

    display(&q);

    return 0;
}