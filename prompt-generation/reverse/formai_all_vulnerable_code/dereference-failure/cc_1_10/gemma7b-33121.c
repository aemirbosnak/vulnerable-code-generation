//Gemma-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HEIGHT 256

typedef struct Node {
    struct Node* left;
    struct Node* right;
    char data;
} Node;

Node* newNode(char data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->left = NULL;
    node->right = NULL;
    node->data = data;
    return node;
}

void insert(Node* node, char data) {
    if (node == NULL) {
        node = newNode(data);
        return;
    }
    if (data < node->data) {
        insert(node->left, data);
    } else {
        insert(node->right, data);
    }
}

void huffman(Node* root) {
    if (root == NULL) {
        return;
    }
    huffman(root->left);
    huffman(root->right);
    printf("%c ", root->data);
}

int main() {
    char text[] = "This is a secret message. It is hidden in this code. Can you find it?";
    Node* root = newNode('\0');
    for (int i = 0; text[i] != '\0'; i++) {
        insert(root, text[i]);
    }
    huffman(root);
    return 0;
}