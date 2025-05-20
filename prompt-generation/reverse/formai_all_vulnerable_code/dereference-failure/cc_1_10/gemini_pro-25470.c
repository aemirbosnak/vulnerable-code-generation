//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char c;
    int count;
    struct node *left;
    struct node *right;
} node;

typedef struct huff_tree {
    node *root;
} huff_tree;

node* create_node(char c, int count) {
    node *n = malloc(sizeof(node));
    n->c = c;
    n->count = count;
    n->left = NULL;
    n->right = NULL;
    return n;
}

huff_tree* create_tree(char *s) {
    huff_tree *t = malloc(sizeof(huff_tree));
    t->root = NULL;

    int count[256] = {0};
    for (int i = 0; s[i] != '\0'; i++) {
        count[s[i]]++;
    }

    node *nodes[256];
    for (int i = 0; i < 256; i++) {
        if (count[i] > 0) {
            nodes[i] = create_node(i, count[i]);
        }
    }

    while (nodes[0] != NULL) {
        node *min1 = NULL;
        node *min2 = NULL;

        for (int i = 0; i < 256; i++) {
            if (nodes[i] != NULL) {
                if (min1 == NULL || nodes[i]->count < min1->count) {
                    min1 = nodes[i];
                }
            }
        }

        for (int i = 0; i < 256; i++) {
            if (nodes[i] != NULL) {
                if (min2 == NULL || nodes[i]->count < min2->count && nodes[i] != min1) {
                    min2 = nodes[i];
                }
            }
        }

        if (min1 == NULL || min2 == NULL) {
            break;
        }

        node *parent = create_node('\0', min1->count + min2->count);
        parent->left = min1;
        parent->right = min2;

        for (int i = 0; i < 256; i++) {
            if (nodes[i] == min1 || nodes[i] == min2) {
                nodes[i] = NULL;
            }
        }

        nodes[0] = parent;
    }

    t->root = nodes[0];
    return t;
}

void encode(huff_tree *t, char *s, char *compressed) {
    int i = 0;
    node *current = t->root;

    while (s[i] != '\0') {
        if (current->left == NULL && current->right == NULL) {
            compressed[i] = '0';
            if (current->c == s[i]) {
                compressed[i + 1] = '1';
                compressed[i + 2] = '\0';
                return;
            } else {
                compressed[i + 1] = '0';
                i++;
                current = t->root;
            }
        } else if (current->left != NULL && current->right == NULL) {
            compressed[i] = '0';
            current = current->left;
        } else if (current->left == NULL && current->right != NULL) {
            compressed[i] = '1';
            current = current->right;
        } else {
            if (s[i] < current->left->c) {
                compressed[i] = '0';
                current = current->left;
            } else {
                compressed[i] = '1';
                current = current->right;
            }
        }
        i++;
    }
}

void decode(huff_tree *t, char *compressed, char *decoded) {
    int i = 0;
    node *current = t->root;

    while (compressed[i] != '\0') {
        if (current->left == NULL && current->right == NULL) {
            decoded[i] = current->c;
            current = t->root;
        } else if (current->left != NULL && current->right == NULL) {
            if (compressed[i] == '0') {
                current = current->left;
            }
        } else if (current->left == NULL && current->right != NULL) {
            if (compressed[i] == '1') {
                current = current->right;
            }
        } else {
            if (compressed[i] == '0') {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        i++;
    }

    decoded[i] = '\0';
}

int main() {
    char s[] = "Hello, world!";

    huff_tree *t = create_tree(s);
    char compressed[1024] = {0};
    encode(t, s, compressed);

    char decoded[1024] = {0};
    decode(t, compressed, decoded);

    printf("Original: %s\n", s);
    printf("Compressed: %s\n", compressed);
    printf("Decoded: %s\n", decoded);

    return 0;
}