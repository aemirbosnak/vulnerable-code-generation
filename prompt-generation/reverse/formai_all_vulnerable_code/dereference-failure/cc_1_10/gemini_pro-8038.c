//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char symbol;
    int freq;
    struct node *left;
    struct node *right;
} node;

typedef struct tree {
    node *root;
} tree;

tree *create_tree(char *str) {
    tree *t = malloc(sizeof(tree));
    t->root = NULL;
    int len = strlen(str);
    int freq[256] = {0};
    for (int i = 0; i < len; i++) {
        freq[str[i]]++;
    }
    node *q[len];
    int front = 0, rear = 0;
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            node *n = malloc(sizeof(node));
            n->symbol = i;
            n->freq = freq[i];
            n->left = n->right = NULL;
            q[rear++] = n;
        }
    }
    while (front < rear) {
        node *n1 = q[front++];
        node *n2 = q[front++];
        node *n = malloc(sizeof(node));
        n->symbol = -1;
        n->freq = n1->freq + n2->freq;
        n->left = n1;
        n->right = n2;
        int j;
        for (j = front; j < rear; j++) {
            if (q[j]->freq > n->freq) {
                break;
            }
        }
        for (int k = rear; k > j; k--) {
            q[k] = q[k-1];
        }
        q[j] = n;
        rear++;
    }
    t->root = q[front];
    return t;
}

void print_tree(node *n, char *code) {
    if (n->left == NULL && n->right == NULL) {
        printf("%c: %s\n", n->symbol, code);
        return;
    }
    char left_code[strlen(code) + 1];
    char right_code[strlen(code) + 1];
    strcpy(left_code, code);
    strcpy(right_code, code);
    strcat(left_code, "0");
    strcat(right_code, "1");
    print_tree(n->left, left_code);
    print_tree(n->right, right_code);
}

void encode(tree *t, char *str, char *encoded) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        node *n = t->root;
        char code[100] = "";
        while (n->left != NULL && n->right != NULL) {
            if (str[i] == n->left->symbol) {
                strcat(code, "0");
                n = n->left;
            } else {
                strcat(code, "1");
                n = n->right;
            }
        }
        strcat(encoded, code);
    }
}

void decode(tree *t, char *encoded, char *decoded) {
    int len = strlen(encoded);
    node *n = t->root;
    for (int i = 0; i < len; i++) {
        if (encoded[i] == '0') {
            n = n->left;
        } else {
            n = n->right;
        }
        if (n->left == NULL && n->right == NULL) {
            *decoded++ = n->symbol;
            n = t->root;
        }
    }
    *decoded = '\0';
}

int main() {
    char str[] = "Hello World!";
    tree *t = create_tree(str);
    print_tree(t->root, "");
    char encoded[1000] = "";
    encode(t, str, encoded);
    printf("Encoded: %s\n", encoded);
    char decoded[1000] = "";
    decode(t, encoded, decoded);
    printf("Decoded: %s\n", decoded);
    return 0;
}