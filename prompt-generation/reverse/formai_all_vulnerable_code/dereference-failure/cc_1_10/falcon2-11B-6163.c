//Falcon2-11B DATASET v1.0 Category: Huffman Coding Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUF_SIZE 1024

typedef struct Node {
    int freq;
    char *str;
    struct Node *left, *right;
} Node;

Node *build_tree(char *strs[], int n) {
    Node *root = NULL;
    for (int i = 0; i < n; i++) {
        if (!root) {
            root = (Node *)malloc(sizeof(Node));
            root->str = strs[i];
            root->freq = 1;
            root->left = root->right = NULL;
        } else {
            Node *new_node = (Node *)malloc(sizeof(Node));
            new_node->str = strs[i];
            new_node->freq = 1;
            new_node->left = root;
            root->freq += 1;
            root->left = new_node;
        }
    }
    return root;
}

void print_tree(Node *root) {
    if (!root) {
        printf("Empty tree\n");
        return;
    }
    printf("%s\t", root->str);
    print_tree(root->left);
    print_tree(root->right);
}

char *compress(char *str, Node *root) {
    if (!root ||!str) {
        return NULL;
    }
    char *buf = (char *)malloc(BUF_SIZE * sizeof(char));
    char c;
    int i = 0;
    while ((c = *str++)!= '\0') {
        if (root->str && strcmp(root->str, c) == 0) {
            buf[i] = root->freq;
            i++;
            Node *curr = root;
            while (curr->right) {
                curr = curr->right;
            }
            Node *last = curr;
            while (last->left) {
                last = last->left;
            }
            if (last->freq == 0) {
                root->freq += 1;
                root->right = last->right;
                root->right->left = NULL;
                last->right = NULL;
            } else {
                last->freq += 1;
                root->freq -= 1;
                root->right = last->right;
                root->right->left = root;
                last->right = NULL;
            }
        } else {
            buf[i++] = c;
        }
    }
    buf[i] = '\0';
    return buf;
}

char *decompress(char *buf, int len, Node *root) {
    char *str = (char *)malloc(len + 1);
    int i = 0;
    while (i < len) {
        if (buf[i] >= 0) {
            str[i] = buf[i];
            i++;
        } else {
            Node *curr = root;
            while (curr->str && strcmp(curr->str, buf[i + 1])!= 0) {
                curr = curr->right;
            }
            if (curr->str) {
                str[i] = curr->str[0];
                i++;
                Node *last = curr;
                while (last->left) {
                    last = last->left;
                }
                last->freq += 1;
                curr->freq -= 1;
                curr->right = last->right;
                curr->right->left = curr;
                last->right = NULL;
            } else {
                printf("Error: invalid character\n");
                return NULL;
            }
        }
    }
    str[i] = '\0';
    return str;
}

int main() {
    char *strs[] = {"a", "b", "c", "d", "e", "f"};
    int n = sizeof(strs) / sizeof(strs[0]);
    Node *root = build_tree(strs, n);
    print_tree(root);

    char *compressed = compress("aaabbcdef", root);
    printf("Compressed: %s\n", compressed);
    char *decompressed = decompress(compressed, strlen(compressed), root);
    printf("Decompressed: %s\n", decompressed);

    return 0;
}