//MISTRAL-7B DATASET v1.0 Category: Database Indexing System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    float love_level;
} lover_t;

typedef struct index_node {
    char key[20];
    int leaf;
    int next;
} index_node_t;

typedef struct b_tree {
    int order;
    index_node_t *nodes;
    int size;
    lover_t *records;
} b_tree_t;

void create_tree(b_tree_t *tree, int order) {
    tree->order = order;
    tree->nodes = (index_node_t *)calloc(order, sizeof(index_node_t));
    tree->records = (lover_t *)calloc(order * 2, sizeof(lover_t));
    tree->size = 0;
}

int is_leaf(b_tree_t *tree, int index) {
    return tree->nodes[index].leaf;
}

int get_next_index(b_tree_t *tree, int index) {
    return tree->nodes[index].next;
}

int get_key_index(b_tree_t *tree, char *key) {
    int i;
    for (i = 0; i < tree->size; i++) {
        if (strcmp(tree->nodes[i].key, key) == 0 && is_leaf(tree, i)) {
            return i;
        }
    }
    return -1;
}

void insert_record(b_tree_t *tree, char *key, lover_t record) {
    int i, j;
    if (get_key_index(tree, key) != -1) {
        printf("Error: Key already exists.\n");
        return;
    }
    i = tree->size;
    strcpy(tree->nodes[i].key, key);
    tree->nodes[i].leaf = 1;
    tree->records[i] = record;
    tree->size++;
    while (i > 0 && strcmp(tree->nodes[i-1].key, key) > 0) {
        j = get_next_index(tree, i-1);
        tree->nodes[i].next = j;
        tree->nodes[j].next = i;
        strcpy(tree->nodes[i].key, tree->nodes[i-1].key);
        i--;
    }
    strcpy(tree->nodes[i].key, key);
}

void print_tree(b_tree_t *tree, int index) {
    int i;
    if (is_leaf(tree, index)) {
        printf("%s: %s, %d, %.2f\n", tree->nodes[index].key, tree->records[index].name, tree->records[index].age, tree->records[index].love_level);
        return;
    }
    printf("%s: INDEX\n", tree->nodes[index].key);
    for (i = 0; i < tree->order && index+i < tree->size; i++) {
        print_tree(tree, get_next_index(tree, index+i));
    }
}

int main() {
    b_tree_t my_tree;
    lover_t lover1 = {"Romeo", 25, 10.0};
    lover_t lover2 = {"Juliet", 18, 15.0};
    char key1[] = "Montague";
    char key2[] = "Capulet";

    create_tree(&my_tree, 5);

    insert_record(&my_tree, key1, lover1);
    insert_record(&my_tree, key2, lover2);

    printf("ROMANTIC INDEX:\n");
    print_tree(&my_tree, 0);

    return 0;
}