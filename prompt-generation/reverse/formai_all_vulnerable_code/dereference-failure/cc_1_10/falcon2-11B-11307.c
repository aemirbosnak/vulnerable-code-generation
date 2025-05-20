//Falcon2-11B DATASET v1.0 Category: Huffman Coding Implementation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUF_SIZE 4096

typedef struct node {
    int freq;
    char *str;
    struct node *left;
    struct node *right;
} Node;

Node *buildTree(char *str, int n) {
    int i, j, k, m;
    Node *root = (Node *)malloc(sizeof(Node));
    root->str = (char *)malloc(BUF_SIZE);
    strcpy(root->str, str);
    root->freq = n;
    for (i = 0; i < 256; i++) {
        root->left = NULL;
        root->right = NULL;
    }
    root->left = root->right = NULL;

    for (i = 0; i < 256; i++) {
        Node *temp = (Node *)malloc(sizeof(Node));
        temp->str = NULL;
        temp->freq = 0;
        temp->left = temp->right = NULL;
        root->left = temp;
        root->right = temp;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < 256; j++) {
            if (str[i] == (char)j) {
                if (root->left->freq > root->right->freq) {
                    Node *temp = root->left;
                    root->left = root->right;
                    root->right = temp;
                } else {
                    Node *temp = root->right;
                    root->left = root->right;
                    root->right = temp;
                }
                break;
            }
        }
    }
    return root;
}

void printTree(Node *root) {
    if (root == NULL) {
        return;
    }
    printTree(root->left);
    printf("%c: %d\n", root->str[0], root->freq);
    printTree(root->right);
}

char *compress(char *str, int n) {
    Node *root = buildTree(str, n);
    char *buf = (char *)malloc(BUF_SIZE);
    int i, j, k, m;
    for (i = 0; i < n; i++) {
        for (j = 0; j < 256; j++) {
            if (str[i] == (char)j) {
                if (root->left->freq > root->right->freq) {
                    Node *temp = root->left;
                    root->left = root->right;
                    root->right = temp;
                } else {
                    Node *temp = root->right;
                    root->left = root->right;
                    root->right = temp;
                }
                break;
            }
        }
    }
    Node *node = root;
    int code = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < 256; j++) {
            if (str[i] == (char)j) {
                code = (code << 8) | j;
                break;
            }
        }
    }
    while (node!= NULL) {
        if (code >= node->freq) {
            k = code - node->freq;
            buf[k] = node->str[0];
            node = node->left;
        } else {
            buf[k] = node->str[0];
            code -= node->freq;
            node = node->right;
        }
        k++;
    }
    buf[k] = '\0';
    return buf;
}

int main() {
    char str[BUF_SIZE] = "abcabcabcabc";
    int n = strlen(str);
    Node *root = buildTree(str, n);
    printf("Tree: ");
    printTree(root);
    printf("Compressed string: %s\n", compress(str, n));
    return 0;
}