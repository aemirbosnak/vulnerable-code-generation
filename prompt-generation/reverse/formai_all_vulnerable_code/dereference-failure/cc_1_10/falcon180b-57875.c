//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define TRUE 1
#define FALSE 0

typedef struct node {
    char name[MAX_NAME_LEN];
    int age;
    struct node* left;
    struct node* right;
} Node;

Node* create_node(char* name, int age) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    strcpy(new_node->name, name);
    new_node->age = age;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

Node* insert_node(Node* root, char* name, int age) {
    if (root == NULL) {
        root = create_node(name, age);
        return root;
    }

    if (strcmp(root->name, name) < 0)
        root->right = insert_node(root->right, name, age);
    else if (strcmp(root->name, name) > 0)
        root->left = insert_node(root->left, name, age);

    return root;
}

Node* search_node(Node* root, char* name) {
    if (root == NULL)
        return NULL;

    if (strcmp(root->name, name) == 0)
        return root;

    if (strcmp(root->name, name) < 0)
        return search_node(root->right, name);
    else
        return search_node(root->left, name);
}

void preorder_traversal(Node* root) {
    if (root == NULL)
        return;

    printf("%s %d\n", root->name, root->age);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

void inorder_traversal(Node* root) {
    if (root == NULL)
        return;

    inorder_traversal(root->left);
    printf("%s %d\n", root->name, root->age);
    inorder_traversal(root->right);
}

void postorder_traversal(Node* root) {
    if (root == NULL)
        return;

    postorder_traversal(root->left);
    postorder_traversal(root->right);
    printf("%s %d\n", root->name, root->age);
}

int main() {
    Node* root = NULL;

    // Insert nodes
    root = insert_node(root, "Alice", 25);
    root = insert_node(root, "Bob", 30);
    root = insert_node(root, "Charlie", 20);
    root = insert_node(root, "David", 28);

    // Traverse tree
    printf("Preorder traversal:\n");
    preorder_traversal(root);
    printf("\n");

    printf("Inorder traversal:\n");
    inorder_traversal(root);
    printf("\n");

    printf("Postorder traversal:\n");
    postorder_traversal(root);
    printf("\n");

    // Search node
    Node* found_node = search_node(root, "Charlie");
    if (found_node!= NULL)
        printf("Found node: %s %d\n", found_node->name, found_node->age);
    else
        printf("Node not found.\n");

    return 0;
}