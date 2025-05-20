//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 256

typedef struct node {
    char ch;
    int freq;
    struct node *left, *right;
} node_t;

typedef struct {
    node_t *root;
    char *code;
    int code_len;
} huffman_t;

huffman_t *create_huffman(char *str) {
    int freq[MAX_CHAR] = {0};
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        freq[str[i]]++;
    }

    node_t *nodes[MAX_CHAR];
    int count = 0;
    for (char ch = 0; ch < MAX_CHAR; ch++) {
        if (freq[ch] > 0) {
            nodes[count++] = (node_t *)malloc(sizeof(node_t));
            nodes[count - 1]->ch = ch;
            nodes[count - 1]->freq = freq[ch];
            nodes[count - 1]->left = nodes[count - 1]->right = NULL;
        }
    }

    while (count > 1) {
        int min1 = 0, min2 = 1;
        for (int i = 0; i < count - 1; i++) {
            if (nodes[i]->freq < nodes[min1]->freq) {
                min2 = min1;
                min1 = i;
            } else if (nodes[i]->freq < nodes[min2]->freq) {
                min2 = i;
            }
        }

        node_t *new_node = (node_t *)malloc(sizeof(node_t));
        new_node->ch = '\0';
        new_node->freq = nodes[min1]->freq + nodes[min2]->freq;
        new_node->left = nodes[min1];
        new_node->right = nodes[min2];
        nodes[min1] = new_node;
        nodes[min2] = NULL;
        count--;
    }

    huffman_t *huff = (huffman_t *)malloc(sizeof(huffman_t));
    huff->root = nodes[0];
    huff->code = (char *)malloc(sizeof(char) * (len + 1));
    huff->code_len = 0;
    return huff;
}

void encode(huffman_t *huff, char *str, char *enc) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        node_t *curr = huff->root;
        while (curr->left || curr->right) {
            if (str[i] == curr->ch) {
                break;
            } else if (str[i] < curr->ch) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
        enc[huff->code_len++] = curr->ch;
    }
    enc[huff->code_len] = '\0';
}

void decode(huffman_t *huff, char *enc, char *dec) {
    int len = strlen(enc);
    node_t *curr = huff->root;
    for (int i = 0; i < len; i++) {
        if (enc[i] == '0') {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
        if (!curr->left && !curr->right) {
            dec[i] = curr->ch;
            curr = huff->root;
        }
    }
    dec[len] = '\0';
}

int main() {
    char str[] = "Huffman Coding";
    huffman_t *huff = create_huffman(str);
    char enc[strlen(str) + 1];
    encode(huff, str, enc);
    printf("Encoded: %s\n", enc);
    char dec[strlen(str) + 1];
    decode(huff, enc, dec);
    printf("Decoded: %s\n", dec);
    return 0;
}