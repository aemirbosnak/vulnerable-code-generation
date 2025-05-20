//FormAI DATASET v1.0 Category: Data structures visualization ; Style: safe
#include<stdio.h>
#include<stdlib.h>

#define MAX 100

struct queue {
   int items[MAX];
   int front;
   int rear;
};

struct stack {
   int items[MAX];
   int top;
};

/* Create an empty queue */
struct queue* createQueue() {
    struct queue* q = malloc(sizeof(struct queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

/* Check if the queue is empty */
int isEmpty(struct queue* q) {
    if(q->rear == -1) 
        return 1;
    else 
        return 0;
}

/* Add an item to the queue */
void enqueue(struct queue* q, int value) {
    if(q->rear == MAX-1)
        printf("\nFull Queue");
    else {
        if(q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

/* Remove an item from the queue */
int dequeue(struct queue* q) {
    int item;
    if(isEmpty(q)) {
        printf("Empty Queue\n");
        item = -1;
    }
    else {
        item = q->items[q->front];
        q->front++;
        if(q->front > q->rear) {
            //printf("Resetting queue ");
            q->front = q->rear = -1;
        }
    }
    return item;
}

/* Create an empty stack */
struct stack* createStack() {
    struct stack* s = malloc(sizeof(struct stack));
    s->top = -1;
    return s;
}

/* Check if the stack is empty */
int stackEmpty(struct stack* s) {
    if(s->top == -1) 
        return 1;
    else 
        return 0;
}

/* Add an item to the stack */
void push(struct stack* s, int value) {
    if(s->top == MAX-1)
        printf("\nFull Stack");
    else {
        s->top++;
        s->items[s->top] = value;
    }
}

/* Remove an item from the stack */
int pop(struct stack* s) {
    int item;
    if(stackEmpty(s)) {
        printf("Empty Stack\n");
        item = -1;
    }
    else {
        item = s->items[s->top];
        s->top--;
    }
    return item;
}

/* Display the stack */
void displayStack(struct stack *s) {
    int i;
    if(stackEmpty(s))
        printf("\nEmpty Stack\n");
    else {
        printf("\nStack elements: ");
        for(i=0; i<=s->top; i++)
            printf("%d ",s->items[i]);
    }
}

/* Display the queue */
void displayQueue(struct queue *q) {
    int i;
    if(isEmpty(q))
        printf("\nEmpty Queue\n");
    else {
        printf("\nQueue elements: ");
        for(i=q->front; i<=q->rear; i++)
            printf("%d ",q->items[i]);
    }    
}

/* Main function */
int main() {
    struct queue* q = createQueue();
    struct stack* s = createStack();
    int choice, value;

    while(1) {
        printf("\n\nOPTIONS: \n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Push\n");
        printf("4. Pop\n");
        printf("5. Display Stack\n");
        printf("6. Display Queue\n");
        printf("7. Quit\n");

        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice) {
            case 1: 
                printf("\nEnter the value to be inserted: ");
                scanf("%d",&value);
                enqueue(q, value);
                break;
            case 2: 
                dequeue(q);
                break;
            case 3: 
                printf("\nEnter the value to be inserted: ");
                scanf("%d",&value);
                push(s, value);
                break;
            case 4: 
                pop(s);
                break;
            case 5: 
                displayStack(s);
                break;
            case 6: 
                displayQueue(q);
                break;
            case 7: 
                exit(0);
                break;
            default: 
                printf("\nWrong input. Try again.\n");
        }       
    }
    return 0;
}