//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

//Structure for node
struct node{
    int data;
    struct node *next;
};

//Structure for queue
struct queue{
    struct node *front;
    struct node *rear;
};

//Function to create a new node
struct node *create_node(int data){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

//Function to create an empty queue
struct queue *create_queue(){
    struct queue *newqueue = (struct queue *)malloc(sizeof(struct queue));
    newqueue->front = NULL;
    newqueue->rear = NULL;
    return newqueue;
}

//Function to check if queue is empty
int is_empty(struct queue *queue){
    if(queue->front == NULL && queue->rear == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

//Function to add element to rear of queue
void enqueue(struct queue *queue, int data){
    struct node *newnode = create_node(data);
    if(is_empty(queue)){
        queue->front = newnode;
        queue->rear = newnode;
    }
    else{
        queue->rear->next = newnode;
        queue->rear = newnode;
    }
}

//Function to remove element from front of queue
int dequeue(struct queue *queue){
    int data;
    struct node *temp = queue->front;
    data = temp->data;
    queue->front = temp->next;
    free(temp);
    if(is_empty(queue)){
        queue->rear = NULL;
    }
    return data;
}

//Function to display elements in queue
void display(struct queue *queue){
    struct node *temp = queue->front;
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    struct queue *queue = create_queue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    display(queue);
    int data = dequeue(queue);
    printf("Dequeued element: %d\n", data);
    display(queue);
    return 0;
}