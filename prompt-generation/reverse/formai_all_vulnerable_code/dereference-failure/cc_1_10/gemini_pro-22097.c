//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: random
#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;

struct queue{
    node* front, *rear;
};

void enqueue(struct queue* q, int data)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    if(q->rear == NULL){
        q->front = q->rear = temp;
    }else{
        q->rear->next = temp;
        q->rear = temp;
    }
}

int dequeue(struct queue* q)
{
    if(q->front == NULL){
        printf("Queue Empty");
        return -1;
    }else{
        node* temp = q->front;
        int data = temp->data;
        q->front = q->front->next;
        if(q->front == NULL)
            q->rear = NULL;
        free(temp);
        return data;
    }
}

void display(struct queue* q)
{
    if(q->front == NULL){
        printf("Queue Empty");
    }else{
        node* temp = q->front;
        while(temp != NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->front = q->rear = NULL;
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    display(q);
    printf("Dequeued: %d\n", dequeue(q));
    display(q);
    printf("Dequeued: %d\n", dequeue(q));
    display(q);
    printf("Dequeued: %d\n", dequeue(q));
    display(q);
    printf("Dequeued: %d\n", dequeue(q));
    display(q);
    printf("Dequeued: %d\n", dequeue(q));
    display(q);
    return 0;
}