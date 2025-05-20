//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    char word[MAX_SIZE];
    int count;
    struct node *left;
    struct node *right;
} Node;

Node* create_node(char *word) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    strcpy(new_node->word, word);
    new_node->count = 1;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

Node* insert_node(Node *root, char *word) {
    if (root == NULL) {
        root = create_node(word);
        return root;
    }

    if (strcmp(root->word, word) == 0) {
        root->count++;
        return root;
    }

    if (strcmp(root->word, word) < 0) {
        root->right = insert_node(root->right, word);
    } else if (strcmp(root->word, word) > 0) {
        root->left = insert_node(root->left, word);
    }

    root->count = root->left->count + root->right->count + 1;

    return root;
}

void inorder_traversal(Node *root) {
    if (root == NULL) {
        return;
    }

    inorder_traversal(root->left);
    printf("%s %d\n", root->word, root->count);
    inorder_traversal(root->right);
}

int main() {
    Node *root = NULL;
    char input[MAX_SIZE];

    printf("Enter words (type 'quit' to exit):\n");
    while (1) {
        scanf("%s", input);
        if (strcmp(input, "quit") == 0) {
            break;
        }
        root = insert_node(root, input);
    }

    printf("Inorder traversal:\n");
    inorder_traversal(root);

    return 0;
}