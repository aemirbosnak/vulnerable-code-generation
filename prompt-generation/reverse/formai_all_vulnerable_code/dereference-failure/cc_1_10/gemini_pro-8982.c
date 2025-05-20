//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct stack {
    node *top;
} stack;

typedef struct queue {
    node *front;
    node *rear;
} queue;

typedef struct tree {
    int data;
    struct tree *left;
    struct tree *right;
} tree;

void push(stack *s, int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = s->top;
    s->top = new_node;
}

int pop(stack *s) {
    if (s->top == NULL) {
        printf("Stack is empty.\n");
        return -1;
    }
    node *temp = s->top;
    s->top = s->top->next;
    int data = temp->data;
    free(temp);
    return data;
}

void enqueue(queue *q, int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    if (q->front == NULL) {
        q->front = new_node;
        q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

int dequeue(queue *q) {
    if (q->front == NULL) {
        printf("Queue is empty.\n");
        return -1;
    }
    node *temp = q->front;
    q->front = q->front->next;
    int data = temp->data;
    free(temp);
    return data;
}

void insert(tree **root, int data) {
    if (*root == NULL) {
        *root = (tree *)malloc(sizeof(tree));
        (*root)->data = data;
        (*root)->left = NULL;
        (*root)->right = NULL;
    } else if (data < (*root)->data) {
        insert(&(*root)->left, data);
    } else {
        insert(&(*root)->right, data);
    }
}

void print_tree(tree *root) {
    if (root == NULL) {
        return;
    }
    print_tree(root->left);
    printf("%d ", root->data);
    print_tree(root->right);
}

int main() {
    stack s;
    s.top = NULL;
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    printf("Stack: ");
    while (s.top != NULL) {
        printf("%d ", pop(&s));
    }
    printf("\n");

    queue q;
    q.front = NULL;
    q.rear = NULL;
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    printf("Queue: ");
    while (q.front != NULL) {
        printf("%d ", dequeue(&q));
    }
    printf("\n");

    tree *root = NULL;
    insert(&root, 10);
    insert(&root, 5);
    insert(&root, 15);
    insert(&root, 2);
    insert(&root, 7);
    insert(&root, 12);
    insert(&root, 20);
    printf("Tree: ");
    print_tree(root);
    printf("\n");

    return 0;
}