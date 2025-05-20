//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[50];
    int age;
    struct Node* left;
    struct Node* right;
} Node;

Node* create_node(const char* name, int age) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    strcpy(new_node->name, name);
    new_node->age = age;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

Node* insert_node(Node* root, const char* name, int age) {
    if (root == NULL) {
        return create_node(name, age);
    }

    if (strcmp(name, root->name) < 0) {
        root->left = insert_node(root->left, name, age);
    } else if (strcmp(name, root->name) > 0) {
        root->right = insert_node(root->right, name, age);
    } else {
        printf("Name '%s' already exists in the tree!\n", name);
    }

    return root;
}

void print_tree(Node* root, int level) {
    if (root == NULL) {
        return;
    }

    for (int i = 0; i < level; i++) {
        printf("    ");
    }

    printf("%s (%d years old)\n", root->name, root->age);

    print_tree(root->left, level + 1);
    print_tree(root->right, level + 1);
}

int main() {
    Node* root = NULL;

    // Insert some funny and creative names into the binary search tree
    root = insert_node(root, "Buddy Holly", 22);
    root = insert_node(root, "Einstein the Dog", 7);
    root = insert_node(root, "Marie Curie", 146);
    root = insert_node(root, "Albert Einstein", 110);
    root = insert_node(root, "Nefertiti", 35);
    root = insert_node(root, "Winnie the Pooh", 8);

    printf("Binary Search Tree:\n");
    print_tree(root, 0);

    return 0;
}