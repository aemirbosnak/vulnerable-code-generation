//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_KEY_LENGTH 64
#define MAX_VALUE_LENGTH 256

typedef struct {
    char *key;
    char *value;
} KeyValuePair;

typedef struct {
    KeyValuePair **pairs;
    int count;
} KeyValueTable;

KeyValuePair *createKeyValuePair(char *key, char *value) {
    KeyValuePair *pair = (KeyValuePair *)malloc(sizeof(KeyValuePair));
    pair->key = strdup(key);
    pair->value = strdup(value);
    return pair;
}

void destroyKeyValuePair(KeyValuePair *pair) {
    free(pair->key);
    free(pair->value);
    free(pair);
}

KeyValueTable *createKeyValueTable() {
    KeyValueTable *table = (KeyValueTable *)malloc(sizeof(KeyValueTable));
    table->pairs = NULL;
    table->count = 0;
    return table;
}

void destroyKeyValueTable(KeyValueTable *table) {
    for (int i = 0; i < table->count; i++) {
        destroyKeyValuePair(table->pairs[i]);
    }
    free(table->pairs);
    free(table);
}

void addKeyValuePair(KeyValueTable *table, char *key, char *value) {
    table->pairs = realloc(table->pairs, sizeof(KeyValuePair *) * (table->count + 1));
    table->pairs[table->count] = createKeyValuePair(key, value);
    table->count++;
}

int main() {
    char line[MAX_LINE_LENGTH];
    char *key, *value;
    KeyValueTable *table = createKeyValueTable();

    while (fgets(line, MAX_LINE_LENGTH, stdin)!= NULL) {
        key = strtok(line, ",");
        value = strtok(NULL, ",");
        if (key!= NULL && value!= NULL) {
            addKeyValuePair(table, key, value);
        }
    }

    for (int i = 0; i < table->count; i++) {
        printf("%s: %s\n", table->pairs[i]->key, table->pairs[i]->value);
    }

    destroyKeyValueTable(table);

    return 0;
}