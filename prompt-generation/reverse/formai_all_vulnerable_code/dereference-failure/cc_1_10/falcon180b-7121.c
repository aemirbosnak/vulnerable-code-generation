//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: secure
#include<stdio.h>
#include<stdlib.h>

#define MAX 100

//Node structure declaration
struct node{
    int data;
    struct node* next;
};

//Function to create an empty queue
void createQueue(struct node** front, struct node** rear){
    *front = (struct node*)malloc(sizeof(struct node));
    (*front)->data = -1;
    (*front)->next = NULL;
    *rear = *front;
}

//Function to check if the queue is empty
int isEmpty(struct node* front){
    if(front->data == -1 && front->next == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

//Function to check if the queue is full
int isFull(struct node* rear){
    if((rear->next == NULL) && (rear->data!= -1)){
        return 1;
    }
    else{
        return 0;
    }
}

//Function to add an element to the queue
void enqueue(struct node** front, struct node** rear, int data){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    if(isEmpty(*front)){
        (*front) = temp;
        (*rear) = temp;
    }
    else{
        (*rear)->next = temp;
        (*rear) = temp;
    }
}

//Function to remove an element from the queue
void dequeue(struct node** front, struct node** rear){
    struct node* temp = (*front);
    (*front) = (*front)->next;
    if((*front) == NULL){
        (*rear) = NULL;
    }
    free(temp);
}

//Function to display the elements in the queue
void display(struct node* front){
    printf("The elements in the queue are: ");
    while(front!= NULL){
        printf("%d ", front->data);
        front = front->next;
    }
    printf("\n");
}

int main(){
    struct node* front = NULL;
    struct node* rear = NULL;
    createQueue(&front, &rear);
    enqueue(&front, &rear, 10);
    enqueue(&front, &rear, 20);
    enqueue(&front, &rear, 30);
    display(front);
    dequeue(&front, &rear);
    dequeue(&front, &rear);
    display(front);
    return 0;
}