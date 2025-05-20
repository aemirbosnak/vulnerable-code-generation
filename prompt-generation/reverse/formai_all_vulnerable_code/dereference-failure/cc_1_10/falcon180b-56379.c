//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

//node structure definition
struct Node{
    int data;
    struct Node* next;
};

//function to create an empty queue
void createQueue(struct Node** front, struct Node** rear){
    *front = *rear = NULL;
}

//function to check if the queue is empty
int isEmpty(struct Node* front){
    return front == NULL;
}

//function to add an element to the rear of the queue
void enqueue(struct Node** front, struct Node** rear, int value){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("Memory Error\n");
        exit(0);
    }
    newNode->data = value;
    newNode->next = NULL;
    if(isEmpty(*front)){
        *front = *rear = newNode;
    }
    else{
        (*rear)->next = newNode;
        (*rear) = newNode;
    }
}

//function to remove an element from the front of the queue
int dequeue(struct Node** front, struct Node** rear){
    int value = -1;
    if(isEmpty(*front)){
        printf("Queue is Empty\n");
    }
    else{
        struct Node* temp = *front;
        value = temp->data;
        *front = (*front)->next;
        if(isEmpty(*front)){
            *rear = NULL;
        }
        free(temp);
    }
    return value;
}

//function to display the elements of the queue
void display(struct Node* front){
    if(isEmpty(front)){
        printf("Queue is Empty\n");
    }
    else{
        printf("Elements in the Queue are:\n");
        struct Node* temp = front;
        while(temp!= NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

int main(){
    struct Node* front = NULL;
    struct Node* rear = NULL;
    createQueue(&front, &rear);
    enqueue(&front, &rear, 1);
    enqueue(&front, &rear, 2);
    enqueue(&front, &rear, 3);
    display(front);
    int value = dequeue(&front, &rear);
    printf("Dequeued value is %d\n", value);
    display(front);
    return 0;
}