//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char symbol;
    int freq;
} symbol_t;

typedef struct {
    char symbol;
    char *code;
} code_t;

int compare(const void *a, const void *b) {
    return ((symbol_t *) a)->freq - ((symbol_t *) b)->freq;
}

void generate_codes(symbol_t *symbols, int n, code_t *codes) {
    int i, j, k;
    char *code;

    for (i = 0; i < n; i++) {
        code = malloc(n + 1);
        code[n] = '\0';
        for (j = i, k = n - 1; j >= 0; j--) {
            code[k--] = symbols[j].symbol;
        }
        codes[i].symbol = symbols[i].symbol;
        codes[i].code = code;
    }
}

void print_codes(code_t *codes, int n) {
    int i;

    for (i = 0; i < n; i++) {
        printf("%c: %s\n", codes[i].symbol, codes[i].code);
    }
}

int main() {
    int n;
    symbol_t *symbols;
    code_t *codes;
    char *input, *output;

    printf("Enter the number of symbols: ");
    scanf("%d", &n);

    symbols = malloc(n * sizeof(symbol_t));
    codes = malloc(n * sizeof(code_t));

    printf("Enter the symbols and their frequencies:\n");
    for (int i = 0; i < n; i++) {
        scanf(" %c %d", &symbols[i].symbol, &symbols[i].freq);
    }

    qsort(symbols, n, sizeof(symbol_t), compare);

    generate_codes(symbols, n, codes);

    print_codes(codes, n);

    return 0;
}