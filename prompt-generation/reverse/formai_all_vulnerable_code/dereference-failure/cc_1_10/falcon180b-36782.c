//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_LENGTH 12
#define MAX_CODE_TABLE_SIZE 4096
#define EOF_CODE 256

typedef struct {
    int code;
    char *string;
} CodeTableEntry;

typedef struct {
    CodeTableEntry *table;
    int tableSize;
    int nextCode;
} CodeTable;

void initCodeTable(CodeTable *table) {
    table->table = malloc(sizeof(CodeTableEntry) * MAX_CODE_TABLE_SIZE);
    table->tableSize = 0;
    table->nextCode = 257;
}

void addEntry(CodeTable *table, int code, char *string) {
    if (table->tableSize >= MAX_CODE_TABLE_SIZE) {
        printf("Error: Code table is full.\n");
        exit(1);
    }
    table->table[table->tableSize].code = code;
    table->table[table->tableSize].string = strdup(string);
    table->tableSize++;
}

void printCodeTable(CodeTable *table) {
    printf("Code Table:\n");
    for (int i = 0; i < table->tableSize; i++) {
        printf("%d: %s\n", table->table[i].code, table->table[i].string);
    }
}

int getCode(CodeTable *table, char *string) {
    for (int i = 0; i < table->tableSize; i++) {
        if (strcmp(table->table[i].string, string) == 0) {
            return table->table[i].code;
        }
    }
    addEntry(table, table->nextCode++, string);
    return table->nextCode - 1;
}

int main() {
    CodeTable table;
    initCodeTable(&table);

    char inputString[100];
    printf("Enter input string: ");
    scanf("%s", inputString);

    int inputCode = getCode(&table, inputString);
    printf("Input code: %d\n", inputCode);

    return 0;
}