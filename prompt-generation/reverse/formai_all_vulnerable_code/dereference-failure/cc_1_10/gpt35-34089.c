//FormAI DATASET v1.0 Category: Data structures visualization ; Style: future-proof
#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

void initQueue(Queue* q){
    q->front = NULL;
    q->rear = NULL;
}

int isQueueEmpty(Queue* q){
    return q->front==NULL;
}

void enqueue(Queue* q, int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if(q->front==NULL){
        q->front = q->rear = newNode;
    }
    else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(Queue* q){
   if(q->front==NULL){
      printf("Queue is empty\n");
      return -1;
   }
   int item = q->front->data;
   if(q->front == q->rear){
      free(q->front);
      q->front = q->rear = NULL;
   }
   else{
      Node* temp = q->front;
      q->front = q->front->next;
      free(temp);
   }
   return item;
}

void display(Queue* q){
   Node* temp;
   if(q->front==NULL)
      printf("Queue is Empty\n");
   else{
      temp=q->front;
      while(temp!=NULL){
         printf("%d ", temp->data);
         temp=temp->next;
      }
      printf("\n");
   }
}

int main(){
    Queue q;
    initQueue(&q);
    printf("Enqueuing 5, 10, 15, 20....\n");
    enqueue(&q, 5);
    enqueue(&q, 10);
    enqueue(&q, 15);
    enqueue(&q, 20);
    printf("Queue contains: ");
    display(&q);
    printf("Dequeuing front element..\n");
    int item = dequeue(&q);
    printf("Removed item: %d\n", item);
    printf("Queue contains: ");
    display(&q);
    printf("Enqueuing 25 and 30....\n");
    enqueue(&q, 25);
    enqueue(&q, 30);
    printf("Queue contains: ");
    display(&q);
    printf("Dequeuing from an empty queue....\n");
    dequeue(&q);
    printf("Queue contains: ");
    display(&q);
    return 0;
}