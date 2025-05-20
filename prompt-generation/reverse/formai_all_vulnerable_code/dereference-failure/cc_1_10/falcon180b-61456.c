//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char *key;
    char *value;
} KeyValuePair;

typedef struct {
    KeyValuePair *pairs;
    int count;
} KeyValueTable;

void initTable(KeyValueTable *table) {
    table->pairs = NULL;
    table->count = 0;
}

void addPair(KeyValueTable *table, char *key, char *value) {
    KeyValuePair *pair = malloc(sizeof(KeyValuePair));
    pair->key = strdup(key);
    pair->value = strdup(value);
    table->pairs = realloc(table->pairs, sizeof(KeyValuePair) * ++table->count);
    table->pairs[table->count - 1] = *pair;
}

void printTable(KeyValueTable *table) {
    if (table->count == 0) {
        printf("No data available.\n");
        return;
    }

    printf("Key\tValue\n");
    for (int i = 0; i < table->count; i++) {
        printf("%s\t%s\n", table->pairs[i].key, table->pairs[i].value);
    }
}

void freeTable(KeyValueTable *table) {
    for (int i = 0; i < table->count; i++) {
        free(table->pairs[i].key);
        free(table->pairs[i].value);
    }
    free(table->pairs);
    table->pairs = NULL;
    table->count = 0;
}

int main(int argc, char **argv) {
    FILE *inputFile;
    char line[MAX_LINE_SIZE];
    char *key, *value;
    KeyValueTable table;

    initTable(&table);

    inputFile = fopen("data.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_SIZE, inputFile)!= NULL) {
        if (line[0] == '#' || line[0] == '\n') {
            continue;
        }

        key = strtok(line, ":");
        value = strtok(NULL, ":");
        if (key == NULL || value == NULL) {
            printf("Invalid data format.\n");
            continue;
        }

        addPair(&table, key, value);
    }

    fclose(inputFile);

    printTable(&table);

    freeTable(&table);

    return 0;
}