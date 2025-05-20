//FormAI DATASET v1.0 Category: Database Indexing System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_KEY_LEN 10

struct record {
    char key[MAX_KEY_LEN];
    int value;
};

typedef struct record record_t;

struct node {
    record_t *record;
    struct node *left;
    struct node *right;
    int height;
};

typedef struct node node_t;

node_t *root;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(node_t *n) {
    if (n == NULL)
        return 0;
    return n->height;
}

int balance_factor(node_t *n) {
    if (n == NULL)
        return 0;
    return height(n->left) - height(n->right);
}

node_t *new_node(record_t *record) {
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->record = record;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

node_t *left_rotate(node_t *x) {
    node_t *y = x->right;
    node_t *tmp = y->left;
    y->left = x;
    x->right = tmp;
    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));
    return y;
}

node_t *right_rotate(node_t *y) {
    node_t *x = y->left;
    node_t *tmp = x->right;
    x->right = y;
    y->left = tmp;
    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));
    return x;
}

node_t *insert(node_t *node, record_t *record) {
    if (node == NULL)
        return new_node(record);

    if (strcmp(record->key, node->record->key) < 0)
        node->left = insert(node->left, record);
    else if (strcmp(record->key, node->record->key) > 0)
        node->right = insert(node->right, record);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int bf = balance_factor(node);

    // Left Left case
    if (bf > 1 && strcmp(record->key, node->left->record->key) < 0)
        return right_rotate(node);

    // Left Right case
    if (bf > 1 && strcmp(record->key, node->left->record->key) > 0) {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }

    // Right Right case
    if (bf < -1 && strcmp(record->key, node->right->record->key) > 0)
        return left_rotate(node);

    // Right Left case
    if (bf < -1 && strcmp(record->key, node->right->record->key) < 0) {
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }

    return node;
}

void inorder(node_t *node) {
    if (node) {
        inorder(node->left);
        printf("%s %d\n", node->record->key, node->record->value);
        inorder(node->right);
    }
}

record_t **hash_table[MAX_RECORDS];

int hash(char *key) {
    int sum = 0;
    for (int i = 0; i < strlen(key); i++)
        sum += key[i];
    return sum % MAX_RECORDS;
}

void add_record(char *key, int value) {
    record_t *record = (record_t *)malloc(sizeof(record_t));
    strncpy(record->key, key, MAX_KEY_LEN);
    record->value = value;
    int index = hash(key);
    record_t **records = hash_table[index];
    if (records == NULL) {
        records = (record_t **)malloc(sizeof(record_t *) * 2);
        records[0] = record;
        records[1] = NULL;
        hash_table[index] = records;
    } else {
        int i = 0;
        while (records[i] != NULL)
            i++;
        records = (record_t **)realloc(records, sizeof(record_t *) * (i + 2));
        records[i] = record;
        records[i + 1] = NULL;
    }
    root = insert(root, record);
}

record_t **find_records(char *key) {
    int index = hash(key);
    record_t **records = hash_table[index];
    if (records == NULL)
        return NULL;
    int i = 0;
    while (records[i] != NULL && strncmp(records[i]->key, key, MAX_KEY_LEN) != 0)
        i++;
    if (records[i] == NULL)
        return NULL;
    record_t **result = (record_t **)malloc(sizeof(record_t *) * MAX_RECORDS);
    i = 0;
    node_t *node = root;
    while (node != NULL) {
        if (strcmp(node->record->key, key) == 0)
            result[i++] = node->record;
        if (strcmp(node->record->key, key) >= 0)
            node = node->left;
        else
            node = node->right;
    }
    result[i] = NULL;
    return result;
}

void delete_record(char *key) {
    int index = hash(key);
    record_t **records = hash_table[index];
    if (records == NULL)
        return;
    int i = 0;
    while (records[i] != NULL && strncmp(records[i]->key, key, MAX_KEY_LEN) != 0)
        i++;
    if (records[i] == NULL)
        return;
    free(records[i]);
    while (records[i + 1] != NULL) {
        records[i] = records[i + 1];
        i++;
    }
    records[i] = NULL;

    // rebuild the AVL tree
    node_t *new_root = NULL;
    for (int i = 0; i < MAX_RECORDS; i++) {
        record_t **records = hash_table[i];
        if (records != NULL) {
            int j = 0;
            while (records[j] != NULL) {
                new_root = insert(new_root, records[j]);
                j++;
            }
            free(records);
            hash_table[i] = NULL;
        }
    }
    root = new_root;
}

int main() {
    root = NULL;

    add_record("apple", 5);
    add_record("banana", 3);
    add_record("grape", 8);
    add_record("orange", 2);
    add_record("peach", 7);
    add_record("pear", 6);

    printf("Inorder traversal of the AVL tree:\n");
    inorder(root);

    printf("Records with key \"apple\":\n");
    record_t **records = find_records("apple");
    for (int i = 0; records[i] != NULL; i++)
        printf("%s %d\n", records[i]->key, records[i]->value);
    free(records);

    printf("Delete record with key \"apple\"\n");
    delete_record("apple");

    printf("Inorder traversal of the AVL tree after deletion:\n");
    inorder(root);

    return 0;
}