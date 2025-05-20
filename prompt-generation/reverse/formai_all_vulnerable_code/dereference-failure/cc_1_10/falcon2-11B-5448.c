//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: visionary
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 10

struct Queue{
    int data[MAX];
    int rear;
    int front;
};

struct Queue* create(){
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->rear = -1;
    q->front = -1;
    return q;
}

void push(struct Queue* q, int data){
    if(q->rear == MAX-1){
        printf("Queue is full\n");
        return;
    }
    if(q->front == -1){
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX;
    q->data[q->rear] = data;
}

int pop(struct Queue* q){
    if(q->front == -1){
        printf("Queue is empty\n");
        return -1;
    }
    int data = q->data[q->front];
    q->front = (q->front + 1) % MAX;
    return data;
}

int front(struct Queue* q){
    if(q->front == -1){
        printf("Queue is empty\n");
        return -1;
    }
    return q->data[q->front];
}

int is_empty(struct Queue* q){
    if(q->front == -1){
        return 1;
    }
    return 0;
}

int main(){
    struct Queue* q = create();
    push(q, 1);
    push(q, 2);
    push(q, 3);
    printf("Front element is: %d\n", front(q));
    printf("Popped element is: %d\n", pop(q));
    printf("Front element is: %d\n", front(q));
    printf("Popped element is: %d\n", pop(q));
    printf("Front element is: %d\n", front(q));
    printf("Popped element is: %d\n", pop(q));
    printf("Queue is empty? %d\n", is_empty(q));
    return 0;
}