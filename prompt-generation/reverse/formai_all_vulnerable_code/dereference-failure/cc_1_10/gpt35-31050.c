//FormAI DATASET v1.0 Category: Data structures visualization ; Style: medieval
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct node{
    int data;
    struct node* next;
};

struct stack{
    struct node* top;
};

struct queue{
    struct node* front;
    struct node* rear;
};

void push(struct stack* stk, int element){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = element;
    newnode->next = stk->top;
    stk->top = newnode;
}

int pop(struct stack* stk){
    if(stk->top != NULL){
        int element = stk->top->data;
        stk->top = stk->top->next;
        return element;
    }
    else{
        printf("Stack underflow!\n");
        return -1;
    }
}

void enqueue(struct queue* q, int element){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = element;
    newnode->next = NULL;

    if(q->rear == NULL){
        q->rear = newnode;
        q->front = newnode;
    }
    else{
        q->rear->next = newnode;
        q->rear = newnode;
    }
}

int dequeue(struct queue* q){
    if(q->front != NULL){
        int element = q->front->data;
        q->front = q->front->next;
        if(q->front == NULL){
            q->rear = NULL;
        }
        return element;
    }
    else{
        printf("Queue underflow!\n");
        return -1;
    }
}

int main(){
    srand(time(0));
    struct stack stk;
    stk.top = NULL;

    struct queue q;
    q.front = NULL;
    q.rear = NULL;

    // Generate random data and visualize as a stack and queue
    printf("Welcome to the medieval world of stacks and queues!\n");
    printf("Behold, the wondrous stack and queue with data of warriors:\n");
    for(int i=0; i<10; i++){
        int data = rand() % 100;
        printf("|        |     ");
        printf("| %2d     |\n", data);
        push(&stk, data);
        enqueue(&q, data);
    }
    printf("|________|     ");
    printf("|_______|\n");

    // Remove warriors from the front of the queue and top of the stack
    printf("\nThe great battle has begun!\n");
    printf("Banished from the battle: ");
    for(int i=0; i<5; i++){
        int warrior1 = pop(&stk);
        int warrior2 = dequeue(&q);
        printf("%d, ", warrior1);
        printf("%d, ", warrior2);
    }
    printf("They have been defeated!\n");

    // Generate new warriors and add them to the front of the queue and top of the stack
    printf("\nThe kingdom calls for reinforcements!\n");
    printf("Incoming warriors: ");
    for(int i=0; i<5; i++){
        int data = rand() % 100;
        printf("%d, ", data);
        push(&stk, data);
        enqueue(&q, data);
    }

    // Display the new stack and queue with the added warriors
    printf("\nThe stack and queue with new warriors:\n");
    printf("|        |     ");
    for(struct node* ptr=stk.top; ptr!=NULL; ptr=ptr->next){
        printf("| %2d     | ", ptr->data);
    }
    printf("\n|________|     ");
    printf("|_______|\n");

    return 0;
}