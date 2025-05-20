//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 10

typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int key) {
    if (root == NULL) {
        root = createNode(key);
    } else if (key < root->key) {
        root->left = insertNode(root->left, key);
    } else {
        root->right = insertNode(root->right, key);
    }
    return root;
}

void printInOrder(Node* node) {
    if (node != NULL) {
        printInOrder(node->left);
        printf("%d ", node->key);
        printInOrder(node->right);
    }
}

void randomizeData(Node** root, int dataSize) {
    srand(time(NULL));
    int i;
    for (i = 0; i < dataSize; i++) {
        *root = insertNode(*root, rand() % 101);
    }
}

int main() {
    Node* root = NULL;
    int dataSize = HEIGHT * HEIGHT;

    randomizeData(&root, dataSize);

    printf("Data before in-order traversal:\n");
    printInOrder(root);

    printf("\nData after in-order traversal:\n");
    Node* temp = root;
    while (temp != NULL) {
        Node* toSwap = temp->right;
        temp->key = toSwap->key;
        toSwap->key = temp->key;
        temp = toSwap;
        temp = temp->left;
    }

    printInOrder(root);

    return 0;
}