//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Hash table entry
typedef struct {
    char *key;
    int value;
} Entry;

// Hash table
typedef struct {
    Entry **entries;
    int size;
} HashTable;

// Create a new hash table
HashTable *create_hash_table(int size) {
    HashTable *table = malloc(sizeof(HashTable));
    table->size = size;
    table->entries = malloc(sizeof(Entry *) * size);
    for (int i = 0; i < size; i++) {
        table->entries[i] = NULL;
    }
    return table;
}

// Destroy a hash table
void destroy_hash_table(HashTable *table) {
    for (int i = 0; i < table->size; i++) {
        if (table->entries[i] != NULL) {
            free(table->entries[i]->key);
            free(table->entries[i]);
        }
    }
    free(table->entries);
    free(table);
}

// Hash function
int hash(char *key, int size) {
    int hash = 0;
    for (int i = 0; i < strlen(key); i++) {
        hash += key[i];
    }
    return hash % size;
}

// Insert a key-value pair into a hash table
void insert(HashTable *table, char *key, int value) {
    int index = hash(key, table->size);
    while (table->entries[index] != NULL && strcmp(table->entries[index]->key, key) != 0) {
        index = (index + 1) % table->size;
    }
    if (table->entries[index] == NULL) {
        table->entries[index] = malloc(sizeof(Entry));
        table->entries[index]->key = strdup(key);
    }
    table->entries[index]->value = value;
}

// Get a value from a hash table
int get(HashTable *table, char *key) {
    int index = hash(key, table->size);
    while (table->entries[index] != NULL && strcmp(table->entries[index]->key, key) != 0) {
        index = (index + 1) % table->size;
    }
    if (table->entries[index] != NULL) {
        return table->entries[index]->value;
    } else {
        return -1;
    }
}

// Print a hash table
void print_hash_table(HashTable *table) {
    for (int i = 0; i < table->size; i++) {
        if (table->entries[i] != NULL) {
            printf("%s: %d\n", table->entries[i]->key, table->entries[i]->value);
        }
    }
}

// Main function
int main() {
    // Create a hash table
    HashTable *table = create_hash_table(10);

    // Insert some key-value pairs into the hash table
    insert(table, "name", "John");
    insert(table, "age", 30);
    insert(table, "city", "New York");

    // Get a value from the hash table
    int age = get(table, "age");
    printf("Age: %d\n", age);

    // Print the hash table
    print_hash_table(table);

    // Destroy the hash table
    destroy_hash_table(table);

    return 0;
}