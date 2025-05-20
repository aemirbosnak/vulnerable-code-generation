//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int freq;
    char data;
    struct node *left;
    struct node *right;
} node;

node *create_node(char data, int freq) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->freq = freq;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

node *build_tree(node **nodes, int size) {
    while (size > 1) {
        int min1 = 0, min2 = 1;
        for (int i = 0; i < size; i++) {
            if (nodes[i]->freq < nodes[min1]->freq) {
                min2 = min1;
                min1 = i;
            } else if (nodes[i]->freq < nodes[min2]->freq && min1 != i) {
                min2 = i;
            }
        }
        node *left = nodes[min1];
        node *right = nodes[min2];
        node *parent = create_node('\0', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        nodes[min1] = parent;
        nodes[min2] = nodes[size - 1];
        size--;
    }
    return nodes[0];
}

void print_tree(node *root, char *code) {
    if (root->left == NULL && root->right == NULL) {
        printf("%c: %s\n", root->data, code);
        return;
    }
    code[strlen(code)] = '0';
    print_tree(root->left, code);
    code[strlen(code) - 1] = '\0';
    code[strlen(code)] = '1';
    print_tree(root->right, code);
    code[strlen(code) - 1] = '\0';
}

void encode(node *root, char *data, char *encoded) {
    if (root->left == NULL && root->right == NULL) {
        encoded[strlen(encoded)] = root->data;
        return;
    }
    for (int i = 0; i < strlen(data); i++) {
        if (data[i] == root->data) {
            encoded[strlen(encoded)] = '1';
            encode(root->left, data, encoded);
            encoded[strlen(encoded)] = '0';
            encode(root->right, data, encoded);
        }
    }
}

void decode(node *root, char *encoded) {
    node *current = root;
    for (int i = 0; i < strlen(encoded); i++) {
        if (encoded[i] == '0') {
            current = current->left;
        } else if (encoded[i] == '1') {
            current = current->right;
        }
        if (current->left == NULL && current->right == NULL) {
            printf("%c", current->data);
            current = root;
        }
    }
}

int main() {
    char data[] = "Huffman Coding";
    int freq[] = {5, 1, 4, 2, 3};
    int size = sizeof(data) / sizeof(data[0]);

    node *nodes[size];
    for (int i = 0; i < size; i++) {
        nodes[i] = create_node(data[i], freq[i]);
    }

    node *root = build_tree(nodes, size);
    char code[100] = "";
    print_tree(root, code);

    char encoded[100] = "";
    encode(root, data, encoded);
    printf("%s\n", encoded);

    decode(root, encoded);

    return 0;
}