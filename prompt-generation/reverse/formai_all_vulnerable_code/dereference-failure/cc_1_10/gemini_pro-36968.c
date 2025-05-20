//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the node structure for the linked list
typedef struct node {
    int data;
    struct node *next;
} node_t;

// Define the stack structure
typedef struct stack {
    node_t *top;
    int size;
} stack_t;

// Define the queue structure
typedef struct queue {
    node_t *front;
    node_t *rear;
    int size;
} queue_t;

// Create a new node
node_t *create_node(int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (new_node == NULL) {
        printf("Error: Could not allocate memory for new node.\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Push an element onto the stack
void push(stack_t *stack, int data) {
    node_t *new_node = create_node(data);
    new_node->next = stack->top;
    stack->top = new_node;
    stack->size++;
}

// Pop an element from the stack
int pop(stack_t *stack) {
    if (stack->top == NULL) {
        printf("Error: Stack is empty.\n");
        exit(1);
    }
    node_t *temp = stack->top;
    int data = temp->data;
    stack->top = stack->top->next;
    free(temp);
    stack->size--;
    return data;
}

// Enqueue an element into the queue
void enqueue(queue_t *queue, int data) {
    node_t *new_node = create_node(data);
    if (queue->rear == NULL) {
        queue->front = new_node;
        queue->rear = new_node;
    } else {
        queue->rear->next = new_node;
        queue->rear = new_node;
    }
    queue->size++;
}

// Dequeue an element from the queue
int dequeue(queue_t *queue) {
    if (queue->front == NULL) {
        printf("Error: Queue is empty.\n");
        exit(1);
    }
    node_t *temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    queue->size--;
    return data;
}

// Print the elements of the linked list
void print_linked_list(node_t *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Print the elements of the stack
void print_stack(stack_t *stack) {
    node_t *temp = stack->top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Print the elements of the queue
void print_queue(queue_t *queue) {
    node_t *temp = queue->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    // Create a new stack
    stack_t stack;
    stack.top = NULL;
    stack.size = 0;

    // Push elements onto the stack
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    // Print the elements of the stack
    printf("Stack: ");
    print_stack(&stack);

    // Pop an element from the stack
    int popped_element = pop(&stack);
    printf("Popped element: %d\n", popped_element);

    // Print the elements of the stack
    printf("Stack: ");
    print_stack(&stack);

    // Create a new queue
    queue_t queue;
    queue.front = NULL;
    queue.rear = NULL;
    queue.size = 0;

    // Enqueue elements into the queue
    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);

    // Print the elements of the queue
    printf("Queue: ");
    print_queue(&queue);

    // Dequeue an element from the queue
    int dequeued_element = dequeue(&queue);
    printf("Dequeued element: %d\n", dequeued_element);

    // Print the elements of the queue
    printf("Queue: ");
    print_queue(&queue);

    return 0;
}