//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: Cryptic
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct _node {
    char *key;
    int val;
    struct _node *left;
    struct _node *right;
} node;

typedef struct _tree {
    node *root;
} tree;

typedef struct _db {
    char *name;
    tree *index;
} db;

db *create_db(char *name) {
    db *db = malloc(sizeof(db));
    db->name = strdup(name);
    db->index = malloc(sizeof(tree));
    db->index->root = NULL;
    return db;
}

void destroy_db(db *db) {
    free(db->name);
    free(db->index);
    free(db);
}

void insert_db(db *db, char *key, int val) {
    node *new = malloc(sizeof(node));
    new->key = strdup(key);
    new->val = val;
    new->left = NULL;
    new->right = NULL;
    if (db->index->root == NULL) {
        db->index->root = new;
    } else {
        node *curr = db->index->root;
        while (1) {
            if (strcmp(key, curr->key) < 0) {
                if (curr->left == NULL) {
                    curr->left = new;
                    break;
                } else {
                    curr = curr->left;
                }
            } else {
                if (curr->right == NULL) {
                    curr->right = new;
                    break;
                } else {
                    curr = curr->right;
                }
            }
        }
    }
}

int get_db(db *db, char *key) {
    node *curr = db->index->root;
    while (curr != NULL) {
        if (strcmp(key, curr->key) == 0) {
            return curr->val;
        } else if (strcmp(key, curr->key) < 0) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    return -1;
}

int main() {
    db *db = create_db("test");
    insert_db(db, "a", 1);
    insert_db(db, "b", 2);
    insert_db(db, "c", 3);

    printf("%d\n", get_db(db, "a"));
    printf("%d\n", get_db(db, "b"));
    printf("%d\n", get_db(db, "c"));

    destroy_db(db);
    return 0;
}