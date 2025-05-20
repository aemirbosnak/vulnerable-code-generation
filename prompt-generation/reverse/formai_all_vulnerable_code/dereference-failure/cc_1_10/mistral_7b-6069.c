//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STR_LEN 100

typedef struct Node {
    char key[MAX_STR_LEN];
    struct Node *left, *right;
} Node;

Node* create_node(const char* key) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    strcpy(new_node->key, key);
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

Node* insert(Node* root, Node* new_node) {
    if (root == NULL) {
        root = new_node;
    } else if (strcmp(new_node->key, root->key) < 0) {
        root->left = insert(root->left, new_node);
    } else {
        root->right = insert(root->right, new_node);
    }
    return root;
}

void print_tree(Node* root, int level) {
    if (root == NULL) {
        return;
    }

    for (int i = 0; i < level; i++) {
        printf("  ");
    }

    printf("%s\n", root->key);
    print_tree(root->left, level + 1);
    print_tree(root->right, level + 1);
}

int main() {
    srand(time(NULL));

    int num_nodes = 10;
    Node* root = NULL;

    printf("Creating a binary search tree with %d random strings...\n", num_nodes);

    for (int i = 0; i < num_nodes; i++) {
        int len = rand() % 50 + 1;
        char key[MAX_STR_LEN];
        memset(key, rand() % 26 + 'A', len);
        key[len] = '\0';

        Node* new_node = create_node(key);
        root = insert(root, new_node);
    }

    printf("Binary search tree created successfully!\n");
    printf("Printing the tree in a surprised style...\n");

    print_tree(root, 0);

    return 0;
}