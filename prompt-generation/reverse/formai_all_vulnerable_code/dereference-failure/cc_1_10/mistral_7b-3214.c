//MISTRAL-7B DATASET v1.0 Category: Compression algorithms ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024
#define MIN_FREQUENCY 5

typedef struct {
    char symbol;
    int freq;
} Symbol;

typedef struct {
    int size;
    Symbol *symbols;
} FreqTable;

void build_freq_table(const char *input, FreqTable *freq_table) {
    int i, len = strlen(input);
    freq_table->size = len;
    freq_table->symbols = calloc(len + 1, sizeof(Symbol));

    for (i = 0; i < len; ++i) {
        Symbol *symbol = &freq_table->symbols[input[i]];
        symbol->symbol = input[i];
        symbol->freq = 0;
    }

    for (i = 0; i < len; ++i) {
        Symbol *symbol = &freq_table->symbols[input[i]];
        ++symbol->freq;
    }
}

void encode(const FreqTable *freq_table, char *output, const char *input) {
    int i, len = strlen(input);
    for (i = 0; i < len; ++i) {
        Symbol *symbol = &freq_table->symbols[input[i]];
        output[i] = symbol->symbol;
    }

    for (i = len; i < BUF_SIZE; ++i) {
        Symbol *symbol = &freq_table->symbols[*((char *)memchr(freq_table->symbols, MIN_FREQUENCY, len * sizeof(Symbol)))];
        output[i] = symbol->symbol;
        if (--symbol->freq == 0) {
            free(freq_table->symbols);
            exit(1);
        }
    }
}

void decode(const FreqTable *freq_table, char *output, const char *input) {
    int i, len = strlen(input);

    for (i = 0; i < len; ++i) {
        Symbol *symbol = &freq_table->symbols[input[i]];
        output[symbol->freq++] = input[i];
    }

    for (; freq_table->symbols[0].freq > 0; ++output[--freq_table->symbols[0].freq]) {}
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <input> <output>\n", argv[0]);
        return 1;
    }

    FreqTable freq_table;
    build_freq_table(argv[1], &freq_table);

    char *output = calloc(BUF_SIZE, sizeof(char));
    encode(&freq_table, output, argv[1]);

    FILE *fp = fopen(argv[2], "wb");
    fwrite(output, 1, strlen(output), fp);
    fclose(fp);

    free(output);
    free(freq_table.symbols);

    printf("Compressed %s to %s\n", argv[1], argv[2]);
    return 0;
}