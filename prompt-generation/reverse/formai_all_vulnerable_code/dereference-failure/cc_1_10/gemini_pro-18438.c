//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int freq;
    char *symbol;
    struct node *left, *right;
} node;

node *create_node(char *symbol, int freq) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->symbol = symbol;
    new_node->freq = freq;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

node *merge_nodes(node *n1, node *n2) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->freq = n1->freq + n2->freq;
    new_node->left = n1;
    new_node->right = n2;
    return new_node;
}

node *build_tree(char *symbols[], int freqs[], int n) {
    node *pq[n];
    for (int i = 0; i < n; i++) {
        pq[i] = create_node(symbols[i], freqs[i]);
    }
    while (n > 1) {
        node *n1 = pq[0];
        node *n2 = pq[1];
        for (int i = 2; i < n; i++) {
            if (pq[i]->freq < n1->freq) {
                n2 = n1;
                n1 = pq[i];
            } else if (pq[i]->freq < n2->freq) {
                n2 = pq[i];
            }
        }
        pq[0] = merge_nodes(n1, n2);
        for (int i = 1; i < n - 1; i++) {
            pq[i] = pq[i + 1];
        }
        n--;
    }
    return pq[0];
}

void print_codes(node *root, char *code) {
    if (root->left == NULL && root->right == NULL) {
        printf("%s: %s\n", root->symbol, code);
    } else {
        print_codes(root->left, strcat(code, "0"));
        print_codes(root->right, strcat(code, "1"));
    }
}

int main() {
    char *symbols[] = {"a", "b", "c", "d", "e"};
    int freqs[] = {5, 9, 12, 13, 16};
    int n = sizeof(symbols) / sizeof(symbols[0]);
    node *root = build_tree(symbols, freqs, n);
    char code[100];
    print_codes(root, code);
    return 0;
}