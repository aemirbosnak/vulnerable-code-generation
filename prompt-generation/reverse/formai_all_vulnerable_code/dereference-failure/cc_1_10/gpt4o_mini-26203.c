//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: introspective
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

// Stack Functions
void push(Stack* stack, int data) {
    Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack Underflow!\n");
        return -1;  // Indicating error
    }
    Node* temp = stack->top;
    int poppedValue = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return poppedValue;
}

void displayStack(Stack* stack) {
    Node* current = stack->top;
    printf("Stack elements: ");
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Queue Functions
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
        printf("Queue Underflow!\n");
        return -1;  // Indicating error
    }
    Node* temp = queue->front;
    int dequeuedValue = temp->data;
    queue->front = queue->front->next;

    if (queue->front == NULL)
        queue->rear = NULL; // If the queue is empty

    free(temp);
    return dequeuedValue;
}

void displayQueue(Queue* queue) {
    Node* current = queue->front;
    printf("Queue elements: ");
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Test program to visualize Data Structures
int main() {
    Stack* stack = createStack();
    Queue* queue = createQueue();

    int choice, value;

    while (1) {
        printf("\n--- Data Structure Visualization ---\n");
        printf("1. Push to Stack\n");
        printf("2. Pop from Stack\n");
        printf("3. Display Stack\n");
        printf("4. Enqueue to Queue\n");
        printf("5. Dequeue from Queue\n");
        printf("6. Display Queue\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(stack, value);
                break;
            case 2:
                value = pop(stack);
                if (value != -1) {
                    printf("Popped from Stack: %d\n", value);
                }
                break;
            case 3:
                displayStack(stack);
                break;
            case 4:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(queue, value);
                break;
            case 5:
                value = dequeue(queue);
                if (value != -1) {
                    printf("Dequeued from Queue: %d\n", value);
                }
                break;
            case 6:
                displayQueue(queue);
                break;
            case 7:
                free(stack);
                free(queue);
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}