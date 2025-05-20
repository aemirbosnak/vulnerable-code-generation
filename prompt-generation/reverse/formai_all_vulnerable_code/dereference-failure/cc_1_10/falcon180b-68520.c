//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CODE 4096
#define MAX_SYMBOL 256

typedef struct {
    char symbol;
    int code;
} Symbol;

typedef struct {
    Symbol *table;
    int count;
} Table;

Table createTable(int size) {
    Table table = {0};
    table.table = (Symbol*)malloc(size * sizeof(Symbol));
    table.count = 0;
    for (int i = 0; i < size; i++) {
        table.table[i].symbol = (char)i;
        table.table[i].code = 0;
    }
    return table;
}

void printTable(Table table) {
    for (int i = 0; i < table.count; i++) {
        printf("%c -> %d\n", table.table[i].symbol, table.table[i].code);
    }
}

void encode(char *input, Table *table) {
    int input_len = strlen(input);
    int i = 0;
    while (i < input_len) {
        int j = 0;
        while (j < table->count && table->table[j].symbol!= input[i]) {
            j++;
        }
        if (j == table->count) {
            table->table[table->count].symbol = input[i];
            table->table[table->count].code = table->count;
            table->count++;
        }
        i++;
    }
}

void decode(char *output, int *index, Table table) {
    while (*index < strlen(output)) {
        int code = output[*index];
        if (code >= 0 && code < table.count) {
            strncat(output, &table.table[code].symbol, 1);
            (*index)++;
        } else {
            printf("Error: Invalid code %d\n", code);
            exit(1);
        }
    }
}

int main() {
    char input[MAX_SYMBOL];
    Table table = createTable(MAX_SYMBOL);
    printf("Enter input string: ");
    scanf("%s", input);
    encode(input, &table);
    printf("Encoded string: ");
    for (int i = 0; i < table.count; i++) {
        printf("%d ", table.table[i].code);
    }
    printf("\n");
    char output[MAX_SYMBOL];
    int index = 0;
    decode(output, &index, table);
    printf("Decoded string: %s\n", output);
    printTable(table);
    return 0;
}