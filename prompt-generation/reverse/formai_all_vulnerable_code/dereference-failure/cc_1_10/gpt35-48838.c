//FormAI DATASET v1.0 Category: Queue ; Style: lively
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10

//defining structure of queue
struct queue{
    int front, rear;
    int items[MAXSIZE];
};

//function to create a queue
struct queue* createQueue(){
    struct queue* que = (struct queue*)malloc(sizeof(struct queue));
    que->front = -1;
    que->rear = -1;
    return que;
}

//function to check if queue is full
int isFull(struct queue* que){
    if(que->rear == MAXSIZE-1){
        return 1;
    }
    else{
        return 0;
    }
}

//function to chekc if queue is empty
int isEmpty(struct queue* que){
    if(que->front == -1 && que->rear == -1){
        return 1;
    }
    else{
        return 0;
    }
}

//function to add elements to queue
void enqueue(struct queue* que, int val){
    if(isFull(que)){
        printf("\nOops! Queue is full. Can't add any more elements.");
    }
    else if(isEmpty(que)){
        que->front = que->rear = 0;
        que->items[que->rear] = val;
        printf("\nSuccessfully added element %d at index %d in queue.", val, que->rear);
    }
    else{
        que->rear++;
        que->items[que->rear] = val;
        printf("\nSuccessfully added element %d at index %d in queue.", val, que->rear);
    }
}

//function to remove elements from queue
int dequeue(struct queue* que){
    int val;
    if(isEmpty(que)){
        printf("\nOops! Queue is empty. Can't remove any elements.");
        return -1;
    }
    else if(que->front == que->rear){
        val = que->items[que->front];
        que->front = que->rear = -1;
        printf("\nSuccessfully removed element %d from queue.", val);
    }
    else{
        val = que->items[que->front];
        que->front++;
        printf("\nSuccessfully removed element %d from queue.", val);
    }
    return val;
}

//function to display elements of queue
void display(struct queue* que){
    int i;
    if(isEmpty(que)){
        printf("\nOops! Queue is empty. No elements to display.");
    }
    else{
        printf("\nThe elements of queue are:");
        for(i=que->front; i<=que->rear; i++){
            printf(" %d", que->items[i]);
        }
    }
}

int main(){
    int choice, val;
    struct queue* que = createQueue();
    while(1){
        printf("\n\n======= Main Menu ========");
        printf("\n1. Add element to queue");
        printf("\n2. Remove element from queue");
        printf("\n3. Display queue elements");
        printf("\n4. Exit program");
        printf("\nEnter your choice:");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("\nEnter the element to be added to queue:");
                scanf("%d", &val);
                enqueue(que, val);
                break;
            case 2:
                dequeue(que);
                break;
            case 3:
                display(que);
                break;
            case 4:
                printf("\nExiting program...");
                exit(0);
            default:
                printf("\nInvalid choice. Try again.");
                break;
        }
    }
    return 0;
}