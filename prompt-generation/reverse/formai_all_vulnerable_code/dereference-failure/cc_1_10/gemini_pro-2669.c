//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: modular
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Define a node for a linked list
typedef struct node {
    int data;
    struct node *next;
} node_t;

// Define a queue
typedef struct queue {
    node_t *head;
    node_t *tail;
} queue_t;

// Initialize a queue
void queue_init(queue_t *queue) {
    queue->head = NULL;
    queue->tail = NULL;
}

// Enqueue an element
void queue_enqueue(queue_t *queue, int data) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    if (queue->tail == NULL) {
        queue->head = new_node;
        queue->tail = new_node;
    } else {
        queue->tail->next = new_node;
        queue->tail = new_node;
    }
}

// Dequeue an element
int queue_dequeue(queue_t *queue) {
    if (queue->head == NULL) {
        return -1;  // Queue is empty
    }
    int data = queue->head->data;
    node_t *tmp = queue->head;
    queue->head = queue->head->next;
    if (queue->head == NULL) {
        queue->tail = NULL;
    }
    free(tmp);
    return data;
}

// Print a queue
void queue_print(queue_t *queue) {
    node_t *current = queue->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Define a stack
typedef struct stack {
    node_t *top;
} stack_t;

// Initialize a stack
void stack_init(stack_t *stack) {
    stack->top = NULL;
}

// Push an element
void stack_push(stack_t *stack, int data) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = stack->top;
    stack->top = new_node;
}

// Pop an element
int stack_pop(stack_t *stack) {
    if (stack->top == NULL) {
        return -1;  // Stack is empty
    }
    int data = stack->top->data;
    node_t *tmp = stack->top;
    stack->top = stack->top->next;
    free(tmp);
    return data;
}

// Print a stack
void stack_print(stack_t *stack) {
    node_t *current = stack->top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Define a tree
typedef struct tree {
    int data;
    struct tree *left;
    struct tree *right;
} tree_t;

// Initialize a tree
void tree_init(tree_t *tree) {
    tree->data = 0;
    tree->left = NULL;
    tree->right = NULL;
}

// Insert an element into a tree
void tree_insert(tree_t *tree, int data) {
    if (tree->data == 0) {
        tree->data = data;
    } else if (data < tree->data) {
        if (tree->left == NULL) {
            tree_init(tree->left);
        }
        tree_insert(tree->left, data);
    } else {
        if (tree->right == NULL) {
            tree_init(tree->right);
        }
        tree_insert(tree->right, data);
    }
}

// Print a tree
void tree_print(tree_t *tree) {
    if (tree->left != NULL) {
        tree_print(tree->left);
    }
    printf("%d ", tree->data);
    if (tree->right != NULL) {
        tree_print(tree->right);
    }
}

int main() {
    // Create a queue
    queue_t queue;
    queue_init(&queue);

    // Enqueue some elements
    queue_enqueue(&queue, 1);
    queue_enqueue(&queue, 2);
    queue_enqueue(&queue, 3);

    // Print the queue
    printf("Queue: ");
    queue_print(&queue);

    // Dequeue an element
    int data = queue_dequeue(&queue);
    printf("Dequeued: %d\n", data);

    // Print the queue
    printf("Queue: ");
    queue_print(&queue);

    // Create a stack
    stack_t stack;
    stack_init(&stack);

    // Push some elements
    stack_push(&stack, 1);
    stack_push(&stack, 2);
    stack_push(&stack, 3);

    // Print the stack
    printf("Stack: ");
    stack_print(&stack);

    // Pop an element
    data = stack_pop(&stack);
    printf("Popped: %d\n", data);

    // Print the stack
    printf("Stack: ");
    stack_print(&stack);

    // Create a tree
    tree_t tree;
    tree_init(&tree);

    // Insert some elements
    tree_insert(&tree, 5);
    tree_insert(&tree, 2);
    tree_insert(&tree, 8);
    tree_insert(&tree, 1);
    tree_insert(&tree, 4);
    tree_insert(&tree, 7);
    tree_insert(&tree, 9);

    // Print the tree
    printf("Tree: ");
    tree_print(&tree);
    printf("\n");

    return 0;
}