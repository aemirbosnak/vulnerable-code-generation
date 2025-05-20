//FormAI DATASET v1.0 Category: Database Indexing System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 10
#define MAX_RECORDS 5

typedef struct record {
    char key[MAX_KEY_LEN];
    int value;
} Record;

typedef struct index_node {
    char key[MAX_KEY_LEN];
    int record_num;
    struct index_node *left;
    struct index_node *right;
} IndexNode;

IndexNode *insert(IndexNode *node, Record *record) {
    if (node == NULL) {
        node = (IndexNode *) malloc(sizeof(IndexNode));
        strcpy(node->key, record->key);
        node->record_num = 0;
        node->left = NULL;
        node->right = NULL;
    }

    int cmp = strcmp(node->key, record->key);

    if (cmp == 0) {
        fprintf(stderr, "Duplicate key found: %s\n", record->key);
        exit(EXIT_FAILURE);
    } else if (cmp > 0) {
        node->left = insert(node->left, record);
    } else {
        node->right = insert(node->right, record);
    }

    return node;
}

IndexNode *lookup(IndexNode *node, char *key) {
    if (node == NULL) {
        return NULL;
    }

    int cmp = strcmp(node->key, key);

    if (cmp == 0) {
        return node;
    } else if (cmp > 0) {
        return lookup(node->left, key);
    } else {
        return lookup(node->right, key);
    }
}

void print_records(IndexNode *node, Record *records) {
    if (node != NULL) {
        print_records(node->left, records);
        printf("%s => %d\n", node->key, records[node->record_num].value);
        print_records(node->right, records);
    }
}

int main() {
    Record records[MAX_RECORDS] = {
        {"abc", 1},
        {"def", 2},
        {"ghi", 3},
        {"jkl", 4},
        {"mno", 5}
    };

    IndexNode *root = NULL;

    for (int i = 0; i < MAX_RECORDS; i++) {
        root = insert(root, &records[i]);
        root->record_num = i;
    }

    char key[MAX_KEY_LEN];
    printf("Enter a key to lookup: ");
    scanf("%s", key);

    IndexNode *node = lookup(root, key);

    if (node == NULL) {
        printf("Key not found: %s\n", key);
    } else {
        printf("Value of %s is %d\n", key, records[node->record_num].value);
    }

    printf("\nAll records in key order:\n");
    print_records(root, records);

    return 0;
}