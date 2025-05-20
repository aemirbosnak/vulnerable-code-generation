//FormAI DATASET v1.0 Category: Queue Implementation ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 5 //maximum size of queue

//structure of queue
struct queue {
    int arr[MAX_SIZE];
    int front;
    int rear;
    int size;
};

//function to create new queue
struct queue* create_queue() {
    struct queue* new_queue = (struct queue*)malloc(sizeof(struct queue));
    new_queue->front = -1;
    new_queue->rear = -1;
    new_queue->size = 0;
    return new_queue;
}

//function to check if queue is full
int is_full(struct queue* q) {
    if(q->rear == MAX_SIZE-1)
        return 1;
    return 0;
}

//function to check if queue is empty
int is_empty(struct queue* q) {
    if(q->front == -1)
        return 1;
    return 0;
}

//function to add elements in queue
void enqueue(struct queue* q, int num) {
    if(is_full(q)) {
        printf("Queue is Full!\n");
        return;
    }
    if(is_empty(q)) {
        q->front = 0;
        q->rear=0;
    }
    else {
        q->rear += 1;
    }
    q->arr[q->rear] = num;
    q->size += 1;
}

//function to remove elements from queue
int dequeue(struct queue* q) {
    int temp;
    if(is_empty(q)) {
        printf("Queue is Empty!\n");
        return -1;
    }
    else {
        temp = q->arr[q->front];
        if(q->front == q->rear){
            q->front = -1;
            q->rear = -1;
        }
        else {
            q->front += 1;
        }
        q->size -= 1;
    }
    return temp;
}

//function to display queue
void display(struct queue* q) {
    if(is_empty(q)) {
        printf("Queue is Empty!\n");
        return;
    }
    else {
        printf("Queue is: ");
        for(int i=q->front; i<=q->rear; i++) {
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}

int main() {
    struct queue* q = create_queue();
    int choice, data;
    while(1) {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                printf("Enter the element to add : ");
                scanf("%d",&data);
                enqueue(q, data);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                display(q);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Please enter valid choice.\n");
        }
    }
    return 0;
}