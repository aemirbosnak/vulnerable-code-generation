//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: configurable
#include <stdlib.h>
#include <stdio.h>

#define MAX_CODES 256

typedef struct {
    unsigned char symbol;
    unsigned int frequency;
} HuffmanNode;

typedef struct {
    HuffmanNode nodes[MAX_CODES];
    unsigned int size;
} HuffmanTree;

HuffmanTree* create_tree(unsigned char* data, unsigned int size) {
    HuffmanTree* tree = malloc(sizeof(HuffmanTree));
    tree->size = 0;

    for (unsigned int i = 0; i < size; i++) {
        unsigned char symbol = data[i];
        unsigned int frequency = 0;

        for (unsigned int j = 0; j < size; j++) {
            if (data[j] == symbol) {
                frequency++;
            }
        }

        tree->nodes[tree->size++] = (HuffmanNode) { .symbol = symbol, .frequency = frequency };
    }

    return tree;
}

void sort_tree(HuffmanTree* tree) {
    for (unsigned int i = 0; i < tree->size - 1; i++) {
        for (unsigned int j = i + 1; j < tree->size; j++) {
            if (tree->nodes[i].frequency > tree->nodes[j].frequency) {
                HuffmanNode temp = tree->nodes[i];
                tree->nodes[i] = tree->nodes[j];
                tree->nodes[j] = temp;
            }
        }
    }
}

HuffmanTree* build_tree(HuffmanTree* tree) {
    while (tree->size > 1) {
        HuffmanNode* left = &tree->nodes[0];
        HuffmanNode* right = &tree->nodes[1];

        HuffmanNode parent = (HuffmanNode) { .symbol = '\0', .frequency = left->frequency + right->frequency };

        tree->nodes[0] = parent;
        tree->nodes[1] = tree->nodes[tree->size - 1];

        sort_tree(tree);

        tree->size--;
    }

    return tree;
}

void print_tree(HuffmanTree* tree) {
    for (unsigned int i = 0; i < tree->size; i++) {
        printf("Symbol: %c, Frequency: %d\n", tree->nodes[i].symbol, tree->nodes[i].frequency);
    }
}

void free_tree(HuffmanTree* tree) {
    free(tree);
}

int main() {
    unsigned char data[] = "hello world";
    unsigned int size = sizeof(data) / sizeof(data[0]);

    HuffmanTree* tree = create_tree(data, size);
    sort_tree(tree);
    build_tree(tree);

    print_tree(tree);
    free_tree(tree);

    return 0;
}