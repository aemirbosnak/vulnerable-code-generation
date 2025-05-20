//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define MAX 100

//struct for a node
struct node{
    int data;
    struct node *next;
};

//struct for the queue
struct Queue{
    struct node *front;
    struct node *rear;
};

//function to create an empty queue
struct Queue* createQueue(){
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

//function to check if the queue is empty
bool isEmpty(struct Queue* q){
    if(q->front == NULL && q->rear == NULL)
        return true;
    else
        return false;
}

//function to enqueue an element into the queue
void enqueue(struct Queue* q, int data){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    if(isEmpty(q))
        q->front = temp;
    else
        q->rear->next = temp;
    q->rear = temp;
}

//function to dequeue an element from the queue
int dequeue(struct Queue* q){
    int data;
    struct node* temp = q->front;
    if(isEmpty(q))
        printf("Queue Underflow\n");
    else{
        data = temp->data;
        q->front = temp->next;
        free(temp);
    }
    return data;
}

//function to display the elements in the queue
void display(struct Queue* q){
    struct node* temp = q->front;
    if(isEmpty(q))
        printf("Queue is Empty\n");
    else{
        printf("Elements in the Queue are: ");
        while(temp!= NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

//main function
int main(){
    struct Queue* q = createQueue();
    int choice, data;
    while(1){
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the element to be enqueued: ");
                scanf("%d", &data);
                enqueue(q, data);
                break;
            case 2:
                data = dequeue(q);
                if(data!= -1)
                    printf("The dequeued element is: %d\n", data);
                break;
            case 3:
                display(q);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}