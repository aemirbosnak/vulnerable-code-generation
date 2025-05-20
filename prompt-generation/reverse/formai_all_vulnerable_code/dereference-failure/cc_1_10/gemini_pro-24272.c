//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char symbol;
    int freq;
    struct node *left;
    struct node *right;
} node;

node *create_node(char symbol, int freq) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->symbol = symbol;
    new_node->freq = freq;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

node *merge_nodes(node *left, node *right) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->symbol = '\0';
    new_node->freq = left->freq + right->freq;
    new_node->left = left;
    new_node->right = right;
    return new_node;
}

void print_tree(node *root) {
    if (root == NULL) {
        return;
    }
    printf("Symbol: %c, Frequency: %d\n", root->symbol, root->freq);
    print_tree(root->left);
    print_tree(root->right);
}

void build_huffman_tree(char *string) {
    int length = strlen(string);
    int frequencies[256] = {0};

    for (int i = 0; i < length; i++) {
        frequencies[string[i]]++;
    }

    node *pq[length];
    int pq_size = 0;
    for (int i = 0; i < 256; i++) {
        if (frequencies[i] > 0) {
            pq[pq_size++] = create_node(i, frequencies[i]);
        }
    }

    while (pq_size > 1) {
        node *left = pq[0];
        node *right = pq[1];
        for (int i = 2; i < pq_size; i++) {
            if (left->freq > pq[i]->freq) {
                left = pq[i];
            }
            if (right->freq > pq[i]->freq) {
                right = pq[i];
            }
        }

        node *new_node = merge_nodes(left, right);
        pq[0] = new_node;
        pq[1] = pq[pq_size - 1];
        pq_size--;
    }

    print_tree(pq[0]);
}

int main() {
    char *string = "Hello, world!";
    build_huffman_tree(string);
    return 0;
}