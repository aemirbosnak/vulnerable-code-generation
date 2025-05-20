//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct QueueNode {
    Node* treeNode;
    struct QueueNode* next;
} QueueNode;

typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
} Queue;

// Function prototypes
Node* createNode(int data);
void insert(Node** root, int data);
void levelOrderTraversal(Node* root);
void enqueue(Queue* q, Node* treeNode);
Node* dequeue(Queue* q);
bool isQueueEmpty(Queue* q);
void freeTree(Node* root);

int main() {
    Node* root = NULL;
    int elements[] = {10, 6, 15, 4, 8, 12, 20};
    
    // Insert elements into the Binary Search Tree
    for (int i = 0; i < sizeof(elements)/sizeof(elements[0]); i++) {
        insert(&root, elements[i]);
    }
    
    printf("Level-order Traversal of the Binary Search Tree:\n");
    levelOrderTraversal(root);
    
    // Free allocated memory
    freeTree(root);
    return 0;
}

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void insert(Node** root, int data) {
    if (*root == NULL) {
        *root = createNode(data);
        return;
    }
    if (data < (*root)->data) {
        insert(&((*root)->left), data);
    } else {
        insert(&((*root)->right), data);
    }
}

void levelOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    Queue q = {NULL, NULL};
    enqueue(&q, root);
    
    while (!isQueueEmpty(&q)) {
        Node* current = dequeue(&q);
        printf("%d ", current->data);
        
        if (current->left != NULL) {
            enqueue(&q, current->left);
        }
        if (current->right != NULL) {
            enqueue(&q, current->right);
        }
    }
    printf("\n");
}

void enqueue(Queue* q, Node* treeNode) {
    QueueNode* newQueueNode = (QueueNode*)malloc(sizeof(QueueNode));
    newQueueNode->treeNode = treeNode;
    newQueueNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newQueueNode;
    } else {
        q->rear->next = newQueueNode;
        q->rear = newQueueNode;
    }
}

Node* dequeue(Queue* q) {
    if (isQueueEmpty(q)) {
        return NULL;
    }
    
    QueueNode* temp = q->front;
    Node* treeNode = temp->treeNode;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return treeNode;
}

bool isQueueEmpty(Queue* q) {
    return q->front == NULL;
}

void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}