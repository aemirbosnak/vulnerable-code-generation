//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 50
#define MAX_VALUE_SIZE 100
#define MAX_INDEX_SIZE 100
#define MAX_TABLE_SIZE 100

struct Index {
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
};

typedef struct Index Index;

struct Table {
    int size;
    Index *indexes;
};

typedef struct Table Table;

Table *createTable() {
    Table *table = (Table *)malloc(sizeof(Table));
    table->size = 0;
    table->indexes = NULL;
    return table;
}

void addIndex(Table *table, char *key, char *value) {
    Index *index = (Index *)malloc(sizeof(Index));
    strcpy(index->key, key);
    strcpy(index->value, value);
    table->indexes = (Index *)realloc(table->indexes, (table->size + 1) * sizeof(Index));
    table->indexes[table->size] = *index;
    table->size++;
}

void printTable(Table *table) {
    int i;
    for (i = 0; i < table->size; i++) {
        printf("Index %d: Key: %s, Value: %s\n", i, table->indexes[i].key, table->indexes[i].value);
    }
}

void freeTable(Table *table) {
    free(table->indexes);
    free(table);
}

int main() {
    Table *table = createTable();

    addIndex(table, "name", "John");
    addIndex(table, "age", "25");
    addIndex(table, "city", "New York");
    addIndex(table, "salary", "50000");

    printTable(table);

    freeTable(table);

    return 0;
}