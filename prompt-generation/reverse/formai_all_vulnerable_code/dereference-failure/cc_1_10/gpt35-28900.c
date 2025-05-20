//FormAI DATASET v1.0 Category: Data structures visualization ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

/* Define the maximum size of the data structures */
#define MAX_SIZE 10

/* Struct to represent a node in the Stack */
typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

/* Function to push an element onto the Stack */
void push(Stack *s, int val) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    s->data[++s->top] = val;
}

/* Function to pop an element from the Stack */
int pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return s->data[s->top--];
}

/* Function to represent the Stack as a String */
char *stackToString(Stack *s) {
    char *str = (char *) malloc(sizeof(char) * MAX_SIZE * 3);
    int i, j = 0;
    for (i = s->top; i >= 0; i--) {
        j += sprintf(&str[j], "%d -> ", s->data[i]);
    }
    strcpy(&str[j-4], "");
    return str;
}

/* Struct to represent a node in the Queue */
typedef struct {
    int data[MAX_SIZE];
    int front, rear;
} Queue;

/* Function to enqueue an element in the Queue */
void enqueue(Queue *q, int val) {
    if (q->rear == MAX_SIZE - 1) {
        printf("Queue Overflow!\n");
        return;
    }
    q->data[++q->rear] = val;
}

/* Function to dequeue an element from the Queue */
int dequeue(Queue *q) {
    if (q->front > q->rear) {
        printf("Queue Underflow!\n");
        return -1;
    }
    return q->data[q->front++];
}

/* Function to represent the Queue as a String */
char *queueToString(Queue *q) {
    char *str = (char *) malloc(sizeof(char) * MAX_SIZE * 3);
    int i, j = 0;
    for (i = q->front; i <= q->rear; i++) {
        j += sprintf(&str[j], "%d -> ", q->data[i]);
    }
    strcpy(&str[j-4], "");
    return str;
}

int main() {
    /* Initialize an example Stack and Queue */
    Stack s = {.data = {1, 2, 3}, .top = 2};
    Queue q = {.data = {4, 5}, .front = 0, .rear = 1};
    
    /* Print the Stack and Queue as Strings */
    printf("Stack: %s\n", stackToString(&s));
    printf("Queue: %s\n", queueToString(&q));
    
    /* Push an element onto the Stack and enqueue an element in the Queue */
    push(&s, 4);
    enqueue(&q, 6);
    
    /* Print the Stack and Queue as Strings again */
    printf("Stack: %s\n", stackToString(&s));
    printf("Queue: %s\n", queueToString(&q));
    
    /* Pop an element from the Stack and dequeue an element from the Queue */
    pop(&s);
    dequeue(&q);
    
    /* Print the Stack and Queue as Strings again */
    printf("Stack: %s\n", stackToString(&s));
    printf("Queue: %s\n", queueToString(&q));
    
    return 0;
}