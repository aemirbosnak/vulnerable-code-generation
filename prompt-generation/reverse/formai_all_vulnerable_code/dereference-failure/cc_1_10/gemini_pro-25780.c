//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    unsigned char character;
    unsigned int frequency;
    struct node *left, *right;
} node_t;

node_t *create_node(unsigned char character, unsigned int frequency) {
    node_t *node = malloc(sizeof(node_t));
    node->character = character;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;
    return node;
}

node_t *merge_nodes(node_t *left, node_t *right) {
    node_t *node = create_node('\0', left->frequency + right->frequency);
    node->left = left;
    node->right = right;
    return node;
}

void print_tree(node_t *node) {
    if (node->left) {
        printf("(");
        print_tree(node->left);
        printf(",");
        print_tree(node->right);
        printf(")");
    } else {
        printf("'%c': %d", node->character, node->frequency);
    }
}

void free_tree(node_t *node) {
    if (node->left) {
        free_tree(node->left);
        free_tree(node->right);
    }
    free(node);
}

unsigned int *get_frequencies(unsigned char *text, unsigned int length) {
    unsigned int *frequencies = calloc(256, sizeof(unsigned int));
    for (unsigned int i = 0; i < length; i++) {
        frequencies[text[i]]++;
    }
    return frequencies;
}

node_t *build_huffman_tree(unsigned char *text, unsigned int length) {
    unsigned int *frequencies = get_frequencies(text, length);
    node_t *nodes[256];
    for (unsigned int i = 0; i < 256; i++) {
        if (frequencies[i] > 0) {
            nodes[i] = create_node(i, frequencies[i]);
        }
    }
    while (1) {
        node_t *left = NULL, *right = NULL;
        unsigned int min_frequency = -1;
        for (unsigned int i = 0; i < 256; i++) {
            if (nodes[i] && (left == NULL || nodes[i]->frequency < min_frequency)) {
                left = nodes[i];
                min_frequency = left->frequency;
            }
        }
        for (unsigned int i = 0; i < 256; i++) {
            if (nodes[i] && (right == NULL || nodes[i]->frequency < min_frequency)) {
                right = nodes[i];
                min_frequency = right->frequency;
            }
        }
        if (left == NULL || right == NULL) {
            break;
        }
        nodes[left->character] = NULL;
        nodes[right->character] = NULL;
        node_t *parent = merge_nodes(left, right);
        for (unsigned int i = 0; i < 256; i++) {
            if (nodes[i] == NULL) {
                nodes[i] = parent;
            }
        }
    }
    return nodes[0];
}

unsigned char *encode_huffman(node_t *tree, unsigned char *text, unsigned int length) {
    unsigned char *encoded_text = malloc(length * 8 + 1);
    unsigned int index = 0;
    for (unsigned int i = 0; i < length; i++) {
        node_t *node = tree;
        while (node->left || node->right) {
            if (text[i] == node->character) {
                break;
            }
            if (text[i] < node->character) {
                node = node->left;
            } else {
                node = node->right;
            }
        }
        unsigned char code[8];
        for (int j = 7; j >= 0; j--) {
            code[j] = node->character & 1;
            node->character >>= 1;
        }
        for (int j = 7; j >= 0; j--) {
            encoded_text[index++] = code[j] + '0';
        }
    }
    encoded_text[index] = '\0';
    return encoded_text;
}

unsigned char *decode_huffman(node_t *tree, unsigned char *encoded_text, unsigned int length) {
    unsigned char *decoded_text = malloc(length);
    unsigned int index = 0;
    node_t *node = tree;
    for (unsigned int i = 0; i < length; i++) {
        if (encoded_text[i] == '0') {
            node = node->left;
        } else if (encoded_text[i] == '1') {
            node = node->right;
        }
        if (node->left == NULL && node->right == NULL) {
            decoded_text[index++] = node->character;
            node = tree;
        }
    }
    decoded_text[index] = '\0';
    return decoded_text;
}

int main() {
    unsigned char *text = "Elementary, my dear Watson.";
    unsigned int length = strlen(text);
    node_t *tree = build_huffman_tree(text, length);
    print_tree(tree);
    printf("\n");
    unsigned char *encoded_text = encode_huffman(tree, text, length);
    printf("Encoded text: %s\n", encoded_text);
    unsigned char *decoded_text = decode_huffman(tree, encoded_text, strlen(encoded_text));
    printf("Decoded text: %s\n", decoded_text);
    free_tree(tree);
    free(encoded_text);
    free(decoded_text);
    return 0;
}