//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_t {
    char *key;
    char *value;
    struct node_t *next;
} node_t;

typedef struct hashtable_t {
    int size;
    node_t **table;
} hashtable_t;

hashtable_t *hashtable_create(int size) {
    hashtable_t *hashtable = malloc(sizeof(hashtable_t));
    hashtable->size = size;
    hashtable->table = malloc(sizeof(node_t *) * size);
    for (int i = 0; i < size; i++) {
        hashtable->table[i] = NULL;
    }
    return hashtable;
}

void hashtable_destroy(hashtable_t *hashtable) {
    for (int i = 0; i < hashtable->size; i++) {
        node_t *node = hashtable->table[i];
        while (node) {
            node_t *next = node->next;
            free(node->key);
            free(node->value);
            free(node);
            node = next;
        }
    }
    free(hashtable->table);
    free(hashtable);
}

int hashtable_hash(hashtable_t *hashtable, char *key) {
    int hash = 0;
    int len = strlen(key);
    for (int i = 0; i < len; i++) {
        hash += key[i];
    }
    return hash % hashtable->size;
}

void hashtable_insert(hashtable_t *hashtable, char *key, char *value) {
    int hash = hashtable_hash(hashtable, key);
    node_t *node = malloc(sizeof(node_t));
    node->key = strdup(key);
    node->value = strdup(value);
    node->next = hashtable->table[hash];
    hashtable->table[hash] = node;
}

char *hashtable_get(hashtable_t *hashtable, char *key) {
    int hash = hashtable_hash(hashtable, key);
    node_t *node = hashtable->table[hash];
    while (node) {
        if (strcmp(node->key, key) == 0) {
            return node->value;
        }
        node = node->next;
    }
    return NULL;
}

void hashtable_remove(hashtable_t *hashtable, char *key) {
    int hash = hashtable_hash(hashtable, key);
    node_t *node = hashtable->table[hash];
    node_t *prev = NULL;
    while (node) {
        if (strcmp(node->key, key) == 0) {
            if (prev) {
                prev->next = node->next;
            } else {
                hashtable->table[hash] = node->next;
            }
            free(node->key);
            free(node->value);
            free(node);
            return;
        }
        prev = node;
        node = node->next;
    }
}

void hashtable_print(hashtable_t *hashtable) {
    for (int i = 0; i < hashtable->size; i++) {
        node_t *node = hashtable->table[i];
        while (node) {
            printf("%s: %s\n", node->key, node->value);
            node = node->next;
        }
    }
}

int main() {
    hashtable_t *hashtable = hashtable_create(10);
    hashtable_insert(hashtable, "name", "John Doe");
    hashtable_insert(hashtable, "age", "30");
    hashtable_insert(hashtable, "city", "New York");

    char *name = hashtable_get(hashtable, "name");
    printf("Name: %s\n", name);

    char *age = hashtable_get(hashtable, "age");
    printf("Age: %s\n", age);

    char *city = hashtable_get(hashtable, "city");
    printf("City: %s\n", city);

    hashtable_remove(hashtable, "age");
    age = hashtable_get(hashtable, "age");
    if (age == NULL) {
        printf("Age removed\n");
    }

    hashtable_print(hashtable);
    hashtable_destroy(hashtable);
    return 0;
}