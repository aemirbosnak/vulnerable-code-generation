//Falcon2-11B DATASET v1.0 Category: Huffman Coding Implementation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

// A Node structure to represent a node in the Huffman Tree
typedef struct node {
    int freq;
    char data;
    struct node *left, *right;
} node;

// A function to calculate the frequency of a character
int freq(char data) {
    int cnt = 0;
    for (int i = 0; i < 26; i++) {
        if (data == 'a' + i) {
            cnt++;
        }
    }
    return cnt;
}

// A function to build the Huffman Tree
void build_tree(node *root, node **left, node **right) {
    node *min = root, *t;
    node *left_node = root->left, *right_node = root->right;
    while (min->left!= NULL) {
        min = min->left;
    }
    t = (node *)malloc(sizeof(node));
    t->freq = min->freq + left_node->freq + right_node->freq;
    t->data = '0';
    t->left = left_node;
    t->right = right_node;
    *left = *right = NULL;
    *left = t;
    *right = root;
    build_tree(*left, &left_node, &right_node);
    build_tree(*right, &left_node, &right_node);
}

// A function to print the Huffman Tree
void print_tree(node *root) {
    if (root == NULL) {
        return;
    }
    print_tree(root->left);
    printf("%c: %d\n", root->data, root->freq);
    print_tree(root->right);
}

// A function to generate the Huffman code
void generate_code(node *root, char *code, int *len) {
    if (root == NULL) {
        return;
    }
    if (root->left == NULL && root->right == NULL) {
        code[(*len)++] = root->data;
        return;
    }
    generate_code(root->left, code, len);
    generate_code(root->right, code, len);
}

// The main function
int main() {
    int freqs[] = {5, 3, 2, 1, 1, 1, 1, 1, 1, 1};
    node *root = NULL;
    node *temp = NULL;
    for (int i = 0; i < 10; i++) {
        root = (node *)malloc(sizeof(node));
        root->freq = freqs[i];
        root->data = 'a' + i;
        temp = root;
        for (int j = 0; j < 10; j++) {
            if (i == j) {
                continue;
            }
            temp->left = (node *)malloc(sizeof(node));
            temp->left->freq = freqs[j];
            temp->left->data = '0';
            temp->right = (node *)malloc(sizeof(node));
            temp->right->freq = freqs[j];
            temp->right->data = '1';
            temp = temp->right;
        }
        temp->left = NULL;
        temp->right = NULL;
        root = temp;
    }
    node **left, **right;
    build_tree(root, &left, &right);
    char code[256];
    int len = 0;
    generate_code(root, code, &len);
    printf("Huffman Code for 'a' is %s\n", code);
    printf("The length of Huffman Code is %d\n", len);
    return 0;
}