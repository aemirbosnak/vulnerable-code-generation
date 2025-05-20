//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Data Structure Declarations
typedef struct node {
    int data;
    struct node *next;
} node_t;

typedef struct queue {
    node_t *front;
    node_t *rear;
    int size;
} queue_t;

typedef struct stack {
    node_t *top;
    int size;
} stack_t;

// Function Declarations
queue_t* create_queue();
void enqueue(queue_t *queue, int data);
int dequeue(queue_t *queue);
bool is_empty_queue(queue_t *queue);

stack_t* create_stack();
void push(stack_t *stack, int data);
int pop(stack_t *stack);
bool is_empty_stack(stack_t *stack);

void visualize_queue(queue_t *queue);
void visualize_stack(stack_t *stack);

// Main Function
int main() {
    // Create a queue
    queue_t *queue = create_queue();

    // Enqueue some elements into the queue
    printf("Enqueuing elements into the queue: ");
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);
    printf("%d, %d, %d, %d, %d\n", queue->front->data, queue->front->next->data,
           queue->front->next->next->data, queue->front->next->next->next->data,
           queue->front->next->next->next->next->data);

    // Visualize the queue
    printf("\nVisualizing the queue:\n");
    visualize_queue(queue);

    // Dequeue some elements from the queue
    printf("\nDequeuing elements from the queue: ");
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    printf("%d, %d, %d\n", queue->front->data, queue->front->next->data,
           queue->front->next->next->data);

    // Visualize the queue again
    printf("\nVisualizing the queue:\n");
    visualize_queue(queue);

    // Create a stack
    stack_t *stack = create_stack();

    // Push some elements onto the stack
    printf("\nPushing elements onto the stack: ");
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    push(stack, 5);
    printf("%d, %d, %d, %d, %d\n", stack->top->data, stack->top->next->data,
           stack->top->next->next->data, stack->top->next->next->next->data,
           stack->top->next->next->next->next->data);

    // Visualize the stack
    printf("\nVisualizing the stack:\n");
    visualize_stack(stack);

    // Pop some elements from the stack
    printf("\nPopping elements from the stack: ");
    pop(stack);
    pop(stack);
    pop(stack);
    printf("%d, %d, %d\n", stack->top->data, stack->top->next->data,
           stack->top->next->next->data);

    // Visualize the stack again
    printf("\nVisualizing the stack:\n");
    visualize_stack(stack);

    return 0;
}

// Function Implementations

// Create a queue
queue_t* create_queue() {
    queue_t *queue = (queue_t*)malloc(sizeof(queue_t));
    queue->front = queue->rear = NULL;
    queue->size = 0;
    return queue;
}

// Enqueue an element into the queue
void enqueue(queue_t *queue, int data) {
    node_t *new_node = (node_t*)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;

    if (queue->rear == NULL) {
        queue->front = queue->rear = new_node;
    } else {
        queue->rear->next = new_node;
        queue->rear = new_node;
    }

    queue->size++;
}

// Dequeue an element from the queue
int dequeue(queue_t *queue) {
    if (is_empty_queue(queue)) {
        printf("Queue is empty, nothing to dequeue.\n");
        return -1;
    }

    node_t *temp = queue->front;
    int data = queue->front->data;

    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    queue->size--;

    return data;
}

// Check if the queue is empty
bool is_empty_queue(queue_t *queue) {
    return (queue->front == NULL);
}

// Create a stack
stack_t* create_stack() {
    stack_t *stack = (stack_t*)malloc(sizeof(stack_t));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

// Push an element onto the stack
void push(stack_t *stack, int data) {
    node_t *new_node = (node_t*)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = stack->top;

    stack->top = new_node;
    stack->size++;
}

// Pop an element from the stack
int pop(stack_t *stack) {
    if (is_empty_stack(stack)) {
        printf("Stack is empty, nothing to pop.\n");
        return -1;
    }

    node_t *temp = stack->top;
    int data = stack->top->data;

    stack->top = stack->top->next;
    free(temp);
    stack->size--;

    return data;
}

// Check if the stack is empty
bool is_empty_stack(stack_t *stack) {
    return (stack->top == NULL);
}

// Visualize the queue
void visualize_queue(queue_t *queue) {
    node_t *current = queue->front;

    printf("[ ");
    while (current != NULL) {
        printf("%d, ", current->data);
        current = current->next;
    }
    printf("]\n");
}

// Visualize the stack
void visualize_stack(stack_t *stack) {
    node_t *current = stack->top;

    printf("[ ");
    while (current != NULL) {
        printf("%d, ", current->data);
        current = current->next;
    }
    printf("]\n");
}