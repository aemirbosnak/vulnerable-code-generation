//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    char name[30];
    int magic_points;
    struct Node* left;
    struct Node* right;
} Node;

Node* create_node(char* name, int magic_points) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    strcpy(new_node->name, name);
    new_node->magic_points = magic_points;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

Node* insert_node(Node* root, Node* new_node) {
    if (root == NULL) {
        root = new_node;
    } else if (strcmp(new_node->name, root->name) < 0) {
        root->left = insert_node(root->left, new_node);
    } else if (strcmp(new_node->name, root->name) > 0) {
        root->right = insert_node(root->right, new_node);
    }
    return root;
}

void print_wisps(Node* root, int level) {
    if (root == NULL) {
        return;
    }

    for (int i = 0; i < level; i++) {
        printf("  ");
    }

    printf("%s (%d magic points)\n", root->name, root->magic_points);

    print_wisps(root->left, level + 1);
    print_wisps(root->right, level + 1);
}

int main() {
    Node* whimsical_tree = NULL;

    whimsical_tree = insert_node(whimsical_tree, create_node("Flutterby", 10));
    whimsical_tree = insert_node(whimsical_tree, create_node("Glittergob", 15));
    whimsical_tree = insert_node(whimsical_tree, create_node("Moonbeam", 20));
    whimsical_tree = insert_node(whimsical_tree, create_node("Sunspot", 12));

    print_wisps(whimsical_tree, 0);

    return 0;
}