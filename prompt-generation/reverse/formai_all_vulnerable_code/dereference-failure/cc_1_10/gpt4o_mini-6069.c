//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 3 // Maximum keys in a node

// B-Tree Node Structure
typedef struct BTreeNode {
    int keys[MAX - 1];
    struct BTreeNode* children[MAX];
    int size;
    int isLeaf;
} BTreeNode;

// B-Tree Structure
typedef struct BTree {
    BTreeNode* root;
} BTree;

// Function to create a new B-Tree node
BTreeNode* createNode(int isLeaf) {
    BTreeNode* newNode = (BTreeNode*)malloc(sizeof(BTreeNode));
    newNode->isLeaf = isLeaf;
    newNode->size = 0;
    for (int i = 0; i < MAX; i++) {
        newNode->children[i] = NULL;
    }
    return newNode;
}

// Function to insert a new key
void insert(BTree* tree, int key);

// Split the child of the node
void splitChild(BTreeNode* node, int index, BTreeNode* child) {
    BTreeNode* newChild = createNode(child->isLeaf);
    newChild->size = MAX / 2 - 1;

    for (int i = 0; i < newChild->size; i++) {
        newChild->keys[i] = child->keys[i + MAX / 2];
    }
    
    if (!child->isLeaf) {
        for (int i = 0; i <= newChild->size; i++) {
            newChild->children[i] = child->children[i + MAX / 2];
        }
    }
    
    child->size = MAX / 2;
    
    for (int i = node->size; i >= index + 1; i--) {
        node->children[i + 1] = node->children[i];
    }
    
    node->children[index + 1] = newChild;

    for (int i = node->size - 1; i >= index; i--) {
        node->keys[i + 1] = node->keys[i];
    }

    node->keys[index] = child->keys[MAX / 2 - 1];
    node->size++;
}

// Insert function for the B-Tree
void insertNonFull(BTreeNode* node, int key) {
    int i = node->size - 1;

    if (node->isLeaf) {
        while (i >= 0 && key < node->keys[i]) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
        node->size++;
    } else {
        while (i >= 0 && key < node->keys[i]) {
            i--;
        }

        if (node->children[i + 1]->size == MAX - 1) {
            splitChild(node, i + 1, node->children[i + 1]);
            if (key > node->keys[i + 1]) {
                i++;
            }
        }
        insertNonFull(node->children[i + 1], key);
    }
}

// Function to create a B-Tree
BTree* createBTree() {
    BTree* bTree = (BTree*)malloc(sizeof(BTree));
    bTree->root = createNode(1);
    return bTree;
}

// Function to display the B-Tree
void display(BTreeNode* node, int level) {
    if (node) {
        for (int i = 0; i < node->size; i++) {
            display(node->children[i], level + 1);
            for (int j = 0; j < level; j++) printf("\t");
            printf("%d\n", node->keys[i]);
        }
        display(node->children[node->size], level + 1);
    }
}

// Search for a key in the B-Tree
int search(BTreeNode* node, int key) {
    int i = 0;

    while (i < node->size && key > node->keys[i]) {
        i++;
    }

    if (i < node->size && node->keys[i] == key) {
        return 1; // Key found
    }

    if (node->isLeaf) {
        return 0; // Key not found
    }

    return search(node->children[i], key);
}

void insert(BTree* tree, int key) {
    BTreeNode* root = tree->root;

    if (root->size == MAX - 1) {
        BTreeNode* newNode = createNode(0);
        newNode->children[0] = root;
        splitChild(newNode, 0, root);
        int i = 0;
        if (newNode->keys[0] < key) {
            i++;
        }
        insertNonFull(newNode->children[i], key);
        tree->root = newNode;
    } else {
        insertNonFull(root, key);
    }
}

int main() {
    BTree* bTree = createBTree();
    int choice, key;

    while (1) {
        printf("\nB-Tree Database Indexing:\n");
        printf("1. Insert Record\n");
        printf("2. Search Record\n");
        printf("3. Display Records\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(bTree, key);
                printf("Inserted %d successfully.\n", key);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                if (search(bTree->root, key)) {
                    printf("Record %d found.\n", key);
                } else {
                    printf("Record %d not found.\n", key);
                }
                break;
            case 3:
                printf("Records in B-Tree:\n");
                display(bTree->root, 0);
                break;
            case 4:
                free(bTree);
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}