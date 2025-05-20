//MISTRAL-7B DATASET v1.0 Category: File system simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TABLE_SIZE 101

typedef struct Node {
    char name[256];
    struct Node *next;
    int is_file;
    int size;
} Node;

typedef struct HashTable {
    Node **data;
} HashTable;

void init_hash_table(HashTable *ht) {
    ht->data = calloc(TABLE_SIZE, sizeof(Node*));
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->data[i] = NULL;
    }
}

int hash_function(char *name, int size) {
    int hash = 0;
    for (int i = 0; i < strlen(name); i++) {
        hash = (hash * 31 + name[i]) % size;
    }
    return hash;
}

void insert(HashTable *ht, char *name, int is_file, int size) {
    int hash = hash_function(name, TABLE_SIZE);
    Node *new_node = malloc(sizeof(Node));
    strcpy(new_node->name, name);
    new_node->is_file = is_file;
    new_node->size = size;
    new_node->next = ht->data[hash];
    ht->data[hash] = new_node;
}

void print_dir(HashTable *ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node *current = ht->data[i];
        if (current != NULL) {
            printf("%s", current->name);
            if (current->is_file) {
                printf(" (%d bytes)\n", current->size);
            } else {
                printf(" (directory)\n");
            }
            Node *next = current->next;
            free(current);
            current = next;
        }
    }
}

int main() {
    HashTable ht;
    init_hash_table(&ht);

    insert(&ht, "file1.txt", 1, 123);
    insert(&ht, "file2.txt", 1, 456);
    insert(&ht, "dir1", 0, 0);

    print_dir(&ht);

    return 0;
}