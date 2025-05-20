//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct HNode {
    char ch;
    int freq;
    struct HNode *left, *right;
} HNode;

HNode *create_node(char ch, int freq) {
    HNode *node = (HNode *) malloc(sizeof(HNode));
    node->ch = ch;
    node->freq = freq;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int compare(const void *a, const void *b) {
    return ((HNode *) a)->freq - ((HNode *) b)->freq;
}

void print_codes(HNode *root, char *codes, int top) {
    if (root->left) {
        codes[top] = '0';
        print_codes(root->left, codes, top + 1);
    }
    if (root->right) {
        codes[top] = '1';
        print_codes(root->right, codes, top + 1);
    }
    if (!root->left && !root->right) {
        printf("%c: %s\n", root->ch, codes);
    }
}

void huffman_codes(char *input) {
    int n = strlen(input);
    HNode *nodes[n];
    int freqs[256] = {0};

    for (int i = 0; i < n; i++) {
        freqs[input[i]]++;
    }

    int top = 0;
    for (int i = 0; i < 256; i++) {
        if (freqs[i]) {
            nodes[top++] = create_node(i, freqs[i]);
        }
    }

    qsort(nodes, top, sizeof(HNode *), compare);

    HNode *left, *right, *top_node;
    while (top > 1) {
        left = nodes[top - 2];
        right = nodes[top - 1];
        top -= 2;

        top_node = create_node('$', left->freq + right->freq);
        top_node->left = left;
        top_node->right = right;
        nodes[top++] = top_node;

        qsort(nodes, top, sizeof(HNode *), compare);
    }

    char codes[n];
    print_codes(nodes[0], codes, 0);
}

int main() {
    char input[] = "aabcde";
    huffman_codes(input);
    return 0;
}