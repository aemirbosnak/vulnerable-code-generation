//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int data;
    struct node* next;
} node;

node* createNode(int data){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void enqueue(node** front, node** rear, int data){
    node* newNode = createNode(data);
    if(*front == NULL){
        *front = newNode;
        *rear = newNode;
    }
    else{
        (*rear)->next = newNode;
        *rear = newNode;
    }
}

int dequeue(node** front, node** rear){
    node* temp = *front;
    int data = temp->data;
    *front = temp->next;
    if(*front == NULL){
        *rear = NULL;
    }
    free(temp);
    return data;
}

int peek(node* front){
    return front->data;
}

int isEmpty(node* front){
    if(front == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void display(node* front){
    while(front!= NULL){
        printf("%d ", front->data);
        front = front->next;
    }
}

int main(){
    node* front = NULL;
    node* rear = NULL;

    enqueue(&front, &rear, 1);
    enqueue(&front, &rear, 2);
    enqueue(&front, &rear, 3);
    enqueue(&front, &rear, 4);
    enqueue(&front, &rear, 5);

    printf("Queue after enqueue: ");
    display(front);

    int dequeuedData = dequeue(&front, &rear);
    printf("\nDequeued data: %d", dequeuedData);

    printf("\nQueue after dequeue: ");
    display(front);

    int peekedData = peek(front);
    printf("\nPeeked data: %d", peekedData);

    printf("\nIs the queue empty? %d", isEmpty(front));

    return 0;
}