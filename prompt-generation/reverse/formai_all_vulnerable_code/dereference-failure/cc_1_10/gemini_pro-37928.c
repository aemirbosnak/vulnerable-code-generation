//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int freq;
    char c;
    struct node *left, *right;
} node;

typedef struct huff_table {
    char c;
    char *code;
} huff_table;

node *create_node(char c, int freq) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->c = c;
    new_node->freq = freq;
    new_node->left = new_node->right = NULL;
    return new_node;
}

node *build_tree(char *str) {
    int n = strlen(str);
    int freq[256] = {0};
    for (int i = 0; i < n; i++) {
        freq[str[i]]++;
    }
    node *priority_queue[n];
    int front = 0, rear = -1;
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            priority_queue[++rear] = create_node(i, freq[i]);
        }
    }
    while (rear > 0) {
        node *left = priority_queue[front++];
        node *right = priority_queue[front++];
        node *parent = create_node('\0', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        priority_queue[++rear] = parent;
    }
    return priority_queue[front];
}

void print_code(node *root, char *code) {
    if (root == NULL) {
        return;
    }
    if (root->c != '\0') {
        printf("%c: %s\n", root->c, code);
    }
    print_code(root->left, strcat(code, "0"));
    print_code(root->right, strcat(code, "1"));
}

huff_table *create_huff_table(node *root) {
    int n = 0;
    node *queue[1000];
    int front = 0, rear = -1;
    queue[++rear] = root;
    while (front <= rear) {
        node *current = queue[front++];
        if (current->c != '\0') {
            n++;
        }
        if (current->left != NULL) {
            queue[++rear] = current->left;
        }
        if (current->right != NULL) {
            queue[++rear] = current->right;
        }
    }
    huff_table *table = (huff_table *)malloc(sizeof(huff_table) * n);
    front = 0, rear = -1;
    queue[++rear] = root;
    int i = 0;
    while (front <= rear) {
        node *current = queue[front++];
        if (current->c != '\0') {
            table[i].c = current->c;
            table[i++].code = (char *)malloc(sizeof(char) * 100);
        }
        if (current->left != NULL) {
            queue[++rear] = current->left;
        }
        if (current->right != NULL) {
            queue[++rear] = current->right;
        }
    }
    return table;
}

void encode(char *str, huff_table *table, int n) {
    char code[1000] = "";
    for (int i = 0; i < strlen(str); i++) {
        for (int j = 0; j < n; j++) {
            if (str[i] == table[j].c) {
                strcat(code, table[j].code);
            }
        }
    }
    printf("Encoded code: %s\n", code);
}

void decode(char *code, huff_table *table, int n) {
    node *root = build_tree(code);
    node *current = root;
    char decoded[1000] = "";
    for (int i = 0; i < strlen(code); i++) {
        if (code[i] == '0') {
            current = current->left;
        } else {
            current = current->right;
        }
        if (current->c != '\0') {
            strcat(decoded, &current->c);
            current = root;
        }
    }
    printf("Decoded string: %s\n", decoded);
}

int main() {
    char str[] = "Hello World!";
    node *root = build_tree(str);
    char code[1000] = "";
    print_code(root, code);
    huff_table *table = create_huff_table(root);
    int n = 0;
    while (table[n].c != '\0') {
        n++;
    }
    encode(str, table, n);
    decode(code, table, n);
    return 0;
}