//FormAI DATASET v1.0 Category: Data structures visualization ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* create_node(int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert_node(Node** root, int data) {
    if (*root == NULL) {
        *root = create_node(data);
        return;
    }
    if (data <= (*root)->data) {
        insert_node(&((*root)->left), data);
    } else {
        insert_node(&((*root)->right), data);
    }
}

int max_depth(Node* root) {
    if (root == NULL) {
        return 0;
    } else {
        int left_depth = max_depth(root->left);
        int right_depth = max_depth(root->right);
        if (left_depth > right_depth) {
            return (left_depth + 1);
        } else {
            return (right_depth + 1);
        }
    }
}

void print_branch(char* branch, int depth) {
    for (int i = 0; i < depth; i++) {
        printf("|    ");
    }
    printf("%s", branch);
}

void visualize_tree(Node* root, char* branch, int depth) {
    if (root == NULL) {
        return;
    }
    print_branch(branch, depth);
    printf("%d\n", root->data);
    char* new_branch = (char*) malloc(strlen(branch) + 5);
    strcpy(new_branch, branch);
    if (root->left != NULL) {
        strcat(new_branch, "|    ");
        visualize_tree(root->left, new_branch, depth + 1);
    }
    memset(new_branch + strlen(branch), ' ', 5);
    if (root->right != NULL) {
        strcat(new_branch, "|    ");
        visualize_tree(root->right, new_branch, depth + 1);
    }
    free(new_branch);
}

int main() {
    Node* root = NULL;
    insert_node(&root, 7);
    insert_node(&root, 4);
    insert_node(&root, 1);
    insert_node(&root, 6);
    insert_node(&root, 9);
    insert_node(&root, 8);
    insert_node(&root, 10);
    int depth = max_depth(root);
    printf("Tree Visualization:\n");
    visualize_tree(root, "", 0);
    return 0;
}