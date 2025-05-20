//Falcon2-11B DATASET v1.0 Category: Huffman Coding Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int frequency;
    char data;
    struct node *left, *right;
} Node;

Node *makeNode(int freq, char data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->frequency = freq;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void insertNode(Node *root, int freq, char data) {
    Node *newNode = makeNode(freq, data);
    if (root == NULL) {
        root = newNode;
        return;
    }
    insertNode(root->left, freq, data);
    insertNode(root->right, freq, data);
}

void inorderTraversal(Node *root) {
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    printf("%c: %d\n", root->data, root->frequency);
    inorderTraversal(root->right);
}

void huffmanCoding(Node *root) {
    if (root == NULL)
        return;
    Node *temp = root->left;
    while (temp->right!= NULL)
        temp = temp->right;
    temp->right = root;
    huffmanCoding(temp);
}

int main() {
    Node *root = NULL;
    insertNode(root, 3, 'a');
    insertNode(root, 2, 'b');
    insertNode(root, 1, 'c');
    insertNode(root, 4, 'd');
    insertNode(root, 5, 'e');

    inorderTraversal(root);
    printf("\n");
    huffmanCoding(root);
    inorderTraversal(root);

    return 0;
}