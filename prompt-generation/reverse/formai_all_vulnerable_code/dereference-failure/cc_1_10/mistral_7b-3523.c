//MISTRAL-7B DATASET v1.0 Category: Cryptographic hash function ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HASH_SIZE 32

typedef struct HashTable {
    unsigned char data[HASH_SIZE];
    struct HashTable *next;
} HashTable;

HashTable *hash_table = NULL;

unsigned int hash_function(char *str) {
    unsigned int hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;

    return hash % HASH_SIZE;
}

void add_hash(char *key, char *value) {
    HashTable *new_node = (HashTable *)malloc(sizeof(HashTable));
    HashTable *current = hash_table;

    strcpy(new_node->data, key);
    new_node->next = NULL;

    if (hash_table == NULL) {
        hash_table = new_node;
    } else {
        int pos = hash_function(key);

        while (current != NULL && current->next != NULL && strcmp(current->next->data, key) != 0) {
            current = current->next;
        }

        if (current->next != NULL) {
            new_node->next = current->next;
            current->next = new_node;
        } else {
            current->next = new_node;
        }
    }

    strcpy(new_node->next->data, value);
}

void print_hash() {
    HashTable *current = hash_table;

    printf("Hash Table:\n");
    while (current != NULL) {
        printf("%s --> %s\n", current->data, current->next ? current->next->data : "");
        current = current->next;
    }
}

int main() {
    add_hash("Survivor1", "Password1");
    add_hash("Survivor2", "Password2");
    add_hash("Survivor3", "Password3");
    print_hash();

    return 0;
}

// Simple hash function based on djb2 algorithm
// but in post-apocalyptic style
unsigned int post_apocalyptic_hash(char *str) {
    unsigned int hash = 0xDEADBEEF;
    int c, i;

    for (i = 0; str[i] != '\0'; i++) {
        c = (unsigned char)str[i];
        hash = ((hash << 5) + hash) + c;
        hash = hash ^ (hash >> 27);
    }

    return hash;
}