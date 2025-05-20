//Falcon2-11B DATASET v1.0 Category: Huffman Coding Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100

typedef struct node {
    int freq;
    char* char_code;
    struct node* left;
    struct node* right;
} Node;

Node* createNode(int freq, char* char_code) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->freq = freq;
    node->char_code = char_code;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void free_node(Node* node) {
    if (node == NULL) {
        return;
    }
    free_node(node->left);
    free_node(node->right);
    free(node);
}

Node* build_tree(int freq[], int size) {
    Node* root = createNode(freq[0], "");
    int i;
    for (i = 1; i < size; i++) {
        Node* temp = createNode(freq[i], "");
        root->left = temp;
        root = root->left;
    }
    return root;
}

char* huffman_encoding(char* str, Node* root) {
    int i;
    char* result = (char*) malloc(strlen(str) * sizeof(char));
    for (i = 0; i < strlen(str); i++) {
        result[i] = root->char_code[str[i] - 'a'];
    }
    return result;
}

int main() {
    char str[] = "ababababab";
    int freq[26] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    Node* root = build_tree(freq, 26);
    char* encoded_str = huffman_encoding(str, root);
    printf("Huffman encoded string: %s\n", encoded_str);
    free(encoded_str);
    free_node(root);
    return 0;
}