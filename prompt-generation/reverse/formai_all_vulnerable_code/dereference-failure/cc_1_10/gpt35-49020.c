//FormAI DATASET v1.0 Category: Data structures visualization ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int data;
    struct _node *next;
} Node;

typedef struct _stack {
    Node *head;
} Stack;

typedef struct _queue {
    Node *front;
    Node *rear;
} Queue;

void initStack(Stack *stack) {
    stack->head = NULL;
}

int isEmptyStack(Stack *stack) {
    return (stack->head == NULL);
}

void push(Stack *stack, int data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = stack->head;
    stack->head = newNode;
}

int pop(Stack *stack) {
    if (isEmptyStack(stack))
        return -1;
    Node *temp = stack->head;
    int data = temp->data;
    stack->head = temp->next;
    free(temp);
    return data;
}

void printStack(Stack *stack) {
    printf("Stack: ");
    while (!isEmptyStack(stack))
        printf("%d ", pop(stack));
    printf("\n");
}

void initQueue(Queue *queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

int isEmptyQueue(Queue *queue) {
    return (queue->front == NULL);
}

void enqueue(Queue *queue, int data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (isEmptyQueue(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeue(Queue *queue) {
    if (isEmptyQueue(queue))
        return -1;
    Node *temp = queue->front;
    int data = temp->data;
    queue->front = temp->next;
    free(temp);
    return data;
}

void printQueue(Queue *queue) {
    printf("Queue: ");
    while (!isEmptyQueue(queue))
        printf("%d ", dequeue(queue));
    printf("\n");
}

int main() {
    Stack s;
    Queue q;
    initStack(&s);
    initQueue(&q);
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);
    enqueue(&q, 6);
    printStack(&s);
    printQueue(&q);
    return 0;
}