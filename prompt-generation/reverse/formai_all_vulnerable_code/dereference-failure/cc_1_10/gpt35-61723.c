//FormAI DATASET v1.0 Category: Image compression ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int value;
    int freq;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct List {
    Node *node;
    struct List *next;
} List;

List *insert_sorted(List *list, Node *node) {
    List *current = list;
    List *previous = NULL;
    while (current != NULL && node->freq > current->node->freq) {
        previous = current;
        current = current->next;
    }
    List *new = (List *)malloc(sizeof(List));
    new->node = node;
    new->next = current;
    if (previous) {
        previous->next = new;
        return list;
    } else {
        return new;
    }
}

List *build_huffman_tree(int *freqs, int size) {
    List *list = NULL;
    for (int i = 0; i < size; i++) {
        if (freqs[i] > 0) {
            Node *node = (Node *)malloc(sizeof(Node));
            node->value = i;
            node->freq = freqs[i];
            node->left = NULL;
            node->right = NULL;
            list = insert_sorted(list, node);
        }
    }
    while (list->next != NULL) {
        Node *left = list->node;
        Node *right = list->next->node;
        Node *parent = (Node *)malloc(sizeof(Node));
        parent->value = -1;
        parent->freq = left->freq + right->freq;
        parent->left = left;
        parent->right = right;
        list = list->next->next;
        list = insert_sorted(list, parent);
    }
    return list->node;
}

void encode(Node *root, int *table, int code, int length) {
    if (root->left == NULL && root->right == NULL) {
        table[root->value] = (code << 8) | length;
    } else {
        encode(root->left, table, code << 1, length + 1);
        encode(root->right, table, (code << 1) | 1, length + 1);
    }
}

void compress(int *pixels, int size, int *freqs, char *filename) {
    Node *root = build_huffman_tree(freqs, size);
    int table[256];
    memset(table, 0, sizeof(table));
    encode(root, table, 0, 0);
    FILE *file = fopen(filename, "wb");
    fwrite(freqs, sizeof(int), 256, file);
    int buffer = 0;
    int bits = 0;
    for (int i = 0; i < size; i++) {
        int code = table[pixels[i]];
        int length = code & 0xff;
        code >>= 8;
        buffer = (buffer << length) | code;
        bits += length;
        while (bits >= 8) {
            fwrite(&buffer, sizeof(char), 1, file);
            buffer >>= 8;
            bits -= 8;
        }
    }
    if (bits > 0) {
        buffer <<= (8 - bits);
        fwrite(&buffer, sizeof(char), 1, file);
    }
    fclose(file);
}

int *count_pixels(int *pixels, int size) {
    int *freqs = (int *)calloc(256, sizeof(int));
    for (int i = 0; i < size; i++) {
        freqs[pixels[i]]++;
    }
    return freqs;
}

int *read_file(char *filename, int *size) {
    FILE *file = fopen(filename, "rb");
    fseek(file, 0, SEEK_END);
    *size = ftell(file) / sizeof(int);
    fseek(file, 0, SEEK_SET);
    int *pixels = (int *)malloc(*size * sizeof(int));
    fread(pixels, sizeof(int), *size, file);
    fclose(file);
    return pixels;
}

int main() {
    int size;
    int *pixels = read_file("image.dat", &size);
    int *freqs = count_pixels(pixels, size);
    compress(pixels, size, freqs, "image.bin");
    free(freqs);
    free(pixels);
    return 0;
}