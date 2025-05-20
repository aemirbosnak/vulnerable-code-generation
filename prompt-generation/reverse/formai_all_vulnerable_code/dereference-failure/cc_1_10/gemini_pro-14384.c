//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: complex
#include <stdlib.h>
#include <stdio.h>

typedef struct _idxnode {
    int index;
    char *key;
    char *value;
    struct _idxnode *next;
} idxnode;

typedef struct _idxtree {
    idxnode *root;
} idxtree;

idxtree *create_idxtree() {
    idxtree *t = malloc(sizeof(idxtree));
    t->root = NULL;
    return t;
}

void insert_idxnode(idxtree *t, int index, char *key, char *value) {
    idxnode *new = malloc(sizeof(idxnode));
    new->index = index;
    new->key = key;
    new->value = value;
    new->next = NULL;

    if (!t->root) {
        t->root = new;
        return;
    }

    idxnode *curr = t->root;
    while (curr->next) {
        curr = curr->next;
    }
    curr->next = new;
}

idxnode *find_idxnode(idxtree *t, int index) {
    idxnode *curr = t->root;
    while (curr) {
        if (curr->index == index) {
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}

void delete_idxnode(idxtree *t, int index) {
    idxnode *prev = NULL;
    idxnode *curr = t->root;

    while (curr) {
        if (curr->index == index) {
            if (!prev) {
                t->root = curr->next;
            } else {
                prev->next = curr->next;
            }
            free(curr->key);
            free(curr->value);
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

void print_idxtree(idxtree *t) {
    idxnode *curr = t->root;
    while (curr) {
        printf("Index: %d, Key: %s, Value: %s\n", curr->index, curr->key, curr->value);
        curr = curr->next;
    }
}

int main() {
    idxtree *t = create_idxtree();

    insert_idxnode(t, 1, "name", "John");
    insert_idxnode(t, 2, "age", "25");
    insert_idxnode(t, 3, "city", "New York");

    idxnode *node = find_idxnode(t, 2);
    printf("Found node with index 2: Key: %s, Value: %s\n", node->key, node->value);

    delete_idxnode(t, 3);

    print_idxtree(t);

    return 0;
}