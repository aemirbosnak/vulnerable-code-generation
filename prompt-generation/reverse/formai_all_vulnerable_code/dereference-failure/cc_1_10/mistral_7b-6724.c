//MISTRAL-7B DATASET v1.0 Category: Bitwise operations ; Style: thoughtful
#include <stdio.h>
#include <stdint.h>

typedef struct Node {
    uint32_t data;
    struct Node *left;
    struct Node *right;
} Node;

Node* newNode(uint32_t data) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

uint32_t sumBits(uint32_t num) {
    int count = 0;
    for (int i = 0; i < 32; ++i) {
        if (num & (1 << i)) {
            count++;
        }
    }
    return count;
}

uint32_t sumNodesBitwise(Node *node, uint32_t currentSum) {
    if (node == NULL) {
        return currentSum;
    }

    currentSum = (currentSum << 1) | node->data;
    currentSum += sumNodesBitwise(node->right, currentSum);
    currentSum += sumNodesBitwise(node->left, currentSum);

    return currentSum;
}

uint32_t sumNodes(Node *node, uint32_t currentSum) {
    if (node == NULL) {
        return currentSum;
    }

    currentSum += node->data;
    currentSum += sumNodes(node->right, currentSum);
    currentSum += sumNodes(node->left, currentSum);

    return currentSum;
}

int main() {
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Using bitwise operations: %u\n", sumNodesBitwise(root, 0));
    printf("Using regular addition: %u\n", sumNodes(root, 0));

    return 0;
}