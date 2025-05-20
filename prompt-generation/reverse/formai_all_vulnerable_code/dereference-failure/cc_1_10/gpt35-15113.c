//FormAI DATASET v1.0 Category: Data structures visualization ; Style: invasive
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int value;
    struct node* next;
}Node;

typedef struct stack {
    Node* top;
}Stack;

typedef struct queue {
    Node* front;
    Node* rear;
}Queue;

void initializeStack(Stack* stack) {
    stack->top = NULL;
}

void initializeQueue(Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

void push(Stack* stack, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error! Out of memory.\n");
        return;
    }
    newNode->value = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

int isEmptyStack(Stack* stack) {
    return (stack->top == NULL);
}

int pop(Stack* stack) {
    if (isEmptyStack(stack)) {
        printf("Error! Stack is empty.\n");
        return -1;
    }
    Node* poppedNode = stack->top;
    int poppedValue = poppedNode->value;
    stack->top = poppedNode->next;
    free(poppedNode);
    return poppedValue;
}

void enqueue(Queue* queue, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error! Out of memory.\n");
        return;
    }
    newNode->value = value;
    newNode->next = NULL;
    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
}

int isEmptyQueue(Queue* queue) {
    return (queue->front == NULL);
}

int dequeue(Queue* queue) {
    if (isEmptyQueue(queue)) {
        printf("Error! Queue is empty.\n");
        return -1;
    }
    Node* dequeuedNode = queue->front;
    int dequeuedValue = dequeuedNode->value;
    queue->front = dequeuedNode->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(dequeuedNode);
    return dequeuedValue;
}

void printStack(Stack* stack) {
    Node* currentNode = stack->top;
    printf("Stack: ");
    while (currentNode != NULL) {
        printf("%d ", currentNode->value);
        currentNode = currentNode->next;
    }
    printf("\n");
}

void printQueue(Queue* queue) {
    Node* currentNode = queue->front;
    printf("Queue: ");
    while (currentNode != NULL) {
        printf("%d ", currentNode->value);
        currentNode = currentNode->next;
    }
    printf("\n");
}

int main() {
    Stack stack;
    Queue queue;

    initializeStack(&stack);
    initializeQueue(&queue);

    printf("Pushing 5, 10, 15 on the stack...\n");
    push(&stack, 5);
    push(&stack, 10);
    push(&stack, 15);

    printf("Enqueuing 20, 25, 30...\n");
    enqueue(&queue, 20);
    enqueue(&queue, 25);
    enqueue(&queue, 30);

    printStack(&stack);
    printQueue(&queue);

    printf("Popping top of stack: %d\n", pop(&stack));
    printf("Dequeuing front of queue: %d\n", dequeue(&queue));

    printStack(&stack);
    printQueue(&queue);

    return 0;
}