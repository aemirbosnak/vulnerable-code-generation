//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *key;
    char *value;
    struct node *next;
} node_t;

typedef struct table {
    int size;
    node_t **buckets;
} table_t;

table_t *create_table(int size) {
    table_t *table = malloc(sizeof(table_t));
    table->size = size;
    table->buckets = malloc(sizeof(node_t *) * size);
    for (int i = 0; i < size; i++) {
        table->buckets[i] = NULL;
    }
    return table;
}

void destroy_table(table_t *table) {
    for (int i = 0; i < table->size; i++) {
        node_t *bucket = table->buckets[i];
        while (bucket != NULL) {
            node_t *next = bucket->next;
            free(bucket->key);
            free(bucket->value);
            free(bucket);
            bucket = next;
        }
    }
    free(table->buckets);
    free(table);
}

node_t *create_node(char *key, char *value) {
    node_t *node = malloc(sizeof(node_t));
    node->key = strdup(key);
    node->value = strdup(value);
    node->next = NULL;
    return node;
}

void destroy_node(node_t *node) {
    free(node->key);
    free(node->value);
    free(node);
}

unsigned int hash(char *key) {
    unsigned int h = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        h = (h << 5) - h + key[i];
    }
    return h;
}

void insert(table_t *table, char *key, char *value) {
    unsigned int index = hash(key) % table->size;
    node_t *bucket = table->buckets[index];
    while (bucket != NULL) {
        if (strcmp(bucket->key, key) == 0) {
            bucket->value = strdup(value);
            return;
        }
        bucket = bucket->next;
    }
    node_t *new_node = create_node(key, value);
    new_node->next = table->buckets[index];
    table->buckets[index] = new_node;
}

char *get(table_t *table, char *key) {
    unsigned int index = hash(key) % table->size;
    node_t *bucket = table->buckets[index];
    while (bucket != NULL) {
        if (strcmp(bucket->key, key) == 0) {
            return bucket->value;
        }
        bucket = bucket->next;
    }
    return NULL;
}

void print_table(table_t *table) {
    for (int i = 0; i < table->size; i++) {
        node_t *bucket = table->buckets[i];
        printf("Bucket %d: ", i);
        while (bucket != NULL) {
            printf("(%s, %s) -> ", bucket->key, bucket->value);
            bucket = bucket->next;
        }
        printf("NULL\n");
    }
}

int main() {
    table_t *table = create_table(10);

    insert(table, "foo", "bar");
    insert(table, "baz", "qux");
    insert(table, "hello", "world");

    printf("The value for \"foo\" is: %s\n", get(table, "foo"));
    printf("The value for \"baz\" is: %s\n", get(table, "baz"));
    printf("The value for \"hello\" is: %s\n", get(table, "hello"));

    print_table(table);

    destroy_table(table);

    return 0;
}