//LLAMA2-13B DATASET v1.0 Category: Compression algorithms ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024
#define BUCKET_SIZE 32

typedef struct {
    char *key;
    char *value;
} bucket_t;

typedef struct {
    bucket_t *buckets[BUCKET_SIZE];
    int count;
} table_t;

table_t *create_table(void) {
    table_t *table = malloc(sizeof(table_t));
    for (int i = 0; i < BUCKET_SIZE; i++) {
        table->buckets[i] = NULL;
    }
    return table;
}

void insert(table_t *table, const char *key, const char *value) {
    int i = 0;
    while (i < BUCKET_SIZE && table->buckets[i] != NULL) {
        if (strcmp(key, table->buckets[i]->key) < 0) {
            i++;
        }
    }
    if (i == BUCKET_SIZE) {
        table->count++;
        table->buckets[i] = malloc(sizeof(bucket_t));
        table->buckets[i]->key = key;
        table->buckets[i]->value = value;
    } else {
        table->buckets[i]->value = value;
    }
}

const char *find(table_t *table, const char *key) {
    int i = 0;
    while (i < BUCKET_SIZE && table->buckets[i] != NULL) {
        if (strcmp(key, table->buckets[i]->key) == 0) {
            return table->buckets[i]->value;
        }
        i++;
    }
    return NULL;
}

void print_table(table_t *table) {
    int i = 0;
    for (i = 0; i < BUCKET_SIZE; i++) {
        if (table->buckets[i] != NULL) {
            printf("%d: %s -> %s\n", i, table->buckets[i]->key, table->buckets[i]->value);
        }
    }
}

int main(void) {
    table_t *table = create_table();
    insert(table, "apple", "red");
    insert(table, "banana", "yellow");
    insert(table, "cherry", "red");
    print_table(table);
    const char *color = find(table, "cherry");
    if (color != NULL) {
        printf("Color of cherry is %s\n", color);
    } else {
        printf("Could not find cherry in the table\n");
    }
    return 0;
}