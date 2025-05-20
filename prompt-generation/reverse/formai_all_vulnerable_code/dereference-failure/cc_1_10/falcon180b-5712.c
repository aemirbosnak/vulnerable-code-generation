//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

typedef struct {
    char *key;
    char *value;
} kv_pair;

typedef struct {
    kv_pair *data;
    int size;
} kv_table;

kv_table *kv_create() {
    kv_table *table = malloc(sizeof(kv_table));
    table->data = malloc(MAX_SIZE * sizeof(kv_pair));
    table->size = 0;
    return table;
}

void kv_destroy(kv_table *table) {
    free(table->data);
    free(table);
}

int kv_size(kv_table *table) {
    return table->size;
}

void kv_put(kv_table *table, char *key, char *value) {
    kv_pair *pair = malloc(sizeof(kv_pair));
    pair->key = strdup(key);
    pair->value = strdup(value);
    table->data[table->size++] = *pair;
}

char *kv_get(kv_table *table, char *key) {
    for (int i = 0; i < table->size; i++) {
        kv_pair *pair = &table->data[i];
        if (strcmp(pair->key, key) == 0) {
            return pair->value;
        }
    }
    return NULL;
}

void kv_delete(kv_table *table, char *key) {
    for (int i = 0; i < table->size; i++) {
        kv_pair *pair = &table->data[i];
        if (strcmp(pair->key, key) == 0) {
            free(pair->key);
            free(pair->value);
            for (int j = i; j < table->size - 1; j++) {
                table->data[j] = table->data[j + 1];
            }
            table->size--;
            return;
        }
    }
}

int main() {
    kv_table *table = kv_create();
    kv_put(table, "name", "John Doe");
    kv_put(table, "age", "30");
    printf("%s\n", kv_get(table, "name"));
    printf("%s\n", kv_get(table, "age"));
    kv_delete(table, "age");
    printf("%s\n", kv_get(table, "age"));
    kv_destroy(table);
    return 0;
}