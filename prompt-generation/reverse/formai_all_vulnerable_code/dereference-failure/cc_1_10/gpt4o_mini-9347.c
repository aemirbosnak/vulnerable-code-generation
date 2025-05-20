//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Stack {
    int items[MAX];
    int top;
} Stack;

typedef struct Queue {
    int items[MAX];
    int front, rear;
} Queue;

Stack stack;
Queue queue;
Node* head = NULL;

void initStack() {
    stack.top = -1;
}

int isFull(Stack* s) {
    return s->top == MAX - 1;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, int value) {
    if (!isFull(s)) {
        s->items[++(s->top)] = value;
    } else {
        printf("Stack Overflow!\n");
    }
}

int pop(Stack* s) {
    if (!isEmpty(s)) {
        return s->items[(s->top)--];
    } else {
        printf("Stack Underflow!\n");
        return -1;
    }
}

void enqueue(Queue* q, int value) {
    if ((q->rear + 1) % MAX == q->front) {
        printf("Queue Overflow!\n");
    } else {
        q->rear = (q->rear + 1) % MAX;
        q->items[q->rear] = value;
    }
}

int dequeue(Queue* q) {
    if (q->front == q->rear) {
        printf("Queue Underflow!\n");
        return -1;
    } else {
        q->front = (q->front + 1) % MAX;
        return q->items[q->front];
    }
}

void insertAtBeginning(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void displayLinkedList() {
    Node* current = head;
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void displayStack() {
    printf("Stack: ");
    for (int i = stack.top; i >= 0; i--) {
        printf("| %d |\n", stack.items[i]);
    }
}

void displayQueue() {
    printf("Queue: ");
    for (int i = (queue.front + 1) % MAX; i != (queue.rear + 1) % MAX; i = (i + 1) % MAX) {
        printf("| %d |\n", queue.items[i]);
    }
}

void shapeShiftVisualization() {
    int choice, value;
    while (1) {
        printf("\nChoose a data structure (1: Stack, 2: Queue, 3: Linked List, 0: Exit): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to push onto the stack: ");
                scanf("%d", &value);
                push(&stack, value);
                displayStack();
                break;
            case 2:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&queue, value);
                displayQueue();
                break;
            case 3:
                printf("Enter value to insert into linked list: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                displayLinkedList();
                break;
            case 0:
                printf("Exiting...\n");
                return;
            default:
                printf("Invalid choice!\n");
        }
    }
}

int main() {
    initStack();
    queue.front = queue.rear = 0;
    shapeShiftVisualization();
    return 0;
}