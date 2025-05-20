//MISTRAL-7B DATASET v1.0 Category: Alien Language Translator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SYMBOLS 128
#define MAX_LINE 256
#define MAX_Tokens 32

typedef struct {
    char symbol;
    char* translation;
} SymbolTable;

SymbolTable symbol_table[MAX_SYMBOLS] = {0};
int symbol_table_size = 0;

void addSymbol(char symbol, char* translation) {
    if (symbol_table_size >= MAX_SYMBOLS) {
        fprintf(stderr, "Error: Symbol table is full.\n");
        exit(EXIT_FAILURE);
    }
    symbol_table[symbol_table_size].symbol = symbol;
    symbol_table[symbol_table_size++].translation = strdup(translation);
}

void loadSymbolsFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE] = {0};
    char* token = NULL;
    char symbol;
    char* translation = NULL;

    while (fgets(line, MAX_LINE, file) != NULL) {
        char* token_start = strtok_r(line, " \t\n\r\f\v", &token);
        if (token_start != NULL) {
            symbol = *token_start;
            token_start += strlen(token_start);
            translation = strtok_r(NULL, ":\n\r\f\v", &token);
            addSymbol(symbol, translation);
        }
    }

    fclose(file);
}

void translate(const char* input) {
    int i;
    for (i = 0; input[i] != '\0'; i++) {
        for (int j = 0; j < symbol_table_size; j++) {
            if (input[i] == symbol_table[j].symbol) {
                printf("%s ", symbol_table[j].translation);
                break;
            }
        }
        putchar(input[i]);
    }
    printf("\n");
}

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <alien_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    loadSymbolsFile("symbols.txt");
    const char* input = argv[1];
    translate(input);

    return EXIT_SUCCESS;
}