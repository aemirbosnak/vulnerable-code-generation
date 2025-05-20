//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

typedef struct stack {
    node_t *top;
} stack_t;

typedef struct queue {
    node_t *front;
    node_t *rear;
} queue_t;

typedef struct binary_tree {
    int data;
    struct binary_tree *left;
    struct binary_tree *right;
} binary_tree_t;

void push(stack_t *stack, int data) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = stack->top;
    stack->top = new_node;
}

int pop(stack_t *stack) {
    if (stack->top == NULL) {
        printf("Stack is empty.\n");
        return -1;
    }

    node_t *temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);

    return data;
}

void enqueue(queue_t *queue, int data) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;

    if (queue->rear == NULL) {
        queue->front = new_node;
        queue->rear = new_node;
    } else {
        queue->rear->next = new_node;
        queue->rear = new_node;
    }
}

int dequeue(queue_t *queue) {
    if (queue->front == NULL) {
        printf("Queue is empty.\n");
        return -1;
    }

    node_t *temp = queue->front;
    int data = temp->data;
    queue->front = temp->next;
    free(temp);

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    return data;
}

binary_tree_t *create_binary_tree(int data) {
    binary_tree_t *new_node = malloc(sizeof(binary_tree_t));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

void insert_into_binary_tree(binary_tree_t *root, int data) {
    if (data < root->data) {
        if (root->left == NULL) {
            root->left = create_binary_tree(data);
        } else {
            insert_into_binary_tree(root->left, data);
        }
    } else {
        if (root->right == NULL) {
            root->right = create_binary_tree(data);
        } else {
            insert_into_binary_tree(root->right, data);
        }
    }
}

void preorder_traversal(binary_tree_t *root) {
    if (root == NULL) {
        return;
    }

    printf("%d ", root->data);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

void inorder_traversal(binary_tree_t *root) {
    if (root == NULL) {
        return;
    }

    inorder_traversal(root->left);
    printf("%d ", root->data);
    inorder_traversal(root->right);
}

void postorder_traversal(binary_tree_t *root) {
    if (root == NULL) {
        return;
    }

    postorder_traversal(root->left);
    postorder_traversal(root->right);
    printf("%d ", root->data);
}

int main() {
    // Create a stack
    stack_t stack;
    stack.top = NULL;

    // Push some elements onto the stack
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    // Pop an element from the stack
    int popped_element = pop(&stack);
    printf("Popped element: %d\n", popped_element);

    // Create a queue
    queue_t queue;
    queue.front = NULL;
    queue.rear = NULL;

    // Enqueue some elements into the queue
    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);

    // Dequeue an element from the queue
    int dequeued_element = dequeue(&queue);
    printf("Dequeued element: %d\n", dequeued_element);

    // Create a binary tree
    binary_tree_t *root = create_binary_tree(10);
    insert_into_binary_tree(root, 5);
    insert_into_binary_tree(root, 15);
    insert_into_binary_tree(root, 2);
    insert_into_binary_tree(root, 7);
    insert_into_binary_tree(root, 12);
    insert_into_binary_tree(root, 20);

    // Preorder traversal of the binary tree
    printf("Preorder traversal:");
    preorder_traversal(root);
    printf("\n");

    // Inorder traversal of the binary tree
    printf("Inorder traversal:");
    inorder_traversal(root);
    printf("\n");

    // Postorder traversal of the binary tree
    printf("Postorder traversal:");
    postorder_traversal(root);
    printf("\n");

    return 0;
}