//FormAI DATASET v1.0 Category: Database Indexing System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 50
#define MAX_VALUE_LENGTH 100

typedef struct Node {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
    struct Node *next;
} Node;

typedef struct Hashtable {
    int size;
    Node **table;
} Hashtable;

Hashtable *createHashtable(int size) {
    Hashtable *hash = (Hashtable *) malloc(sizeof(Hashtable));
    hash->size = size;
    hash->table = (Node **) malloc(size * sizeof(Node *));
    for (int i = 0; i < size; i++) {
        hash->table[i] = NULL;
    }
    return hash;
}

int hashFunction(char *key, int size) {
    int sum = 0;
    for (int i = 0; i < strlen(key); i++) {
        sum += key[i];
    }
    return sum % size;
}

void insert(Hashtable *hash, char *key, char *value) {
    int index = hashFunction(key, hash->size);
    Node *node = (Node *) malloc(sizeof(Node));
    strcpy(node->key, key);
    strcpy(node->value, value);
    node->next = hash->table[index];
    hash->table[index] = node;
}

char *search(Hashtable *hash, char *key) {
    int index = hashFunction(key, hash->size);
    Node *node = hash->table[index];
    while (node != NULL) {
        if (strcmp(node->key, key) == 0) {
            return node->value;
        }
        node = node->next;
    }
    return NULL;
}

void printHashtable(Hashtable *hash) {
    for (int i = 0; i < hash->size; i++) {
        Node *node = hash->table[i];
        printf("[%d]", i);
        while (node != NULL) {
            printf(" -> %s:%s", node->key, node->value);
            node = node->next;
        }
        printf(" -> NULL\n");
    }
}

int main() {
    Hashtable *hash = createHashtable(10);
    insert(hash, "apple", "fruit");
    insert(hash, "banana", "fruit");
    insert(hash, "chicken", "meat");
    insert(hash, "carrot", "vegetable");
    printf("Hashtable:\n");
    printHashtable(hash);
    printf("Search for 'apple': %s\n", search(hash, "apple"));
    printf("Search for 'beef': %s\n", search(hash, "beef"));
    return 0;
}