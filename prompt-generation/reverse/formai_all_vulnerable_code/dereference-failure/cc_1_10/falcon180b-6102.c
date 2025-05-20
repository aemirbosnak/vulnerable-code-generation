//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Linked List Node
typedef struct node {
    char data;
    struct node* next;
} Node;

// Stack Data Structure
typedef struct stack {
    Node* top;
} Stack;

// Queue Data Structure
typedef struct queue {
    Node* front;
    Node* rear;
} Queue;

// Initialize an empty stack
void init_stack(Stack* s) {
    s->top = NULL;
}

// Push an element onto the stack
void push_stack(Stack* s, char element) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = element;
    new_node->next = s->top;
    s->top = new_node;
}

// Pop an element from the stack
char pop_stack(Stack* s) {
    char element = s->top->data;
    Node* temp = s->top;
    s->top = s->top->next;
    free(temp);
    return element;
}

// Initialize an empty queue
void init_queue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

// Enqueue an element into the queue
void enqueue_queue(Queue* q, char element) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = element;
    new_node->next = NULL;
    if (q->rear == NULL) {
        q->front = new_node;
        q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

// Dequeue an element from the queue
char dequeue_queue(Queue* q) {
    char element = q->front->data;
    Node* temp = q->front;
    q->front = q->front->next;
    free(temp);
    return element;
}

// Main function
int main() {
    Stack s;
    init_stack(&s);
    push_stack(&s, 'a');
    push_stack(&s, 'b');
    push_stack(&s, 'c');
    push_stack(&s, 'd');
    char popped_element = pop_stack(&s);
    printf("Popped element: %c\n", popped_element);

    Queue q;
    init_queue(&q);
    enqueue_queue(&q, 'e');
    enqueue_queue(&q, 'f');
    enqueue_queue(&q, 'g');
    char dequeued_element = dequeue_queue(&q);
    printf("Dequeued element: %c\n", dequeued_element);

    return 0;
}