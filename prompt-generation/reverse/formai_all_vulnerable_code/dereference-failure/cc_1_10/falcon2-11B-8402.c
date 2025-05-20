//Falcon2-11B DATASET v1.0 Category: Huffman Coding Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_CODE_LEN 20
#define MAX_LEN 256

typedef struct node {
    int freq;
    char *code;
    struct node *left;
    struct node *right;
} Node;

Node* create_node(int freq) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->freq = freq;
    node->code = NULL;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* insert_char(Node* root, char c) {
    Node* node = create_node(0);
    node->freq = 1;
    node->code = (char*) malloc(MAX_CODE_LEN);
    strcpy(node->code, c);
    node->left = root;
    node->right = root;
    if (root == NULL) {
        root = node;
    } else {
        Node* parent = root;
        while (parent->freq > node->freq) {
            parent = parent->left;
        }
        if (c < parent->code[0]) {
            parent->left = node;
        } else {
            parent->right = node;
        }
    }
    return root;
}

void traverse(Node* root) {
    if (root == NULL) {
        return;
    }
    traverse(root->left);
    printf("%c", root->code[0]);
    traverse(root->right);
}

int main() {
    Node* root = NULL;
    insert_char(root, 'a');
    insert_char(root, 'b');
    insert_char(root, 'c');
    insert_char(root, 'd');
    insert_char(root, 'e');
    insert_char(root, 'f');
    insert_char(root, 'g');
    insert_char(root, 'h');
    insert_char(root, 'i');
    insert_char(root, 'j');
    insert_char(root, 'k');
    insert_char(root, 'l');
    insert_char(root,'m');
    insert_char(root, 'n');
    insert_char(root, 'o');
    insert_char(root, 'p');
    insert_char(root, 'q');
    insert_char(root, 'r');
    insert_char(root,'s');
    insert_char(root, 't');
    insert_char(root, 'u');
    insert_char(root, 'v');
    insert_char(root, 'w');
    insert_char(root, 'x');
    insert_char(root, 'y');
    insert_char(root, 'z');
    traverse(root);
    return 0;
}