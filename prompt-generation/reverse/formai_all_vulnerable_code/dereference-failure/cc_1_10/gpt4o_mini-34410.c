//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_NAME_LENGTH 30
#define SLEEP_TIME 200000

typedef struct Node {
    char name[MAX_NAME_LENGTH];
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

Node* createNode(const char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;
    return newNode;
}

// Stack Functions
void push(Stack* stack, const char* name) {
    Node* newNode = createNode(name);
    newNode->next = stack->top;
    stack->top = newNode;
}

void pop(Stack* stack) {
    if (stack->top) {
        Node* temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
    }
}

void displayStack(Stack* stack) {
    Node* current = stack->top;
    printf("Stack: ");
    while (current) {
        printf("[%s] ", current->name);
        current = current->next;
    }
    printf("\n");
}

// Queue Functions
void enqueue(Queue* queue, const char* name) {
    Node* newNode = createNode(name);
    if (queue->rear) {
        queue->rear->next = newNode;
    } else {
        queue->front = newNode;
    }
    queue->rear = newNode;
}

void dequeue(Queue* queue) {
    if (queue->front) {
        Node* temp = queue->front;
        queue->front = queue->front->next;
        if (!queue->front) {
            queue->rear = NULL;
        }
        free(temp);
    }
}

void displayQueue(Queue* queue) {
    Node* current = queue->front;
    printf("Queue: ");
    while (current) {
        printf("[%s] ", current->name);
        current = current->next;
    }
    printf("\n");
}

void visualizeStructures() {
    Stack stack = {NULL};
    Queue queue = {NULL};

    const char* names[] = {"Alice", "Bob", "Charlie", "Diana", "Evelyn"};
    int numNames = sizeof(names) / sizeof(names[0]);

    for (int i = 0; i < numNames; i++) {
        printf("Adding %s to Stack and Queue...\n", names[i]);
        
        push(&stack, names[i]);
        enqueue(&queue, names[i]);

        displayStack(&stack);
        displayQueue(&queue);
        
        // Shape shifting effect
        usleep(SLEEP_TIME);
        printf("\033[F\033[K"); // Clear previous line
        printf("Shape shifting function\n");
    }

    // Remove elements to visualize removal
    for (int i = 0; i < numNames; i++) {
        printf("Removing element from Stack and Queue...\n");
        
        pop(&stack);
        dequeue(&queue);
        
        displayStack(&stack);
        displayQueue(&queue);
        
        // Shape shifting effect
        usleep(SLEEP_TIME);
        printf("\033[F\033[K"); // Clear previous line
        printf("Shape shifting function\n");
    }

    // Freeing memory
    while (stack.top) {
        pop(&stack);
    }
    while (queue.front) {
        dequeue(&queue);
    }
}

int main() {
    printf("Welcome to Data Structures Visualization!\n");
    visualizeStructures();
    printf("Visualization complete. Goodbye!\n");
    return 0;
}