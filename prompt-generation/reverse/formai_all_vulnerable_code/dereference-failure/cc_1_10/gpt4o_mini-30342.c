//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEGREE 3
#define MAX_RECORD_LENGTH 100
#define TRUE 1
#define FALSE 0

typedef struct Record {
    int id;
    char data[MAX_RECORD_LENGTH];
} Record;

typedef struct BTreeNode {
    int n; // Number of keys
    Record *records[MAX_DEGREE - 1]; // Store records
    struct BTreeNode *children[MAX_DEGREE]; // Child pointers
    int leaf; // True if leaf node
} BTreeNode;

typedef struct BTree {
    BTreeNode *root;
} BTree;

BTreeNode* createNode(int leaf) {
    BTreeNode *newNode = malloc(sizeof(BTreeNode));
    newNode->n = 0;
    newNode->leaf = leaf;
    return newNode;
}

BTree* createBTree() {
    BTree *tree = malloc(sizeof(BTree));
    tree->root = createNode(TRUE);
    return tree;
}

void splitChild(BTreeNode *parent, int i, BTreeNode *fullNode) {
    BTreeNode *newNode = createNode(fullNode->leaf);
    newNode->n = MAX_DEGREE - 1;

    for (int j = 0; j < MAX_DEGREE - 1; j++)
        newNode->records[j] = fullNode->records[j + 1];

    if (!fullNode->leaf) {
        for (int j = 0; j < MAX_DEGREE; j++)
            newNode->children[j] = fullNode->children[j + 1];
    }

    fullNode->n = MAX_DEGREE - 1;
    for (int j = parent->n; j >= i + 1; j--)
        parent->children[j + 1] = parent->children[j];

    parent->children[i + 1] = newNode;

    for (int j = parent->n - 1; j >= i; j--)
        parent->records[j + 1] = parent->records[j];

    parent->records[i] = fullNode->records[0];
    parent->n++;
}

void insertNonFull(BTreeNode *node, Record *record) {
    int i = node->n - 1;

    if (node->leaf) {
        while (i >= 0 && record->id < node->records[i]->id) {
            node->records[i + 1] = node->records[i];
            i--;
        }
        node->records[i + 1] = record;
        node->n++;
    } else {
        while (i >= 0 && record->id < node->records[i]->id)
            i--;

        if (node->children[i + 1]->n == MAX_DEGREE - 1) {
            splitChild(node, i + 1, node->children[i + 1]);

            if (record->id > node->records[i + 1]->id)
                i++;
        }
        insertNonFull(node->children[i + 1], record);
    }
}

void insert(BTree *tree, Record *record) {
    BTreeNode *root = tree->root;

    if (root->n == MAX_DEGREE - 1) {
        BTreeNode *newNode = createNode(FALSE);
        tree->root = newNode;
        newNode->children[0] = root;
        splitChild(newNode, 0, root);
        insertNonFull(newNode, record);
    } else {
        insertNonFull(root, record);
    }
}

void traverse(BTreeNode *node) {
    int i;
    for (i = 0; i < node->n; i++) {
        if (!node->leaf)
            traverse(node->children[i]);
        printf("ID: %d, Data: %s\n", node->records[i]->id, node->records[i]->data);
    }
    if (!node->leaf)
        traverse(node->children[i]);
}

void freeNode(BTreeNode *node) {
    for (int i = 0; i <= node->n; i++) {
        if (!node->leaf)
            freeNode(node->children[i]);
    }
    free(node);
}

void freeBTree(BTree *tree) {
    freeNode(tree->root);
    free(tree);
}

int main() {
    BTree *tree = createBTree();
    Record *record;

    for (int i = 0; i < 10; i++) {
        record = malloc(sizeof(Record));
        record->id = i * 10;
        snprintf(record->data, sizeof(record->data), "Record %d", record->id);
        insert(tree, record);
    }

    printf("B-Tree records:\n");
    traverse(tree->root);

    freeBTree(tree);
    return 0;
}