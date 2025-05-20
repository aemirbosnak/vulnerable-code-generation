//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

struct Node {
    char c;
    int freq;
    struct Node *left, *right;
};

struct Node *createNode(char c, int freq) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->c = c;
    node->freq = freq;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node *mergeNodes(struct Node *a, struct Node *b) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->c = '\0';
    node->freq = a->freq + b->freq;
    node->left = a;
    node->right = b;
    return node;
}

void printTree(struct Node *root, int depth) {
    if (root == NULL) {
        return;
    }
    printTree(root->left, depth + 1);
    printf("%*s%c: %d\n", depth * 4, "", root->c, root->freq);
    printTree(root->right, depth + 1);
}

void printCodes(struct Node *root, char *code, int depth) {
    if (root == NULL) {
        return;
    }
    if (root->c != '\0') {
        code[depth] = '\0';
        printf("%c: %s\n", root->c, code);
    }
    printCodes(root->left, code, depth + 1);
    code[depth] = '0';
    printCodes(root->right, code, depth + 1);
}

char *encode(char *text, struct Node *root) {
    int text_len = strlen(text);
    char *code = (char *)malloc(sizeof(char) * text_len * 8);
    int code_len = 0;
    for (int i = 0; i < text_len; i++) {
        struct Node *node = root;
        while (node->c != text[i]) {
            if (text[i] == node->left->c) {
                code[code_len++] = '0';
                node = node->left;
            } else {
                code[code_len++] = '1';
                node = node->right;
            }
        }
    }
    code[code_len] = '\0';
    return code;
}

char *decode(char *code, struct Node *root) {
    int code_len = strlen(code);
    char *text = (char *)malloc(sizeof(char) * code_len);
    int text_len = 0;
    struct Node *node = root;
    for (int i = 0; i < code_len; i++) {
        if (code[i] == '0') {
            node = node->left;
        } else {
            node = node->right;
        }
        if (node->c != '\0') {
            text[text_len++] = node->c;
            node = root;
        }
    }
    text[text_len] = '\0';
    return text;
}

int main() {
    int freq[256] = {0};
    char text[] = "Huffman Coding";

    for (int i = 0; i < strlen(text); i++) {
        freq[text[i]]++;
    }

    struct Node *root = NULL;

    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            root = mergeNodes(root, createNode(i, freq[i]));
        }
    }

    char code[256] = {0};

    printTree(root, 0);
    printCodes(root, code, 0);

    char *encoded_text = encode(text, root);
    printf("Encoded text: %s\n", encoded_text);

    char *decoded_text = decode(encoded_text, root);
    printf("Decoded text: %s\n", decoded_text);

    return 0;
}