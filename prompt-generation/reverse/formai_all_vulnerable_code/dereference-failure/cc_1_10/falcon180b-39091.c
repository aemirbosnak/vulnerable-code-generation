//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 100
#define MAX_VALUE_LENGTH 1000
#define HASH_TABLE_SIZE 1000

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} entry_t;

entry_t *hash_table[HASH_TABLE_SIZE];

int hash(char *key) {
    int hash_value = 0;
    int i = 0;
    while (key[i]) {
        hash_value += key[i];
        i++;
    }
    return hash_value % HASH_TABLE_SIZE;
}

void insert(char *key, char *value) {
    int index = hash(key);
    if (hash_table[index] == NULL) {
        hash_table[index] = (entry_t *) malloc(sizeof(entry_t));
        strcpy(hash_table[index]->key, key);
        strcpy(hash_table[index]->value, value);
    } else {
        printf("Key already exists.\n");
    }
}

void search(char *key) {
    int index = hash(key);
    if (hash_table[index]!= NULL) {
        printf("Value: %s\n", hash_table[index]->value);
    } else {
        printf("Key not found.\n");
    }
}

void delete(char *key) {
    int index = hash(key);
    if (hash_table[index]!= NULL) {
        free(hash_table[index]);
        hash_table[index] = NULL;
    } else {
        printf("Key not found.\n");
    }
}

int main() {
    hash_table[0] = (entry_t *) malloc(sizeof(entry_t));
    strcpy(hash_table[0]->key, "apple");
    strcpy(hash_table[0]->value, "red");

    insert("banana", "yellow");
    insert("orange", "orange");

    search("banana");
    search("pear");

    delete("banana");
    delete("orange");

    return 0;
}