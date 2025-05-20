//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NODES 1000
#define MAX_KEY_SIZE 32
#define MAX_VALUE_SIZE 1024

typedef struct node {
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
    struct node *next;
} node_t;

typedef struct {
    node_t *nodes[MAX_NODES];
    int num_nodes;
} db_t;

db_t *db_create() {
    db_t *db = malloc(sizeof(db_t));
    memset(db->nodes, 0, sizeof(db->nodes));
    db->num_nodes = 0;
    return db;
}

void db_destroy(db_t *db) {
    for (int i = 0; i < db->num_nodes; i++) {
        node_t *node = db->nodes[i];
        while (node!= NULL) {
            node_t *tmp = node;
            node = node->next;
            free(tmp);
        }
    }
    free(db);
}

void db_insert(db_t *db, const char *key, const char *value) {
    node_t *node = db->nodes[hash(key) % MAX_NODES];
    while (node!= NULL) {
        if (strcmp(node->key, key) == 0) {
            strcpy(node->value, value);
            return;
        }
        node = node->next;
    }
    node_t *new_node = malloc(sizeof(node_t));
    strcpy(new_node->key, key);
    strcpy(new_node->value, value);
    new_node->next = db->nodes[hash(key) % MAX_NODES];
    db->nodes[hash(key) % MAX_NODES] = new_node;
    db->num_nodes++;
}

char *db_lookup(db_t *db, const char *key) {
    node_t *node = db->nodes[hash(key) % MAX_NODES];
    while (node!= NULL) {
        if (strcmp(node->key, key) == 0) {
            return node->value;
        }
        node = node->next;
    }
    return NULL;
}

int hash(const char *str) {
    int hash = 0;
    for (int i = 0; str[i]!= '\0'; i++) {
        hash = (hash * 31) ^ str[i];
    }
    return hash;
}

int main() {
    db_t *db = db_create();
    db_insert(db, "hello", "world");
    char *value = db_lookup(db, "hello");
    printf("%s\n", value);
    db_destroy(db);
    return 0;
}