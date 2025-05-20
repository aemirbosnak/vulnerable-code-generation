//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}node;

typedef struct Queue{
    node* front;
    node* rear;
}queue;

void initQueue(queue* q){
    q->front = NULL;
    q->rear = NULL;
}

int isEmpty(queue* q){
    if(q->front == NULL)
        return 1;
    else
        return 0;
}

void enqueue(queue* q, int data){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    
    if(isEmpty(q))
        q->front = temp;
    else
        q->rear->next = temp;
    
    q->rear = temp;
}

int dequeue(queue* q){
    if(isEmpty(q))
        return -1;
    
    node* temp = q->front;
    int data = temp->data;
    
    if(q->front == q->rear)
        q->front = NULL;
    else
        q->front = q->front->next;
    
    free(temp);
    
    return data;
}

void display(queue* q){
    node* temp = q->front;
    
    if(isEmpty(q))
        printf("Queue is empty\n");
    else{
        printf("Queue elements are: ");
        while(temp!= NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(){
    queue q;
    initQueue(&q);
    
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    
    display(&q);
    
    int x = dequeue(&q);
    printf("Dequeued element is: %d\n", x);
    
    display(&q);
    
    enqueue(&q, 5);
    enqueue(&q, 6);
    
    display(&q);
    
    return 0;
}