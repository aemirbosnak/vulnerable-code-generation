//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 1000000
#define INIT_SIZE 16

// Define a struct for our hash table
typedef struct {
    int *keys;
    int *values;
    int size;
    int capacity;
} HashTable;

// Function prototypes
HashTable* createHashTable();
int hash(int key, int capacity);
void resize(HashTable* table);
void destroyHashTable(HashTable* table);

// Main function
int main() {
    int i, j;
    HashTable* table = createHashTable();

    // Insert some key-value pairs
    for (i = 0; i < 100000; i++) {
        table->keys[i] = i;
        table->values[i] = i * 2;
    }

    // Print out the values
    for (i = 0; i < table->size; i++) {
        printf("%d: %d\n", table->keys[i], table->values[i]);
    }

    // Destroy the hash table
    destroyHashTable(table);

    return 0;
}

// Create a new hash table
HashTable* createHashTable() {
    HashTable* table = (HashTable*)malloc(sizeof(HashTable));
    table->keys = (int*)malloc(MAX_SIZE * sizeof(int));
    table->values = (int*)malloc(MAX_SIZE * sizeof(int));
    table->size = 0;
    table->capacity = INIT_SIZE;

    return table;
}

// Compute the hash value for a given key
int hash(int key, int capacity) {
    return key % capacity;
}

// Resize the hash table
void resize(HashTable* table) {
    int i, newCapacity;

    newCapacity = table->capacity * 2;
    table->keys = (int*)realloc(table->keys, newCapacity * sizeof(int));
    table->values = (int*)realloc(table->values, newCapacity * sizeof(int));
    table->capacity = newCapacity;
}

// Destroy the hash table
void destroyHashTable(HashTable* table) {
    free(table->keys);
    free(table->values);
    free(table);
}