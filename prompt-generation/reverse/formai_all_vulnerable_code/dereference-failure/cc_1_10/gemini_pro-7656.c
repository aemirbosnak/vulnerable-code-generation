//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *key;
    int value;
    struct node *next;
} node_t;

typedef struct index {
    char *name;
    node_t *head;
} index_t;

typedef struct database {
    index_t *indexes;
    int num_indexes;
} database_t;

database_t *create_database() {
    database_t *db = malloc(sizeof(database_t));
    db->indexes = NULL;
    db->num_indexes = 0;
    return db;
}

void destroy_database(database_t *db) {
    for (int i = 0; i < db->num_indexes; i++) {
        node_t *node = db->indexes[i].head;
        while (node != NULL) {
            node_t *next = node->next;
            free(node->key);
            free(node);
            node = next;
        }
        free(db->indexes[i].name);
    }
    free(db->indexes);
    free(db);
}

index_t *create_index(database_t *db, char *name) {
    index_t *index = malloc(sizeof(index_t));
    index->name = strdup(name);
    index->head = NULL;
    db->indexes = realloc(db->indexes, (db->num_indexes + 1) * sizeof(index_t));
    db->indexes[db->num_indexes++] = *index;
    return index;
}

void destroy_index(index_t *index) {
    node_t *node = index->head;
    while (node != NULL) {
        node_t *next = node->next;
        free(node->key);
        free(node);
        node = next;
    }
    free(index->name);
    free(index);
}

int insert(index_t *index, char *key, int value) {
    node_t *node = malloc(sizeof(node_t));
    node->key = strdup(key);
    node->value = value;
    node->next = index->head;
    index->head = node;
    return 1;
}

int delete(index_t *index, char *key) {
    node_t *prev = NULL;
    node_t *node = index->head;
    while (node != NULL) {
        if (strcmp(node->key, key) == 0) {
            if (prev == NULL) {
                index->head = node->next;
            } else {
                prev->next = node->next;
            }
            free(node->key);
            free(node);
            return 1;
        }
        prev = node;
        node = node->next;
    }
    return 0;
}

int search(index_t *index, char *key) {
    node_t *node = index->head;
    while (node != NULL) {
        if (strcmp(node->key, key) == 0) {
            return node->value;
        }
        node = node->next;
    }
    return -1;
}

int main() {
    database_t *db = create_database();

    index_t *index1 = create_index(db, "index1");
    insert(index1, "key1", 1);
    insert(index1, "key2", 2);
    insert(index1, "key3", 3);

    index_t *index2 = create_index(db, "index2");
    insert(index2, "key1", 10);
    insert(index2, "key2", 20);
    insert(index2, "key3", 30);

    printf("%d\n", search(index1, "key2")); // 2
    printf("%d\n", search(index2, "key3")); // 30

    delete(index1, "key2");
    printf("%d\n", search(index1, "key2")); // -1

    destroy_index(index1);
    destroy_index(index2);
    destroy_database(db);

    return 0;
}