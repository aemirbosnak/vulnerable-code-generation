//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int frequency;
    char character;
    struct node *left_child;
    struct node *right_child;
} node;

int codearray[100], top = 0;

node *new_node(int frequency, char character) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->frequency = frequency;
    new_node->character = character;
    new_node->left_child = NULL;
    new_node->right_child = NULL;
    return new_node;
}

void print_codearray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");
}

void print_tree(node *tree) {
    if (tree == NULL) {
        return;
    }

    if (tree->left_child == NULL && tree->right_child == NULL) {
        printf("%c: ", tree->character);
        print_codearray(codearray, top);
    } else {
        codearray[top] = 0;
        top++;
        print_tree(tree->left_child);

        codearray[top] = 1;
        top++;
        print_tree(tree->right_child);
    }
    top--;
}

void build_codearray(node *tree, char character, int arr[], int n) {
    if (tree == NULL) {
        return;
    }

    if (tree->character == character) {
        print_codearray(arr, n);
    } else {
        arr[n] = 0;
        build_codearray(tree->left_child, character, arr, n+1);

        arr[n] = 1;
        build_codearray(tree->right_child, character, arr, n+1);
    }
}

int compare_nodes(const void *a, const void *b) {
    node **node_a = (node **)a;
    node **node_b = (node **)b;

    return (*node_a)->frequency - (*node_b)->frequency;
}

node *build_huffman_tree(char *input_string) {
    int len = strlen(input_string), i;

    node **nodes = (node **)malloc(len * sizeof(node *));
    for (i = 0; i < len; i++) {
        nodes[i] = new_node(0, input_string[i]);
    }

    qsort(nodes, len, sizeof(node *), compare_nodes);

    while (len > 1) {
        node *left_child = nodes[0];
        node *right_child = nodes[1];

        node *parent = new_node(left_child->frequency + right_child->frequency, '*');
        parent->left_child = left_child;
        parent->right_child = right_child;

        nodes[0] = parent;
        int j;
        for (j = 1; j < len - 1; j++) {
            nodes[j] = nodes[j+1];
        }
        len--;

        qsort(nodes, len, sizeof(node *), compare_nodes);
    }

    return nodes[0];
}

int main() {
    char input_string[100];
    printf("Enter a string: ");
    fgets(input_string, 100, stdin);

    // Remove newline character at the end of input string
    input_string[strcspn(input_string, "\n")] = 0;

    node *huffman_tree = build_huffman_tree(input_string);
    build_codearray(huffman_tree, 'b', codearray, top);
    print_tree(huffman_tree);

    return 0;
}