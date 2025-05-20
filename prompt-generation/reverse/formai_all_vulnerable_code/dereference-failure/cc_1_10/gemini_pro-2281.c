//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *key;
    char *value;
    struct node *next;
} node_t;

typedef struct index {
    char *key;
    node_t *head;
} index_t;

typedef struct database {
    index_t *indexes;
    int num_indexes;
} database_t;

database_t *database_create() {
    database_t *db = malloc(sizeof(database_t));
    db->indexes = NULL;
    db->num_indexes = 0;
    return db;
}

void database_destroy(database_t *db) {
    for (int i = 0; i < db->num_indexes; i++) {
        index_t *index = &db->indexes[i];
        node_t *node = index->head;
        while (node) {
            node_t *next = node->next;
            free(node->key);
            free(node->value);
            free(node);
            node = next;
        }
        free(index->key);
        free(index);
    }
    free(db->indexes);
    free(db);
}

int database_add_index(database_t *db, char *key) {
    for (int i = 0; i < db->num_indexes; i++) {
        if (strcmp(db->indexes[i].key, key) == 0) {
            return -1;
        }
    }
    db->indexes = realloc(db->indexes, (db->num_indexes + 1) * sizeof(index_t));
    index_t *index = &db->indexes[db->num_indexes];
    index->key = strdup(key);
    index->head = NULL;
    db->num_indexes++;
    return 0;
}

int database_insert(database_t *db, char *key, char *value) {
    for (int i = 0; i < db->num_indexes; i++) {
        index_t *index = &db->indexes[i];
        if (strcmp(index->key, key) == 0) {
            node_t *node = malloc(sizeof(node_t));
            node->key = strdup(key);
            node->value = strdup(value);
            node->next = index->head;
            index->head = node;
            return 0;
        }
    }
    return -1;
}

char *database_get(database_t *db, char *key) {
    for (int i = 0; i < db->num_indexes; i++) {
        index_t *index = &db->indexes[i];
        if (strcmp(index->key, key) == 0) {
            node_t *node = index->head;
            while (node) {
                if (strcmp(node->key, key) == 0) {
                    return node->value;
                }
                node = node->next;
            }
        }
    }
    return NULL;
}

int main() {
    database_t *db = database_create();
    database_add_index(db, "name");
    database_add_index(db, "age");
    database_insert(db, "John", "30");
    database_insert(db, "Mary", "25");
    database_insert(db, "Bob", "40");
    char *name = database_get(db, "name");
    char *age = database_get(db, "age");
    printf("name: %s, age: %s\n", name, age);
    database_destroy(db);
    return 0;
}