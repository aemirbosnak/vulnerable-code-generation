//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return root;
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    return root;
}

void inorderTraversal(Node* root, char* output) {
    if (root == NULL) {
        *output = '\0';
        return;
    }

    inorderTraversal(root->left, output);
    *output++ = ' ';
    *output++ = (root->data > 50 ? '>' : '<');
    *output++ = (root->data % 2 == 0 ? 'E' : 'O');
    *output++ = (root->data % 3 == 0 ? '.' : '_');
    *output++ = (root->data % 5 == 0 ? '*' : ' ');
    *output++ = '\n';

    inorderTraversal(root->right, output);
}

int main() {
    Node* root = NULL;
    int data[] = {15, 10, 20, 25, 30};
    int i;

    for (i = 0; i < sizeof(data)/sizeof(data[0]); i++) {
        root = insertNode(root, data[i]);
    }

    char output[1024] = {0};
    inorderTraversal(root, output);

    printf("%s", output);

    return 0;
}