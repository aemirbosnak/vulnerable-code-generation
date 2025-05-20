//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int key;
    char name[20];
    struct Node *left, *right;
} Node;

Node* newNode(int key, char* name) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->key = key;
    strcpy(node->name, name);
    node->left = node->right = NULL;
    return node;
}

Node* insert(Node* root, int key, char* name) {
    if (root == NULL)
        return newNode(key, name);

    if (key < root->key)
        root->left = insert(root->left, key, name);
    else if (key > root->key)
        root->right = insert(root->right, key, name);

    return root;
}

Node* search(Node* root, int key) {
    if (root == NULL || root->key == key)
        return root;

    if (key < root->key)
        return search(root->left, key);

    return search(root->right, key);
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d %s ", root->key, root->name);
        inorder(root->right);
    }
}

int height(Node* root) {
    if (root == NULL)
        return 0;
    else
        return (1 + MAX(height(root->left), height(root->right)));
}

int MAX(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    Node* root = NULL;
    int i, keys[] = { 50, 30, 20, 40, 70, 60, 80 };
    char names[][20] = { "John", "Mike", "Bob", "Nick", "George", "Tom", "Sara" };

    for (i = 0; i < 7; i++)
        root = insert(root, keys[i], names[i]);

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    printf("Height of tree is %d\n", height(root));

    Node* searchNode = search(root, 60);
    if (searchNode != NULL)
        printf("%s found\n", searchNode->name);
    else
        printf("60 not found\n");

    return 0;
}