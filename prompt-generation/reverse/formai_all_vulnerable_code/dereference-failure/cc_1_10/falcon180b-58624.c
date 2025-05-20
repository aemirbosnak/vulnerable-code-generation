//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct stack {
    Node* top;
} Stack;

typedef struct queue {
    Node* front;
    Node* rear;
} Queue;

typedef struct tree {
    int data;
    struct tree* left;
    struct tree* right;
} Tree;

Stack* createStack() {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    if (stack == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    stack->top = NULL;
    return stack;
}

void push(Stack* stack, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty\n");
        exit(1);
    }
    int data = stack->top->data;
    Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

Queue* createQueue() {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    if (queue == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

void enqueue(Queue* queue, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    newNode->data = data;
    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeue(Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty\n");
        exit(1);
    }
    int data = queue->front->data;
    Node* temp = queue->front;
    if (queue->front == queue->rear) {
        queue->front = NULL;
        queue->rear = NULL;
    } else {
        queue->front = queue->front->next;
    }
    free(temp);
    return data;
}

Tree* createTree(int data) {
    Tree* tree = (Tree*) malloc(sizeof(Tree));
    if (tree == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    tree->data = data;
    tree->left = NULL;
    tree->right = NULL;
    return tree;
}

void insert(Tree* tree, int data) {
    if (tree == NULL) {
        printf("Tree is empty\n");
        exit(1);
    }
    if (data < tree->data) {
        if (tree->left == NULL) {
            tree->left = createTree(data);
        } else {
            insert(tree->left, data);
        }
    } else if (data > tree->data) {
        if (tree->right == NULL) {
            tree->right = createTree(data);
        } else {
            insert(tree->right, data);
        }
    } else {
        printf("Data already exists in the tree\n");
    }
}

void inorder(Tree* tree) {
    if (tree == NULL) {
        printf("Tree is empty\n");
        exit(1);
    }
    inorder(tree->left);
    printf("%d ", tree->data);
    inorder(tree->right);
}

int main() {
    Stack* stack = createStack();
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    printf("Stack: ");
    while (stack->top!= NULL) {
        int data = pop(stack);
        printf("%d ", data);
    }
    printf("\n");

    Queue* queue = createQueue();
    enqueue(queue, 40);
    enqueue(queue, 50);
    enqueue(queue, 60);
    printf("Queue: ");
    while (queue->front!= NULL) {
        int data = dequeue(queue);
        printf("%d ", data);
    }
    printf("\n");

    Tree* tree = createTree(15);
    insert(tree, 5);
    insert(tree, 20);
    insert(tree, 10);
    insert(tree, 25);
    inorder(tree);
    printf("\n");

    return 0;
}