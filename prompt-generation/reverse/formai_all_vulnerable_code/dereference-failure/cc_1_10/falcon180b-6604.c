//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 50
#define MAX_VALUE_SIZE 100
#define MAX_INDEX_SIZE 500
#define MAX_TREE_HEIGHT 10

typedef struct {
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
} Entry;

typedef struct node {
    Entry entry;
    struct node* children[26];
    int count;
} Node;

Node* createNode() {
    Node* node = (Node*)malloc(sizeof(Node));
    memset(node, 0, sizeof(Node));
    return node;
}

void insert(Node* node, char* key, char* value) {
    int index = *key - 'a';
    if (node->children[index] == NULL) {
        node->children[index] = createNode();
    }
    insert(node->children[index], key + 1, value);
}

void printTree(Node* node, int space) {
    if (node == NULL) return;
    printTree(node->children['a'], space + 4);
    printf("%*s[%c]: %s\n", space, "", node->entry.key[0], node->entry.value);
    printTree(node->children['z'], space + 4);
}

void search(Node* node, char* key) {
    int index = *key - 'a';
    if (node->children[index] == NULL) return;
    if (strcmp(node->children[index]->entry.key, key) == 0) {
        printf("Found: %s\n", node->children[index]->entry.value);
        return;
    }
    search(node->children[index], key + 1);
}

int main() {
    Node* root = createNode();
    char key[MAX_KEY_SIZE] = "apple";
    char value[MAX_VALUE_SIZE] = "red";
    insert(root, key, value);

    char searchKey[MAX_KEY_SIZE] = "apple";
    search(root, searchKey);

    printTree(root, 0);

    return 0;
}