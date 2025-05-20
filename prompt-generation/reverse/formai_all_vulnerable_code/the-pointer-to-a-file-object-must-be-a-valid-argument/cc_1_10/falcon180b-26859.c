//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *key;
    char *value;
} pair_t;

typedef struct {
    pair_t *data;
    int count;
    int capacity;
} hash_table_t;

hash_table_t *create_hash_table(int capacity) {
    hash_table_t *table = (hash_table_t *) malloc(sizeof(hash_table_t));
    table->data = (pair_t *) malloc(sizeof(pair_t) * capacity);
    table->count = 0;
    table->capacity = capacity;
    return table;
}

int hash_func(char *key, int capacity) {
    int hash = 0;
    while (*key) {
        hash = (hash * 31 + *key++) % capacity;
    }
    return hash;
}

void insert_pair(hash_table_t *table, char *key, char *value) {
    int hash = hash_func(key, table->capacity);
    int i = 0;
    while (i < table->count && strcmp(table->data[i].key, key)!= 0) {
        i++;
    }
    if (i == table->count) {
        table->data[i] = (pair_t) { strdup(key), strdup(value) };
        table->count++;
    } else {
        free(table->data[i].value);
        table->data[i].value = strdup(value);
    }
}

void print_pairs(hash_table_t *table) {
    for (int i = 0; i < table->count; i++) {
        printf("%s: %s\n", table->data[i].key, table->data[i].value);
    }
}

int main() {
    FILE *file = fopen("resume.txt", "r");
    char line[100];
    hash_table_t *table = create_hash_table(10);

    while (fgets(line, sizeof(line), file)!= NULL) {
        char *key = strtok(line, ":");
        char *value = strtok(NULL, "\n");
        insert_pair(table, key, value);
    }

    print_pairs(table);

    return 0;
}