//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef struct node {
    char *word;
    int count;
    struct node *left;
    struct node *right;
} Node;

Node* create_node(char *word) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->word = word;
    node->count = 1;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* insert_node(Node *root, char *word) {
    if (root == NULL) {
        return create_node(word);
    }

    if (strcmp(word, root->word) < 0) {
        root->left = insert_node(root->left, word);
    } else if (strcmp(word, root->word) > 0) {
        root->right = insert_node(root->right, word);
    } else {
        root->count++;
    }

    return root;
}

void inorder_traversal(Node *root, void (*visit)(Node*)) {
    if (root!= NULL) {
        inorder_traversal(root->left, visit);
        visit(root);
        inorder_traversal(root->right, visit);
    }
}

void print_word_count(Node *node) {
    printf("%s: %d\n", node->word, node->count);
}

int main() {
    char input[100];
    Node *root = NULL;

    printf("Enter words (type 'done' to finish):\n");
    while (fgets(input, sizeof(input), stdin)!= NULL) {
        char *word = strtok(input, "\n");
        if (strcmp(word, "done") == 0) {
            break;
        }
        root = insert_node(root, word);
    }

    printf("Words and their counts:\n");
    inorder_traversal(root, print_word_count);

    return 0;
}