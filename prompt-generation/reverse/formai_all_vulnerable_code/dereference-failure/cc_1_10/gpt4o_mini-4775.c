//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

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

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Stack functions
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

void push(Stack* stack, int data) {
    Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack Underflow\n");
        return -1; 
    }
    Node* temp = stack->top;
    int popped = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return popped;
}

void displayStack(Stack* stack) {
    Node* current = stack->top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Queue functions
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

void enqueue(Queue* queue, int data) {
    Node* newNode = createNode(data);
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
}

int dequeue(Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue Underflow\n");
        return -1; 
    }
    Node* temp = queue->front;
    int dequeued = temp->data;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return dequeued;
}

void displayQueue(Queue* queue) {
    Node* current = queue->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Stack* stack = createStack();
    Queue* queue = createQueue();
    int choice, value;

    while (1) {
        printf("1. Stack Operations\n");
        printf("2. Queue Operations\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("1. Push on Stack\n");
                printf("2. Pop from Stack\n");
                printf("3. Display Stack\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);
                if (choice == 1) {
                    printf("Enter value to push: ");
                    scanf("%d", &value);
                    push(stack, value);
                } else if (choice == 2) {
                    printf("Popped value: %d\n", pop(stack));
                } else if (choice == 3) {
                    printf("Stack: ");
                    displayStack(stack);
                }
                break;

            case 2:
                printf("1. Enqueue\n");
                printf("2. Dequeue\n");
                printf("3. Display Queue\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);
                if (choice == 1) {
                    printf("Enter value to enqueue: ");
                    scanf("%d", &value);
                    enqueue(queue, value);
                } else if (choice == 2) {
                    printf("Dequeued value: %d\n", dequeue(queue));
                } else if (choice == 3) {
                    printf("Queue: ");
                    displayQueue(queue);
                }
                break;

            case 3:
                printf("Exiting...\n");
                free(stack);
                free(queue);
                return 0;

            default:
                printf("Invalid choice\n");
        }
        printf("\n");
    }
}