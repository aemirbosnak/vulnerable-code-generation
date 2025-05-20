//MISTRAL-7B DATASET v1.0 Category: Database Indexing System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAB_SIZE 128
#define HASH_SIZE 1024
#define KEY_LEN 32

typedef struct {
    char key[KEY_LEN];
    int value;
} Entry;

typedef struct HashTable {
    Entry *data;
} HashTable;

HashTable *create_hash_table() {
    HashTable *ht = malloc(sizeof(HashTable));
    ht->data = calloc(HASH_SIZE, sizeof(Entry));
    return ht;
}

int hash(char *str) {
    int hash = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        hash = (hash * 31 + str[i]) & (HASH_SIZE - 1);
    }
    return hash;
}

int find_entry(HashTable *ht, char *key) {
    int index = hash(key) % HASH_SIZE;
    Entry *entry = &ht->data[index];
    while (strcmp(entry->key, key) != 0 && entry->key[0] != '\0') {
        index = (index + 1) % HASH_SIZE;
        entry = &ht->data[index];
    }
    if (entry->key[0] == '\0') {
        return -1;
    }
    return index;
}

void put(HashTable *ht, char *key, int value) {
    int index = find_entry(ht, key);
    if (index != -1) {
        Entry *entry = &ht->data[index];
        entry->value = value;
        return;
    }

    int new_index = hash(key) % HASH_SIZE;
    Entry *new_entry = &ht->data[new_index];
    strcpy(new_entry->key, key);
    new_entry->value = value;
}

int get(HashTable *ht, char *key) {
    int index = find_entry(ht, key);
    if (index == -1) {
        return -1;
    }
    return ht->data[index].value;
}

int main(int argc, char *argv[]) {
    HashTable *ht = create_hash_table();

    put(ht, "apple", 1);
    put(ht, "banana", 2);
    put(ht, "cherry", 3);
    put(ht, "orange", 4);

    printf("get apple: %d\n", get(ht, "apple"));
    printf("get banana: %d\n", get(ht, "banana"));
    printf("get cherry: %d\n", get(ht, "cherry"));
    printf("get orange: %d\n", get(ht, "orange"));
    printf("get grape: %d\n", get(ht, "grape"));

    return 0;
}