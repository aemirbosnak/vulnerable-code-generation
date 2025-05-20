//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node Node;
struct _Node {
    char c;
    int f;
    Node *l;
    Node *r;
};

Node *new_node(char c, int f) {
    Node *node = malloc(sizeof(Node));
    node->c = c;
    node->f = f;
    node->l = node->r = NULL;
    return node;
}

Node *merge_nodes(Node *l, Node *r) {
    Node *node = new_node('\0', l->f + r->f);
    node->l = l;
    node->r = r;
    return node;
}

Node *build_huffman_tree(const char *s) {
    int f[256] = {0};
    for (int i = 0; i < strlen(s); i++) {
        f[s[i]]++;
    }
    
    Node *nodes[256];
    int n = 0;
    for (int i = 0; i < 256; i++) {
        if (f[i] > 0) {
            nodes[n++] = new_node(i, f[i]);
        }
    }
    
    while (n > 1) {
        int min1 = 0, min2 = 1;
        for (int i = 2; i < n; i++) {
            if (nodes[i]->f < nodes[min1]->f) {
                min2 = min1;
                min1 = i;
            } else if (nodes[i]->f < nodes[min2]->f) {
                min2 = i;
            }
        }
        Node *l = nodes[min1];
        Node *r = nodes[min2];
        nodes[min1] = merge_nodes(l, r);
        nodes[min2] = nodes[--n];
    }
    
    return nodes[0];
}

void print_huffman_codes(Node *root, char code[]) {
    if (root->l == NULL && root->r == NULL) {
        printf("%c: %s\n", root->c, code);
    } else {
        code[strlen(code)] = '0';
        print_huffman_codes(root->l, code);
        code[strlen(code) - 1] = '1';
        print_huffman_codes(root->r, code);
    }
}

char *huffman_encode(Node *root, const char *s) {
    int n = strlen(s);
    char *code = malloc(n * 8 + 1);
    int i = 0;
    int j = 0;
    while (i < n) {
        Node *p = root;
        while (p->l != NULL && p->r != NULL) {
            if (s[i] == p->l->c) {
                p = p->l;
                code[j++] = '0';
            } else {
                p = p->r;
                code[j++] = '1';
            }
        }
        code[j++] = '1';
        i++;
    }
    code[j] = '\0';
    return code;
}

char *huffman_decode(Node *root, const char *code) {
    int n = strlen(code);
    char *s = malloc(n + 1);
    int i = 0;
    int j = 0;
    Node *p = root;
    while (i < n) {
        if (code[i] == '0') {
            p = p->l;
        } else {
            p = p->r;
        }
        if (p->l == NULL && p->r == NULL) {
            s[j++] = p->c;
            p = root;
        }
        i++;
    }
    s[j] = '\0';
    return s;
}

int main() {
    const char *s = "abracadabra";
    Node *root = build_huffman_tree(s);
    char code[256] = {0};
    print_huffman_codes(root, code);
    char *encoded = huffman_encode(root, s);
    printf("\nEncoded: %s\n", encoded);
    char *decoded = huffman_decode(root, encoded);
    printf("\nDecoded: %s\n", decoded);
    return 0;
}