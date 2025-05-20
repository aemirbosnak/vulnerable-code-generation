//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: brave
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct Tree {
    Node* root;
} Tree;

typedef struct Code {
    int* code;
    int size;
} Code;

Node* create_node(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Tree* create_tree(int* values, int size) {
    Tree* tree = (Tree*)malloc(sizeof(Tree));
    tree->root = NULL;

    for (int i = 0; i < size; i++) {
        Node* node = create_node(values[i]);
        if (tree->root == NULL) {
            tree->root = node;
        } else {
            Node* current = tree->root;
            while (true) {
                if (node->value <= current->value) {
                    if (current->left == NULL) {
                        current->left = node;
                        break;
                    } else {
                        current = current->left;
                    }
                } else {
                    if (current->right == NULL) {
                        current->right = node;
                        break;
                    } else {
                        current = current->right;
                    }
                }
            }
        }
    }

    return tree;
}

void print_tree(Node* node) {
    if (node == NULL) {
        return;
    }

    printf("%d", node->value);
    if (node->left != NULL) {
        printf(" (");
        print_tree(node->left);
        printf(")");
    }
    if (node->right != NULL) {
        printf(" (");
        print_tree(node->right);
        printf(")");
    }
}

void destroy_tree(Node* node) {
    if (node == NULL) {
        return;
    }

    destroy_tree(node->left);
    destroy_tree(node->right);
    free(node);
}

Code* encode(Tree* tree, int value) {
    Code* code = (Code*)malloc(sizeof(Code));
    code->code = NULL;
    code->size = 0;

    Node* current = tree->root;
    while (current != NULL) {
        if (value == current->value) {
            break;
        } else if (value < current->value) {
            code->size++;
            code->code = (int*)realloc(code->code, code->size * sizeof(int));
            code->code[code->size - 1] = 0;
            current = current->left;
        } else {
            code->size++;
            code->code = (int*)realloc(code->code, code->size * sizeof(int));
            code->code[code->size - 1] = 1;
            current = current->right;
        }
    }

    return code;
}

void print_code(Code* code) {
    for (int i = 0; i < code->size; i++) {
        printf("%d", code->code[i]);
    }
}

void destroy_code(Code* code) {
    free(code->code);
    free(code);
}

int main() {
    int values[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(values) / sizeof(values[0]);

    Tree* tree = create_tree(values, size);
    print_tree(tree->root);
    printf("\n");

    int value = 5;
    Code* code = encode(tree, value);
    print_code(code);
    printf("\n");

    destroy_code(code);
    destroy_tree(tree->root);

    return 0;
}