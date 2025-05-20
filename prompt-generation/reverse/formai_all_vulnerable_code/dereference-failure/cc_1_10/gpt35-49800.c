//FormAI DATASET v1.0 Category: Database Indexing System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define OMT(_v) (_v == NULL)

#define MAX_ORDER       5

typedef struct btree_node {
    int     n;          /* Number of keys in node */
    char    *keys[MAX_ORDER - 1];
    struct btree_node *childs[MAX_ORDER];
} btree_node_t;

typedef struct btree {
    struct btree     *root;
    unsigned int     order;          
    btree_node_t     *first;
    btree_node_t     *free;
} btree_t;

btree_node_t *new_node(unsigned int order) {
    btree_node_t *ret = malloc(sizeof(*ret));
    if (OMT(ret)) return NULL;

    ret->n = 0;
    for (int i = 0; i < order; i++) {
        ret->keys[i] = NULL;
        ret->childs[i] = NULL;
    }
    return ret;
}

static void free_node(btree_t *btree, btree_node_t **node) {
    btree_node_t *p = *node;
    p->n = 0;
    btree->free = p;
}

static void free_btree(btree_t *t) {
    while (t->first) {
        btree_node_t *p = t->first;
        t->first = p->childs[0];
        free_node(t, &p);
    }
}

int main() {
   /* example usage */
   btree_t btree;
   btree.order = MAX_ORDER;
   btree.root = NULL;
   btree.first = btree.free = NULL;

   btree_node_t *node = new_node(MAX_ORDER);
   free_node(&btree, &node);
   free_btree(&btree);

   return 0;
}