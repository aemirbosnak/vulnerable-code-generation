//MISTRAL-7B DATASET v1.0 Category: Database Indexing System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define TABLE_SIZE 101

typedef struct {
    char key[256];
    int value;
} Record;

unsigned int hash_function(char *key) {
    unsigned int hash = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        hash = (hash * 31 + key[i]) & (TABLE_SIZE - 1);
    }
    return hash;
}

struct HashTable {
    Record *data;
};

struct HashTable *create_hash_table() {
    struct HashTable *ht = (struct HashTable *) malloc(sizeof(struct HashTable));
    ht->data = (Record *) calloc(TABLE_SIZE, sizeof(Record));
    return ht;
}

void put(struct HashTable *ht, char *key, int value) {
    int hash = hash_function(key);

    if (ht->data[hash].value == -1) {
        strcpy(ht->data[hash].key, key);
        ht->data[hash].value = value;
    } else {
        while (strcmp(ht->data[hash].key, key) != 0) {
            int next_hash = (hash + 1) & (TABLE_SIZE - 1);
            if (ht->data[next_hash].value == -1) {
                strcpy(ht->data[next_hash].key, key);
                ht->data[next_hash].value = value;
                break;
            }
            hash = next_hash;
        }
    }
}

int get(struct HashTable *ht, char *key) {
    int hash = hash_function(key);

    if (ht->data[hash].value == -1) {
        return -1;
    }

    if (strcmp(ht->data[hash].key, key) == 0) {
        return ht->data[hash].value;
    }

    int next_hash = (hash + 1) & (TABLE_SIZE - 1);
    while (strcmp(ht->data[next_hash].key, key) != 0) {
        next_hash = (next_hash + 1) & (TABLE_SIZE - 1);
        if (ht->data[next_hash].value == -1) {
            return -1;
        }
    }

    return ht->data[next_hash].value;
}

void destroy_hash_table(struct HashTable *ht) {
    free(ht->data);
    free(ht);
}

int main() {
    struct HashTable *ht = create_hash_table();

    put(ht, "apple", 1);
    put(ht, "banana", 2);
    put(ht, "cherry", 3);
    put(ht, "orange", 4);

    printf("Value for key 'apple': %d\n", get(ht, "apple"));
    printf("Value for key 'orange': %d\n", get(ht, "orange"));

    destroy_hash_table(ht);

    return 0;
}