//FormAI DATASET v1.0 Category: Queue Implementation ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct Queue{
    Node* front;
    Node* rear;
    int size;
}Queue;

void enqueue(Queue* q, int val){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = val;
    new_node->next = NULL;
    if(q->front == NULL && q->rear == NULL){
        q->front = q->rear = new_node;
        q->size++;
        return;
    }
    q->rear->next = new_node;
    q->rear = new_node;
    q->size++;
}

int dequeue(Queue* q){
    if(q->front == NULL){
        printf("The queue is empty\n");
        return -1;
    }
    int val = q->front->data;
    Node* temp = q->front;
    q->front = q->front->next;
    if(q->front == NULL){
        q->rear = NULL;
    }
    free(temp);
    q->size--;
    return val;
}

int front(Queue* q){
    return q->front->data;
}

int rear(Queue* q){
    return q->rear->data;
}

int size(Queue* q){
    return q->size;
}

void display(Queue* q){
    Node* temp = q->front;
    printf("Queue: ");
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    q->size = 0;

    printf("Welcome to the Queue Game\n");
    printf("How many players do you have?\n");
    int num, player;
    scanf("%d",&num);

    for(int i=1; i<=num; i++){
        enqueue(q, i);
    }

    int flag = 1;
    while(q->size > 1){
        player = dequeue(q);
        printf("Player %d's turn\n", player);
        if(flag){
            printf("Enter a number: ");
            int n;
            scanf("%d",&n);
            for(int i=1; i<n; i++){
                player = dequeue(q);
                enqueue(q, player);
            }
            flag = 0;
        }else{
            printf("Enter a valid number (less than or equal to %d): ", q->size);
            int n;
            scanf("%d",&n);
            if(n > q->size){
                printf("Invalid number, try again\n");
                flag = 1;
                enqueue(q, player);
            }else{
                for(int i=1; i<n; i++){
                    player = dequeue(q);
                    enqueue(q, player);
                }
            }
        }
        display(q);
        enqueue(q, player);
        flag = !flag;
    }
    printf("Player %d wins the game\n",q->front->data);
    return 0;
}