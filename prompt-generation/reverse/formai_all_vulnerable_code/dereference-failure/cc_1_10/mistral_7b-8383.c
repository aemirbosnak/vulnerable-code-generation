//MISTRAL-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    unsigned char ch;
    unsigned int freq;
    struct node *left, *right;
} node_t;

void emit_codes(node_t *root, char *codes, int *len) {
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL) {
        printf("Character %c with frequency %d has the code %s\n", root->ch, root->freq, codes);
        *len += strlen(codes) + 1;
    }

    emit_codes(root->left, codes, len);
    emit_codes(root->right, codes ? strcat(codes, "0") : "0", len);
}

void build_tree(unsigned char *input, unsigned int length, node_t **root) {
    node_t **left, **right, **q;
    node_t *node1, *node2;

    if (length == 0) {
        *root = NULL;
        return;
    }

    q = (node_t **)calloc(length, sizeof(node_t *));

    for (int i = 0; i < length; i++) {
        node1 = (node_t *)malloc(sizeof(node_t));
        node1->ch = input[i];
        node1->freq = 1;
        node1->left = NULL;
        node1->right = NULL;
        q[i] = node1;
    }

    while (q[0] && q[1]) {
        node1 = q[0];
        q++;

        node2 = q[0];
        q++;

        *root = (node_t *)malloc(sizeof(node_t));

        (*root)->ch = 0;
        (*root)->freq = node1->freq + node2->freq;
        (*root)->left = node1;
        (*root)->right = node2;

        left = &(*root)->left;
        right = &(*root)->right;

        *left = node1;
        *right = node2;
    }

    *root = q[0];
}

int main(int argc, char **argv) {
    unsigned char input[] = {'A' - 1, 'B', 'C', 'C', 'D', 'E', 'E', 'E'};
    unsigned int length = sizeof(input) / sizeof(unsigned char);
    node_t *root;
    char *codes = NULL;
    int len = 0;

    build_tree(input, length, &root);
    emit_codes(root, NULL, &len);
    free(codes);
    free(root);

    return 0;
}