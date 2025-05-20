//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Tree node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Stack node
struct StackNode {
    struct Node *node;
    struct StackNode *next;
};

// Queue node
struct QueueNode {
    struct Node *node;
    struct QueueNode *next;
};

// Stack
struct Stack {
    struct StackNode *top;
};

// Queue
struct Queue {
    struct QueueNode *front;
    struct QueueNode *rear;
};

// Create a new node
struct Node *createNode(int data) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Create a new stack node
struct StackNode *createStackNode(struct Node *node) {
    struct StackNode *stackNode = (struct StackNode *)malloc(sizeof(struct StackNode));
    stackNode->node = node;
    stackNode->next = NULL;
    return stackNode;
}

// Create a new queue node
struct QueueNode *createQueueNode(struct Node *node) {
    struct QueueNode *queueNode = (struct QueueNode *)malloc(sizeof(struct QueueNode));
    queueNode->node = node;
    queueNode->next = NULL;
    return queueNode;
}

// Create a new stack
struct Stack *createStack() {
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

// Create a new queue
struct Queue *createQueue() {
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Push a node onto the stack
void push(struct Stack *stack, struct Node *node) {
    struct StackNode *stackNode = createStackNode(node);
    stackNode->next = stack->top;
    stack->top = stackNode;
}

// Pop a node from the stack
struct Node *pop(struct Stack *stack) {
    if (stack->top == NULL) {
        return NULL;
    }
    struct StackNode *stackNode = stack->top;
    stack->top = stackNode->next;
    struct Node *node = stackNode->node;
    free(stackNode);
    return node;
}

// Enqueue a node onto the queue
void enqueue(struct Queue *queue, struct Node *node) {
    struct QueueNode *queueNode = createQueueNode(node);
    if (queue->rear == NULL) {
        queue->front = queueNode;
        queue->rear = queueNode;
        return;
    }
    queue->rear->next = queueNode;
    queue->rear = queueNode;
}

// Dequeue a node from the queue
struct Node *dequeue(struct Queue *queue) {
    if (queue->front == NULL) {
        return NULL;
    }
    struct QueueNode *queueNode = queue->front;
    queue->front = queueNode->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    struct Node *node = queueNode->node;
    free(queueNode);
    return node;
}

// Perform a preorder traversal of the tree
void preorder(struct Node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Perform an inorder traversal of the tree
void inorder(struct Node *root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Perform a postorder traversal of the tree
void postorder(struct Node *root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// Perform a level-order traversal of the tree
void levelorder(struct Node *root) {
    if (root == NULL) {
        return;
    }
    struct Queue *queue = createQueue();
    enqueue(queue, root);
    while (queue->front != NULL) {
        struct Node *node = dequeue(queue);
        printf("%d ", node->data);
        if (node->left != NULL) {
            enqueue(queue, node->left);
        }
        if (node->right != NULL) {
            enqueue(queue, node->right);
        }
    }
}

// Print a tree in a visually appealing way
void printTree(struct Node *root, int level) {
    if (root == NULL) {
        return;
    }
    for (int i = 0; i < level; i++) {
        printf("    ");
    }
    printf("%d\n", root->data);
    printTree(root->left, level + 1);
    printTree(root->right, level + 1);
}

// Main function
int main() {
    // Create a binary tree
    struct Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    // Print the tree in a visually appealing way
    printTree(root, 0);

    // Perform a preorder traversal of the tree
    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");

    // Perform an inorder traversal of the tree
    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    // Perform a postorder traversal of the tree
    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");

    // Perform a level-order traversal of the tree
    printf("Level-order traversal: ");
    levelorder(root);
    printf("\n");

    return 0;
}