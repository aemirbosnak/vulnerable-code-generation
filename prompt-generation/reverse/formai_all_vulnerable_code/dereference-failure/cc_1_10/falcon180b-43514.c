//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_SIZE 100

//Node structure for creating linked list
struct Node{
    int data;
    struct Node* next;
};

//Queue structure for creating queue
struct Queue{
    struct Node* front;
    struct Node* rear;
    int size;
};

//Function for creating an empty queue
void createQueue(struct Queue* q){
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

//Function for checking if the queue is empty
bool isEmpty(struct Queue* q){
    if(q->front == NULL){
        return true;
    }
    else{
        return false;
    }
}

//Function for checking if the queue is full
bool isFull(struct Queue* q){
    if(q->size == MAX_SIZE){
        return true;
    }
    else{
        return false;
    }
}

//Function for adding an element to the rear of the queue
void enqueue(struct Queue* q, int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if(isEmpty(q)){
        q->front = newNode;
        q->rear = newNode;
    }
    else{
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
}

//Function for removing the element from the front of the queue
void dequeue(struct Queue* q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
    }
    else{
        struct Node* temp = q->front;
        q->front = q->front->next;
        free(temp);
        q->size--;
    }
}

//Function for displaying the elements in the queue
void display(struct Queue* q){
    struct Node* temp = q->front;
    printf("Queue elements are: ");
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    struct Queue q;
    createQueue(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    display(&q);
    dequeue(&q);
    dequeue(&q);
    display(&q);
    enqueue(&q, 40);
    enqueue(&q, 50);
    display(&q);
    return 0;
}