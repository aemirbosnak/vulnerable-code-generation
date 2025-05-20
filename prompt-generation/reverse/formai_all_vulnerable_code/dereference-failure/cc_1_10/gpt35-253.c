//FormAI DATASET v1.0 Category: Data structures visualization ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_HEAP_SIZE 100
#define MAX_TREE_HEIGHT 6

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct Queue {
    Node *data[MAX_HEAP_SIZE];
    int frontIndex, rearIndex;
} Queue;

typedef struct BST {
    Node *root;
} BST;

Queue *createQueue(void) {
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    queue->frontIndex = -1;
    queue->rearIndex = -1;
    return queue;
}

int isQueueEmpty(Queue *queue) {
    return (queue->frontIndex == -1 || queue->frontIndex > queue->rearIndex);
}

int isQueueFull(Queue *queue) {
    return (queue->rearIndex == MAX_HEAP_SIZE - 1);
}

void enqueue(Queue *queue, Node *data) {
    if (!isQueueFull(queue)) {
        if (isQueueEmpty(queue)) {
            queue->frontIndex = 0;
        }
        queue->rearIndex++;
        queue->data[queue->rearIndex] = data;
    }
}

Node *dequeue(Queue *queue) {
    if (!isQueueEmpty(queue)) {
        Node *data = queue->data[queue->frontIndex];
        queue->frontIndex++;
        return data;
    }
    return NULL;
}

Node *createNode(int data) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

BST *createBST(void) {
    BST *bst = (BST *) malloc(sizeof(BST));
    bst->root = NULL;
    return bst;
}

Node *searchBST(Node *root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return searchBST(root->left, data);
    } else {
        return searchBST(root->right, data);
    }
}

Node *findMinimum(Node *root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

Node *insertBST(Node *root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return root;
    }
    if (data < root->data) {
        root->left = insertBST(root->left, data);
    } else {
        root->right = insertBST(root->right, data);
    }
    return root;
}

Node *deleteBST(Node *root, int data) {
    if (root == NULL) {
        return root;
    }
    if (data < root->data) {
        root->left = deleteBST(root->left, data);
    } else if (data > root->data) {
        root->right = deleteBST(root->right, data);
    } else {
        if (root->left == NULL) {
            Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        Node *temp = findMinimum(root->right);
        root->data = temp->data;
        root->right = deleteBST(root->right, temp->data);
    }
    return root;
}

void levelOrderTraversal(Node *root) {
    Queue *queue = createQueue();
    if (root != NULL) {
        enqueue(queue, root);
    }
    while (!isQueueEmpty(queue)) {
        Node *node = dequeue(queue);
        printf("%d ", node->data);
        if (node->left != NULL) {
            enqueue(queue, node->left);
        }
        if (node->right != NULL) {
            enqueue(queue, node->right);
        }
    }
}

void printTree(int spaces, int height, Node *root) {
    if (height <= MAX_TREE_HEIGHT) {
        if (root != NULL) {
            printTree(spaces + 4, height + 1, root->right);
            for (int i = 0; i < spaces; i++) {
                printf(" ");
            }
            printf("%d\n", root->data);
            printTree(spaces + 4, height + 1, root->left);
        } else {
            for (int i = 0; i < spaces; i++) {
                printf(" ");
            }
            printf(".\n");
        }
    }
}

int main() {
    srand(time(NULL));

    BST *bst = createBST();

    for (int i = 0; i < 15; i++) {

        int value = (rand() % 40) + 1;

        Node *node = createNode(value);

        if (bst->root == NULL) {
            bst->root = node;
        } else {
            insertBST(bst->root, value);
        }

        printf("Inserting node with value %d:\n", value);
        printTree(0, 1, bst->root);
    }

    for (int i = 0; i < 4; i++) {

        int value = (rand() % 40) + 1;

        Node *node = searchBST(bst->root, value);

        if (node != NULL) {
            bst->root = deleteBST(bst->root, value);
        }

        printf("Deleting node with value %d:\n", value);
        printTree(0, 1, bst->root);
    }

    printf("Level Order Traversal:\n");
    levelOrderTraversal(bst->root);

    return 0;
}