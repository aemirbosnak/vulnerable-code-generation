//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    char key[21];
    int height;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(char key[]) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    strcpy(newNode->key, key);
    newNode->height = 0;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int height(Node* N) {
    if (N == NULL)
        return -1;
    return N->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int calcHeight(Node* N) {
    int leftHeight = height(N->left);
    int rightHeight = height(N->right);

    if (leftHeight > rightHeight)
        return leftHeight + 1;
    else
        return rightHeight + 1;
}

void updateHeight(Node* N) {
    N->height = max(height(N->left), height(N->right)) + 1;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

Node* insert(Node* node, char key[]) {
    if (node == NULL) {
        Node* newNode = createNode(key);
        return newNode;
    }

    if (strcmp(key, node->key) < 0)
        node->left = insert(node->left, key);
    else if (strcmp(key, node->key) > 0)
        node->right = insert(node->right, key);

    updateHeight(node);

    int balance = calcHeight(node->left) - calcHeight(node->right);

    if (balance > 1) {
        if (calcHeight(node->left->left) >= calcHeight(node->left->right))
            node->left = rightRotate(node->left);
        node = leftRotate(node);
    }

    return node;
}

void printInOrder(Node* node) {
    if (node != NULL) {
        printInOrder(node->left);
        printf("%s ", node->key);
        printInOrder(node->right);
    }
}

void destroy(Node* node) {
    if (node != NULL) {
        destroy(node->left);
        destroy(node->right);
        free(node);
    }
}

int main() {
    Node* root = NULL;

    char keys[30][21] = {
        "apple", "banana", "cherry", "date", "fig",
        "grape", "kiwi", "lemon", "mango", "orange",
        "peach", "pear", "pineapple", "quince", "strawberry",
        "tangerine", "watermelon", "zucchini", "apricot", "blueberry"
    };

    int i;

    for (i = 0; i < 22; i++)
        root = insert(root, keys[i]);

    printf("Inorder traversal: ");
    printInOrder(root);
    printf("\n");

    destroy(root);

    return 0;
}