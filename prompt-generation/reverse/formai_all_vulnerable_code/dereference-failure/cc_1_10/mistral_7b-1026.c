//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 50

typedef struct Node {
    char name[MAX_NAME_LENGTH + 1];
    int age;
    struct Node *left, *right;
} Node;

Node* create_node(const char* name, int age) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    strcpy(new_node->name, name);
    new_node->age = age;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

Node* insert(Node* root, Node* new_node) {
    if (root == NULL)
        return new_node;

    if (strcmp(new_node->name, root->name) < 0)
        root->left = insert(root->left, new_node);
    else if (strcmp(new_node->name, root->name) > 0)
        root->right = insert(root->right, new_node);

    return root;
}

Node* search(Node* root, const char* name) {
    if (root == NULL || strcmp(name, root->name) == 0)
        return root;

    if (strcmp(name, root->name) < 0)
        return search(root->left, name);

    return search(root->right, name);
}

void print_node(Node* node) {
    if (node == NULL) {
        printf("Empty\n");
        return;
    }

    printf("%s (%d years old)\n", node->name, node->age);
}

void inorder_traversal(Node* root) {
    if (root == NULL)
        return;

    inorder_traversal(root->left);
    print_node(root);
    inorder_traversal(root->right);
}

int main() {
    Node* root = NULL;

    const char* names[] = {"John Doe", "Jane Doe", "Bob Smith", "Alice Johnson", "Peter Brown"};
    int ages[] = {32, 28, 45, 35, 23};

    for (size_t i = 0; i < 5; ++i)
        root = insert(root, create_node(names[i], ages[i]));

    printf("Binary Search Tree:\n");
    inorder_traversal(root);

    Node* person = search(root, "Alice Johnson");
    if (person != NULL)
        printf("\nFound: %s\n", person->name);
    else
        printf("\nNot found\n");

    return 0;
}