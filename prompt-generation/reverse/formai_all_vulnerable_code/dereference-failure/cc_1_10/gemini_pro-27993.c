//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_LENGTH 100

typedef struct {
    unsigned char symbol;
    unsigned int frequency;
} symbol_t;

typedef struct {
    symbol_t *symbols;
    unsigned int num_symbols;
} symbol_table_t;

typedef struct {
    unsigned char *code;
    unsigned int length;
} code_t;

typedef struct {
    symbol_table_t *symbol_table;
    code_t *codes;
} huffman_tree_t;

huffman_tree_t *create_huffman_tree(symbol_table_t *symbol_table) {
    huffman_tree_t *tree = malloc(sizeof(huffman_tree_t));
    tree->symbol_table = symbol_table;

    unsigned int num_symbols = symbol_table->num_symbols;
    tree->codes = malloc(sizeof(code_t) * num_symbols);

    for (unsigned int i = 0; i < num_symbols; i++) {
        tree->codes[i].code = malloc(sizeof(unsigned char) * MAX_CODE_LENGTH);
        tree->codes[i].length = 0;
    }

    return tree;
}

void free_huffman_tree(huffman_tree_t *tree) {
    for (unsigned int i = 0; i < tree->symbol_table->num_symbols; i++) {
        free(tree->codes[i].code);
    }

    free(tree->codes);
    free(tree->symbol_table->symbols);
    free(tree->symbol_table);
    free(tree);
}

void print_huffman_tree(huffman_tree_t *tree) {
    for (unsigned int i = 0; i < tree->symbol_table->num_symbols; i++) {
        printf("%c: ", tree->symbol_table->symbols[i].symbol);
        for (unsigned int j = 0; j < tree->codes[i].length; j++) {
            printf("%d", tree->codes[i].code[j]);
        }
        printf("\n");
    }
}

void generate_huffman_codes(huffman_tree_t *tree, unsigned char *code, unsigned int length, unsigned int index) {
    if (index == tree->symbol_table->num_symbols) {
        return;
    }

    code[length] = 0;
    generate_huffman_codes(tree, code, length + 1, index);

    code[length] = 1;
    tree->codes[index].code[tree->codes[index].length++] = code[length];
    generate_huffman_codes(tree, code, length + 1, index + 1);
}

int main() {
    symbol_table_t *symbol_table = malloc(sizeof(symbol_table_t));
    symbol_table->symbols = malloc(sizeof(symbol_t) * 5);
    symbol_table->num_symbols = 5;

    symbol_table->symbols[0].symbol = 'a';
    symbol_table->symbols[0].frequency = 5;
    symbol_table->symbols[1].symbol = 'b';
    symbol_table->symbols[1].frequency = 3;
    symbol_table->symbols[2].symbol = 'c';
    symbol_table->symbols[2].frequency = 2;
    symbol_table->symbols[3].symbol = 'd';
    symbol_table->symbols[3].frequency = 1;
    symbol_table->symbols[4].symbol = 'e';
    symbol_table->symbols[4].frequency = 1;

    huffman_tree_t *tree = create_huffman_tree(symbol_table);
    unsigned char code[MAX_CODE_LENGTH];
    generate_huffman_codes(tree, code, 0, 0);
    print_huffman_tree(tree);
    free_huffman_tree(tree);
    free(symbol_table->symbols);
    free(symbol_table);

    return 0;
}