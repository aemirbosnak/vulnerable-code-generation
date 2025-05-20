//FormAI DATASET v1.0 Category: System administration ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

/*
 * This program is a simple file compression/decompression tool written in C
 * It uses a Huffman encoding algorithm and works in the following manner:
 *
 * To compress a file:
 *
 * ./huffman compress input_file output_file
 *
 * To decompress a file:
 *
 * ./huffman decompress input_file output_file
 */

typedef struct {
    char symbol;
    int frequency;
    char *code;
} Symbol;

typedef struct {
    Symbol *symbol;
    int num_symbols;
} SymbolTable;

SymbolTable *get_symbol_table(char *filename);
void free_symbol_table(SymbolTable *table);
void build_code_table(SymbolTable *table);
void compress(char *input_filename, char *output_filename);
void decompress(char *input_filename, char *output_filename);

int main(int argc, char **argv) {
    if (argc != 4) {
        printf("Usage: huffman [compress/decompress] input output\n");
        return 1;
    }

    if (strcmp(argv[1], "compress") == 0) {
        compress(argv[2], argv[3]);
    } else if (strcmp(argv[1], "decompress") == 0) {
        decompress(argv[2], argv[3]);
    } else {
        printf("Invalid operation: %s. Use either 'compress' or 'decompress'\n", argv[1]);
        return 1;
    }

    return 0;
}

SymbolTable *get_symbol_table(char *filename) {
    FILE *input_file = fopen(filename, "r");

    if (input_file == NULL) {
        printf("Cannot open file: %s\n", filename);
        return NULL;
    }

    SymbolTable *table = malloc(sizeof(SymbolTable));
    Symbol *symbols = malloc(sizeof(Symbol) * 256);
    int i;

    for (i = 0; i < 256; i++) {
        symbols[i].symbol = i;
        symbols[i].frequency = 0;
        symbols[i].code = NULL;
    }

    int c;

    while ((c = fgetc(input_file)) != EOF) {
        symbols[c].frequency += 1;
    }

    table->num_symbols = 0;

    for (i = 0; i < 256; i++) {
        if (symbols[i].frequency > 0) {
            table->num_symbols += 1;
        }
    }

    table->symbol = malloc(sizeof(Symbol) * table->num_symbols);

    int j = 0;

    for (i = 0; i < 256; i++) {
        if (symbols[i].frequency > 0) {
            table->symbol[j] = symbols[i];
            j++;
        }
    }

    free(symbols);
    fclose(input_file);
    return table;
}

void free_symbol_table(SymbolTable *table) {
    int i;

    for (i = 0; i < table->num_symbols; i++) {
        if (table->symbol[i].code != NULL) {
            free(table->symbol[i].code);
        }
    }

    free(table->symbol);
    free(table);
}

void build_code_table(SymbolTable *table) {
    int i, j, k;

    for (i = 0; i < table->num_symbols - 1; i++) {
        for (j = i + 1; j < table->num_symbols; j++) {
            if (table->symbol[i].frequency > table->symbol[j].frequency) {
                Symbol temp = table->symbol[i];
                table->symbol[i] = table->symbol[j];
                table->symbol[j] = temp;
            }
        }
    }

    int *left_child = calloc(table->num_symbols, sizeof(int));
    int *right_child = calloc(table->num_symbols, sizeof(int));
    int *parent = calloc(table->num_symbols, sizeof(int));
    int *path = calloc(table->num_symbols, sizeof(int));
    int *length = calloc(table->num_symbols, sizeof(int));
    int position = 0;
    int code_length = 0;

    while (position < table->num_symbols - 1) {
        int min1 = -1;
        int min2 = -1;

        for (i = 0; i <= position; i++) {
            if (parent[i] == -1) {
                if (min1 == -1 || table->symbol[i].frequency < table->symbol[min1].frequency) {
                    min2 = min1;
                    min1 = i;
                } else if (min2 == -1 || table->symbol[i].frequency < table->symbol[min2].frequency) {
                    min2 = i;
                }
            }
        }

        left_child[position] = min1;
        right_child[position] = min2;
        parent[min1] = position;
        parent[min2] = position;
        table->symbol[position].symbol = 0;
        table->symbol[position].frequency = table->symbol[min1].frequency + table->symbol[min2].frequency;
        position++;
    }

    int root = position - 1;

    for (i = 0; i < table->num_symbols; i++) {
        position = i;
        code_length = 0;

        while (position != root) {
            int p = parent[position];

            if (left_child[p] == position) {
                path[code_length] = 0;
            } else {
                path[code_length] = 1;
            }

            code_length++;
            position = p;
        }

        table->symbol[i].code = malloc(sizeof(char) * (code_length + 1));

        for (j = 0, k = code_length - 1; j < code_length; j++, k--) {
            table->symbol[i].code[j] = path[k] + '0';
        }

        table->symbol[i].code[code_length] = '\0';
        length[i] = code_length;
    }

    free(left_child);
    free(right_child);
    free(parent);
    free(path);
    free(length);
}

void compress(char *input_filename, char *output_filename) {
    SymbolTable *table = get_symbol_table(input_filename);

    if (table == NULL) {
        printf("Cannot compress file: %s\n", input_filename);
        return;
    }

    build_code_table(table);
    FILE *input_file = fopen(input_filename, "r");
    FILE *output_file = fopen(output_filename, "w");
    int i, c;

    for (i = 0; i < table->num_symbols; i++) {
        fprintf(output_file, "%c:%s\n", table->symbol[i].symbol, table->symbol[i].code);
    }

    fprintf(output_file, "=====\n");

    while ((c = fgetc(input_file)) != EOF) {
        for (i = 0; i < table->num_symbols; i++) {
            if (table->symbol[i].symbol == c) {
                fprintf(output_file, "%s", table->symbol[i].code);
                break;
            }
        }
    }

    fclose(input_file);
    fclose(output_file);
    free_symbol_table(table);
    printf("File %s compressed into file %s.\n", input_filename, output_filename);
}

void decompress(char *input_filename, char *output_filename) {
    SymbolTable *table = malloc(sizeof(SymbolTable));
    table->symbol = malloc(sizeof(Symbol) * 256);
    table->num_symbols = 0;
    FILE *input_file = fopen(input_filename, "r");
    FILE *output_file = fopen(output_filename, "w");
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int i, j;

    while ((read = getline(&line, &len, input_file)) != -1) {
        if (strcmp(line, "=====\n") == 0) {
            break;
        }

        table->symbol[table->num_symbols].symbol = line[0];

        // Skip the colon
        for (i = 2, j = 0; line[i] != '\n'; i++, j++) {
            table->symbol[table->num_symbols].code[j] = line[i];
        }

        table->symbol[table->num_symbols].code[j] = '\0';
        table->num_symbols++;
    }

    while ((read = getline(&line, &len, input_file)) != -1) {
        int position = 0;
        int code_length = strlen(line) - 1;

        while (code_length > 0) {
            for (i = 0; i < table->num_symbols; i++) {
                if (strlen(table->symbol[i].code) <= code_length &&
                    strncmp(line + position, table->symbol[i].code, strlen(table->symbol[i].code)) == 0) {
                    fputc(table->symbol[i].symbol, output_file);
                    code_length -= strlen(table->symbol[i].code);
                    position += strlen(table->symbol[i].code);
                    break;
                }
            }
        }
    }

    fclose(input_file);
    fclose(output_file);
    free(line);
    free_symbol_table(table);
    printf("File %s decompressed into file %s.\n", input_filename, output_filename);
}