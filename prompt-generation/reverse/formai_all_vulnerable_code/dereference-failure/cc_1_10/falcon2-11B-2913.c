//Falcon2-11B DATASET v1.0 Category: Database simulation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the size of the hash table
#define TABLE_SIZE 10

// Define the hash function
int hash(const char *str, int size) {
    int hash = 0;
    for (int i = 0; i < size; i++) {
        hash = (hash << 2) ^ str[i];
    }
    return hash % TABLE_SIZE;
}

// Define the data structure for the hash table
struct HashTable {
    int size;
    char **table;
};

// Initialize the hash table
void init_hash_table(struct HashTable *table, int size) {
    table->size = size;
    table->table = (char **)malloc(size * sizeof(char *));
    for (int i = 0; i < size; i++) {
        table->table[i] = NULL;
    }
}

// Free the memory allocated for the hash table
void free_hash_table(struct HashTable *table) {
    for (int i = 0; i < table->size; i++) {
        free(table->table[i]);
    }
    free(table->table);
}

// Insert a key-value pair into the hash table
void insert(struct HashTable *table, const char *key, const char *value) {
    int index = hash(key, strlen(key));
    table->table[index] = (char *)malloc(strlen(value) + 1);
    strcpy(table->table[index], value);
}

// Delete a key-value pair from the hash table
void delete(struct HashTable *table, const char *key) {
    int index = hash(key, strlen(key));
    free(table->table[index]);
    table->table[index] = NULL;
}

// Search for a key in the hash table
int search(struct HashTable *table, const char *key) {
    int index = hash(key, strlen(key));
    return (table->table[index]!= NULL && strcmp(key, table->table[index]) == 0)? 1 : 0;
}

// Print the contents of the hash table
void print_hash_table(struct HashTable *table) {
    for (int i = 0; i < table->size; i++) {
        if (table->table[i]!= NULL) {
            printf("%s\n", table->table[i]);
        }
    }
}

int main() {
    struct HashTable table;
    init_hash_table(&table, TABLE_SIZE);

    // Insert some key-value pairs
    insert(&table, "apple", "fruit");
    insert(&table, "banana", "fruit");
    insert(&table, "orange", "fruit");
    insert(&table, "grape", "fruit");

    // Search for a key
    printf("Search for 'apple': %s\n", search(&table, "apple")? "found" : "not found");

    // Delete a key-value pair
    delete(&table, "banana");

    // Print the contents of the hash table
    print_hash_table(&table);

    free_hash_table(&table);
    return 0;
}