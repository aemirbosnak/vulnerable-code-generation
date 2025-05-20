//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define ERROR -1

typedef struct {
    int data[MAX];
    int front;
    int rear;
} Queue;

typedef struct {
    int data[MAX];
    int top;
} Stack;

// Function prototypes
Queue* createQueue();
int enqueue(Queue* queue, int value);
int dequeue(Queue* queue);
void displayQueue(Queue* queue);

Stack* createStack();
int push(Stack* stack, int value);
int pop(Stack* stack);
void displayStack(Stack* stack);

void visualizeQueue(Queue* queue);
void visualizeStack(Stack* stack);

int main() {
    Queue* queue = createQueue();
    Stack* stack = createStack();
    int choice, value;

    while (1) {
        printf("\nData Structures Visualization\n");
        printf("1. Enqueue to Queue\n");
        printf("2. Dequeue from Queue\n");
        printf("3. Push to Stack\n");
        printf("4. Pop from Stack\n");
        printf("5. Visualize Queue\n");
        printf("6. Visualize Stack\n");
        printf("7. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(queue, value);
                break;

            case 2:
                value = dequeue(queue);
                if (value != ERROR) {
                    printf("Dequeued value: %d\n", value);
                }
                break;

            case 3:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(stack, value);
                break;

            case 4:
                value = pop(stack);
                if (value != ERROR) {
                    printf("Popped value: %d\n", value);
                }
                break;

            case 5:
                visualizeQueue(queue);
                break;

            case 6:
                visualizeStack(stack);
                break;

            case 7:
                free(queue);
                free(stack);
                exit(0);

            default:
                printf("Invalid option! Please try again.\n");
        }
    }
    
    return 0;
}

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

int enqueue(Queue* queue, int value) {
    if ((queue->rear + 1) % MAX == queue->front) {
        printf("Queue is full!\n");
        return ERROR;
    }
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % MAX;
    queue->data[queue->rear] = value;
    return 0;
}

int dequeue(Queue* queue) {
    if (queue->front == -1) {
        printf("Queue is empty!\n");
        return ERROR;
    }
    int value = queue->data[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1; // Queue is empty
    } else {
        queue->front = (queue->front + 1) % MAX;
    }
    return value;
}

void displayQueue(Queue* queue) {
    if (queue->front == -1) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue: ");
    for (int i = queue->front; i != queue->rear + 1; i = (i + 1) % MAX) {
        printf("%d ", queue->data[i]);
    }
    printf("\n");
}

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}

int push(Stack* stack, int value) {
    if (stack->top == MAX - 1) {
        printf("Stack is full!\n");
        return ERROR;
    }
    stack->data[++stack->top] = value;
    return 0;
}

int pop(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack is empty!\n");
        return ERROR;
    }
    return stack->data[stack->top--];
}

void displayStack(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

void visualizeQueue(Queue* queue) {
    printf("Visualizing Queue:\n");
    for (int i = 0; i < MAX; i++) {
        if (i == queue->front) {
            printf("[F] ");  // Front of Queue
        }
        if (i == queue->rear) {
            printf("[R] ");  // Rear of Queue
        }
        if (i == queue->front || (queue->front != -1 && (i >= queue->front && i <= queue->rear))) {
            printf("%d ", queue->data[i]);
        } else {
            printf(" - ");
        }
    }
    printf("\n");
}

void visualizeStack(Stack* stack) {
    printf("Visualizing Stack:\n");
    for (int i = MAX - 1; i >= 0; i--) {
        if (i == stack->top) {
            printf("[T] ");  // Top of Stack
        }
        if (i <= stack->top) {
            printf("%d ", stack->data[i]);
        } else {
            printf(" - ");
        }
    }
    printf("\n");
}