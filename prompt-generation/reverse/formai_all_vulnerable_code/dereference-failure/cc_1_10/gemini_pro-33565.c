//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *key;
    int value;
    struct node *left;
    struct node *right;
} node_t;

typedef struct index {
    char *name;
    node_t *root;
} index_t;

typedef struct database {
    char *name;
    int num_indexes;
    index_t *indexes;
} database_t;

node_t *new_node(char *key, int value) {
    node_t *node = malloc(sizeof(node_t));
    node->key = strdup(key);
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

index_t *new_index(char *name) {
    index_t *index = malloc(sizeof(index_t));
    index->name = strdup(name);
    index->root = NULL;
    return index;
}

database_t *new_database(char *name) {
    database_t *database = malloc(sizeof(database_t));
    database->name = strdup(name);
    database->num_indexes = 0;
    database->indexes = NULL;
    return database;
}

void insert_index(database_t *database, index_t *index) {
    database->indexes = realloc(database->indexes, (database->num_indexes + 1) * sizeof(index_t));
    database->indexes[database->num_indexes++] = *index;
}

void insert_node(node_t **root, char *key, int value) {
    if (*root == NULL) {
        *root = new_node(key, value);
        return;
    }

    if (strcmp(key, (*root)->key) < 0) {
        insert_node(&(*root)->left, key, value);
    } else {
        insert_node(&(*root)->right, key, value);
    }
}

void search_node(node_t *root, char *key, int *value) {
    if (root == NULL) {
        *value = -1;
        return;
    }

    if (strcmp(key, root->key) == 0) {
        *value = root->value;
        return;
    }

    if (strcmp(key, root->key) < 0) {
        search_node(root->left, key, value);
    } else {
        search_node(root->right, key, value);
    }
}

void print_node(node_t *root) {
    if (root == NULL) {
        return;
    }

    printf("(%s, %d)\n", root->key, root->value);
    print_node(root->left);
    print_node(root->right);
}

void print_index(index_t *index) {
    printf("Index: %s\n", index->name);
    print_node(index->root);
}

void print_database(database_t *database) {
    printf("Database: %s\n", database->name);
    for (int i = 0; i < database->num_indexes; i++) {
        print_index(&database->indexes[i]);
    }
}

int main() {
    database_t *database = new_database("my_database");
    index_t *index = new_index("my_index");

    insert_index(database, index);
    insert_node(&index->root, "key1", 1);
    insert_node(&index->root, "key2", 2);
    insert_node(&index->root, "key3", 3);

    int value;
    search_node(index->root, "key2", &value);
    printf("Value: %d\n", value);

    print_database(database);

    return 0;
}