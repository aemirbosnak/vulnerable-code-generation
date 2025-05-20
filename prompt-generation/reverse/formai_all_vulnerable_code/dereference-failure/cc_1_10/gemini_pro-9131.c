//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: surrealist
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

void insert_node(node **root, node *new_node) {
    if (*root == NULL) {
        *root = new_node;
        return;
    }

    if (new_node->freq < (*root)->freq) {
        insert_node(&(*root)->left, new_node);
    } else {
        insert_node(&(*root)->right, new_node);
    }
}

void build_tree(node **root, char *data, int *freq, int size) {
    for (int i = 0; i < size; i++) {
        node *new_node = create_node(data[i], freq[i]);
        insert_node(root, new_node);
    }
}

void print_tree(node *root, char *code, int index) {
    if (root == NULL) {
        return;
    }

    if (root->left == NULL && root->right == NULL) {
        printf("%c: %s\n", root->data, code);
        return;
    }

    code[index] = '0';
    print_tree(root->left, code, index + 1);
    code[index] = '1';
    print_tree(root->right, code, index + 1);
}

void encode(char *data, char *encoded_data, int size, char *code) {
    for (int i = 0; i < size; i++) {
        strcat(encoded_data, code[data[i] - 'a']);
    }
}

void decode(char *encoded_data, int size, node *root) {
    node *current = root;

    for (int i = 0; i < size; i++) {
        if (encoded_data[i] == '0') {
            current = current->left;
        } else {
            current = current->right;
        }

        if (current->left == NULL && current->right == NULL) {
            printf("%c", current->data);
            current = root;
        }
    }
}

int main() {
    char data[] = "aacaabbccdd";
    int freq[] = {2, 3, 2, 1, 2, 1, 1, 1};
    int size = sizeof(data) / sizeof(data[0]);

    node *root = NULL;
    build_tree(&root, data, freq, size);

    char code[size];
    print_tree(root, code, 0);

    char encoded_data[100];
    encode(data, encoded_data, size, code);

    printf("Encoded data: %s\n", encoded_data);

    decode(encoded_data, strlen(encoded_data), root);

    return 0;
}