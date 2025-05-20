//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

typedef struct stack {
    node_t *top;
    int size;
} stack_t;

typedef struct queue {
    node_t *front;
    node_t *rear;
    int size;
} queue_t;

node_t *create_node(int data) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

stack_t *create_stack() {
    stack_t *new_stack = (stack_t *)malloc(sizeof(stack_t));
    new_stack->top = NULL;
    new_stack->size = 0;
    return new_stack;
}

queue_t *create_queue() {
    queue_t *new_queue = (queue_t *)malloc(sizeof(queue_t));
    new_queue->front = NULL;
    new_queue->rear = NULL;
    new_queue->size = 0;
    return new_queue;
}

void push(stack_t *stack, int data) {
    node_t *new_node = create_node(data);
    if (stack->top == NULL) {
        stack->top = new_node;
    } else {
        new_node->next = stack->top;
        stack->top = new_node;
    }
    stack->size++;
}

int pop(stack_t *stack) {
    if (stack->top == NULL) {
        return -1;
    } else {
        int data = stack->top->data;
        node_t *temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
        stack->size--;
        return data;
    }
}

void enqueue(queue_t *queue, int data) {
    node_t *new_node = create_node(data);
    if (queue->front == NULL) {
        queue->front = new_node;
        queue->rear = new_node;
    } else {
        queue->rear->next = new_node;
        queue->rear = new_node;
    }
    queue->size++;
}

int dequeue(queue_t *queue) {
    if (queue->front == NULL) {
        return -1;
    } else {
        int data = queue->front->data;
        node_t *temp = queue->front;
        queue->front = queue->front->next;
        free(temp);
        queue->size--;
        return data;
    }
}

void print_stack(stack_t *stack) {
    node_t *temp = stack->top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void print_queue(queue_t *queue) {
    node_t *temp = queue->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    stack_t *stack = create_stack();
    queue_t *queue = create_queue();

    // Enqueue and dequeue elements in the queue
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    printf("Queue: ");
    print_queue(queue);

    dequeue(queue);
    printf("Queue: ");
    print_queue(queue);

    // Push and pop elements in the stack
    push(stack, 4);
    push(stack, 5);
    push(stack, 6);
    printf("Stack: ");
    print_stack(stack);

    pop(stack);
    printf("Stack: ");
    print_stack(stack);

    return 0;
}