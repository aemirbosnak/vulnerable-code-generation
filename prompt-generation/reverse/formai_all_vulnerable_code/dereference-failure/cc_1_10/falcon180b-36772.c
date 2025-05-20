//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

//node structure definition
struct node{
    int data;
    struct node* next;
};

//function to create a new node with given data
struct node* createNode(int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if(!newNode){
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//function to add element to the end of the queue
void enqueue(struct node** frontRef, struct node** rearRef, int data){
    struct node* newNode = createNode(data);
    if(*frontRef == NULL){
        *frontRef = newNode;
        *rearRef = newNode;
    }
    else{
        (*rearRef)->next = newNode;
        *rearRef = newNode;
    }
}

//function to remove element from the front of the queue
int dequeue(struct node** frontRef, struct node** rearRef){
    struct node* temp = *frontRef;
    int data = temp->data;
    if(*frontRef!= NULL){
        *frontRef = (*frontRef)->next;
        if(*frontRef == NULL){
            *rearRef = NULL;
        }
    }
    free(temp);
    return data;
}

//function to display the elements in the queue
void display(struct node* front){
    printf("Queue elements are: ");
    while(front!= NULL){
        printf("%d ", front->data);
        front = front->next;
    }
    printf("\n");
}

int main(){
    struct node* front = NULL;
    struct node* rear = NULL;

    //test case 1: enqueue and dequeue operations
    enqueue(&front, &rear, 10);
    enqueue(&front, &rear, 20);
    enqueue(&front, &rear, 30);
    display(front);
    printf("Dequeued element is: %d\n", dequeue(&front, &rear));
    display(front);

    //test case 2: dequeue when queue is empty
    struct node* temp = dequeue(&front, &rear);
    printf("Dequeued element is: %d\n", temp);

    //test case 3: enqueue when queue is full
    for(int i=0; i<MAX; i++){
        enqueue(&front, &rear, i*10);
    }
    enqueue(&front, &rear, 100);

    return 0;
}