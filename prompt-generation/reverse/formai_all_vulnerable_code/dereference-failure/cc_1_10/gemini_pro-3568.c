//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 256
#define MAX_CODE_LENGTH 10

typedef struct node {
    int count;
    char ch;
    struct node *left;
    struct node *right;
} node;

node *nodes[MAX_CHAR];
char codes[MAX_CHAR][MAX_CODE_LENGTH];

void create_tree(char *s) {
    int i;
    int count[MAX_CHAR] = {0};
    int n = strlen(s);
    for (i = 0; i < n; i++) {
        count[s[i]]++;
    }
    for (i = 0; i < MAX_CHAR; i++) {
        if (count[i] > 0) {
            nodes[i] = (node *)malloc(sizeof(node));
            nodes[i]->count = count[i];
            nodes[i]->ch = i;
            nodes[i]->left = NULL;
            nodes[i]->right = NULL;
        }
    }
    while (n > 1) {
        int min1 = -1, min2 = -1;
        int min_count1 = MAX_CHAR, min_count2 = MAX_CHAR;
        for (i = 0; i < MAX_CHAR; i++) {
            if (nodes[i] != NULL && nodes[i]->count < min_count1) {
                min_count1 = nodes[i]->count;
                min1 = i;
            }
        }
        for (i = 0; i < MAX_CHAR; i++) {
            if (nodes[i] != NULL && nodes[i]->count < min_count2 && i != min1) {
                min_count2 = nodes[i]->count;
                min2 = i;
            }
        }
        node *new_node = (node *)malloc(sizeof(node));
        new_node->count = min_count1 + min_count2;
        new_node->ch = 0;
        new_node->left = nodes[min1];
        new_node->right = nodes[min2];
        nodes[min1] = NULL;
        nodes[min2] = NULL;
        nodes[MAX_CHAR - n--] = new_node;
    }
}

void create_codes(node *root, int code[], int top) {
    if (root->left == NULL && root->right == NULL) {
        int i;
        for (i = 0; i < top; i++) {
            codes[root->ch][i] = code[i];
        }
        codes[root->ch][i] = '\0';
        return;
    }
    code[top] = 0;
    create_codes(root->left, code, top + 1);
    code[top] = 1;
    create_codes(root->right, code, top + 1);
}

void encode(char *s) {
    int i, n = strlen(s);
    int code[MAX_CODE_LENGTH];
    create_tree(s);
    create_codes(nodes[MAX_CHAR - 1], code, 0);
    for (i = 0; i < n; i++) {
        printf("%s", codes[s[i]]);
    }
}

void decode(char *s) {
    int i, j, n = strlen(s);
    node *root = nodes[MAX_CHAR - 1];
    for (i = 0; i < n; i++) {
        if (s[i] == '0') {
            root = root->left;
        } else {
            root = root->right;
        }
        if (root->left == NULL && root->right == NULL) {
            printf("%c", root->ch);
            root = nodes[MAX_CHAR - 1];
        }
    }
}

int main() {
    char s[] = "Hello, world!";
    printf("Original string: %s\n", s);
    printf("Encoded string: ");
    encode(s);
    printf("\nDecoded string: ");
    decode(s);
    printf("\n");
    return 0;
}