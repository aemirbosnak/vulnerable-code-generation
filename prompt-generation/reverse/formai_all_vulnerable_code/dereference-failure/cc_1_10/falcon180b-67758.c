//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Node structure for Linked List
typedef struct node {
    int data;
    struct node* next;
} Node;

// Stack structure using Linked List
typedef struct stack {
    Node* top;
} Stack;

// Queue structure using Linked List
typedef struct queue {
    Node* front;
    Node* rear;
} Queue;

// Tree structure using Linked List
typedef struct tree {
    Node* root;
} Tree;

// Create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Push an element onto the stack
void push(Stack* stack, int data) {
    Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

// Pop an element from the stack
int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty\n");
        exit(0);
    }
    int data = stack->top->data;
    Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

// Enqueue an element into the queue
void enqueue(Queue* queue, int data) {
    Node* newNode = createNode(data);
    if (queue->front == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Dequeue an element from the queue
int dequeue(Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty\n");
        exit(0);
    }
    int data = queue->front->data;
    Node* temp = queue->front;
    queue->front = queue->front->next;
    free(temp);
    return data;
}

// Insert a node into the tree
void insert(Tree* tree, int data) {
    Node* newNode = createNode(data);
    if (tree->root == NULL) {
        tree->root = newNode;
    } else {
        Node* current = tree->root;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Traverse the tree in pre-order fashion
void preOrder(Node* node) {
    if (node!= NULL) {
        printf("%d ", node->data);
        preOrder(node->next);
    }
}

int main() {
    // Test Stack operations
    Stack stack;
    stack.top = NULL;
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    printf("Stack elements: ");
    while (stack.top!= NULL) {
        printf("%d ", pop(&stack));
    }
    printf("\n");

    // Test Queue operations
    Queue queue;
    queue.front = NULL;
    queue.rear = NULL;
    enqueue(&queue, 40);
    enqueue(&queue, 50);
    enqueue(&queue, 60);
    printf("Queue elements: ");
    while (queue.front!= NULL) {
        printf("%d ", dequeue(&queue));
    }
    printf("\n");

    // Test Tree operations
    Tree tree;
    tree.root = NULL;
    insert(&tree, 70);
    insert(&tree, 80);
    insert(&tree, 90);
    printf("Tree elements in pre-order traversal: ");
    preOrder(tree.root);
    printf("\n");

    return 0;
}