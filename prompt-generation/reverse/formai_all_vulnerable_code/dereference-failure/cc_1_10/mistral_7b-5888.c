//MISTRAL-7B DATASET v1.0 Category: Database Indexing System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TABLE_SIZE 101
#define KEY_LENGTH 50
#define DATA_LENGTH 100

typedef struct {
    char key[KEY_LENGTH];
    char data[DATA_LENGTH];
} Record;

typedef struct HashNode {
    Record record;
    struct HashNode *next;
} HashNode;

unsigned long hash(char *str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % TABLE_SIZE;
}

HashNode *create_node(char *key, char *data) {
    HashNode *new_node = (HashNode *) malloc(sizeof(HashNode));

    strncpy(new_node->record.key, key, KEY_LENGTH);
    strncpy(new_node->record.data, data, DATA_LENGTH);
    new_node->next = NULL;

    return new_node;
}

void insert(char *key, char *data, HashNode **hash_table) {
    unsigned long index = hash(key);
    HashNode *new_node = create_node(key, data);

    if (!hash_table[index]) {
        hash_table[index] = new_node;
    } else {
        HashNode *current = hash_table[index];

        while (current->next) {
            current = current->next;
        }

        current->next = new_node;
    }
}

HashNode *search(char *key, HashNode **hash_table) {
    unsigned long index = hash(key);
    HashNode *current = hash_table[index];

    while (current) {
        if (strcmp(current->record.key, key) == 0) {
            return current;
        }

        current = current->next;
    }

    return NULL;
}

void print_record(HashNode *node) {
    printf("Key: %s\n", node->record.key);
    printf("Data: %s\n", node->record.data);
}

int main() {
    HashNode *hash_table[TABLE_SIZE] = {NULL};
    Record test_record = {"example_key", "example_data"};
    char test_key[KEY_LENGTH] = "example_key";

    insert(test_key, test_record.key, hash_table);

    HashNode *found_node = search(test_key, hash_table);

    if (found_node) {
        printf("Found record:\n");
        print_record(found_node);
    } else {
        printf("Record not found.\n");
    }

    return 0;
}