//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} Stack;

typedef struct {
    int data[MAX];
    int front, rear;
} Queue;

void initializeStack(Stack* s) {
    s->top = NULL;
}

void push(Stack* s, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
    printf("Pushed to stack: %d\n", value);
}

int pop(Stack* s) {
    if (s->top == NULL) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }
    Node* temp = s->top;
    int poppedValue = temp->data;
    s->top = s->top->next;
    free(temp);
    return poppedValue;
}

void displayStack(Stack* s) {
    Node* temp = s->top;
    printf("Stack (top to bottom): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void initializeQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isQueueFull(Queue* q) {
    return (q->rear + 1) % MAX == q->front;
}

int isQueueEmpty(Queue* q) {
    return q->front == -1;
}

void enqueue(Queue* q, int value) {
    if (isQueueFull(q)) {
        printf("Queue is full. Cannot enqueue %d.\n", value);
        return;
    }
    if (isQueueEmpty(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX;
    q->data[q->rear] = value;
    printf("Enqueued to queue: %d\n", value);
}

int dequeue(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int dequeuedValue = q->data[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1; // reset queue
    } else {
        q->front = (q->front + 1) % MAX;
    }
    return dequeuedValue;
}

void displayQueue(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    int i = q->front;
    printf("Queue (front to rear): ");
    while (1) {
        printf("%d ", q->data[i]);
        if (i == q->rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    Stack stack;
    Queue queue;
    initializeStack(&stack);
    initializeQueue(&queue);

    // Testing Stack Operations
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    displayStack(&stack);

    printf("Popped from stack: %d\n", pop(&stack));
    displayStack(&stack);

    // Testing Queue Operations
    enqueue(&queue, 100);
    enqueue(&queue, 200);
    enqueue(&queue, 300);
    displayQueue(&queue);

    printf("Dequeued from queue: %d\n", dequeue(&queue));
    displayQueue(&queue);

    return 0;
}