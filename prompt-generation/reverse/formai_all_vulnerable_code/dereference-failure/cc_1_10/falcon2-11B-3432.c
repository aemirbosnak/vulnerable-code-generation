//Falcon2-11B DATASET v1.0 Category: Syntax parsing ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char *name;
    struct Node *left;
    struct Node *right;
} Node;

Node *parse_syntax_tree(char *input) {
    if (!input)
        return NULL;
    if (input[0] == '(' && input[strlen(input) - 1] == ')') {
        int num_parens = 0;
        for (int i = 1; i < strlen(input); i++) {
            if (input[i] == '(')
                num_parens++;
            if (input[i] == ')')
                num_parens--;
            if (num_parens == 0)
                break;
        }
        if (num_parens == 0) {
            Node *root = (Node *)malloc(sizeof(Node));
            root->name = strdup(input);
            root->left = NULL;
            root->right = NULL;
            return root;
        }
    }
    Node *root = parse_syntax_tree(input + 1);
    if (root == NULL)
        return NULL;
    Node *current = root;
    while (current->left!= NULL) {
        current = current->left;
    }
    current->left = parse_syntax_tree(input);
    return root;
}

int main() {
    char input[] = "((A + B) * C)";
    Node *root = parse_syntax_tree(input);
    if (root) {
        printf("Syntax tree: %s\n", root->name);
        if (root->left) {
            printf("Left subtree: %s\n", root->left->name);
        }
        if (root->right) {
            printf("Right subtree: %s\n", root->right->name);
        }
        free(root->name);
        free(root);
    }
    return 0;
}