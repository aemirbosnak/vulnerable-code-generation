//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(Stack* stack, int data) {
    Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
    printf("Pushed %d to stack\n", data);
}

int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack underflow\n");
        return -1;
    }
    Node* temp = stack->top;
    stack->top = stack->top->next;
    int popped = temp->data;
    free(temp);
    printf("Popped %d from stack\n", popped);
    return popped;
}

void enqueue(Queue* queue, int data) {
    Node* newNode = createNode(data);
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        printf("Enqueued %d to queue\n", data);
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
    printf("Enqueued %d to queue\n", data);
}

int dequeue(Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue underflow\n");
        return -1;
    }
    Node* temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    int dequeued = temp->data;
    free(temp);
    printf("Dequeued %d from queue\n", dequeued);
    return dequeued;
}

void displayStack(Stack* stack) {
    Node* current = stack->top;
    printf("Stack contents: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void displayQueue(Queue* queue) {
    Node* current = queue->front;
    printf("Queue contents: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Stack* stack = createStack();
    Queue* queue = createQueue();

    // Push elements to the stack
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    displayStack(stack);

    // Pop an element from the stack
    pop(stack);
    displayStack(stack);

    // Enqueue elements to the queue
    enqueue(queue, 5);
    enqueue(queue, 15);
    enqueue(queue, 25);
    displayQueue(queue);

    // Dequeue an element from the queue
    dequeue(queue);
    displayQueue(queue);

    // Clean up
    while (pop(stack) != -1); // Pop all from stack
    free(stack);
    while (dequeue(queue) != -1); // Dequeue all from queue
    free(queue);

    return 0;
}