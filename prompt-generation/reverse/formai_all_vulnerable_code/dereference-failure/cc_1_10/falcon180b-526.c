//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the maximum number of elements in the database
#define MAX_ELEMENTS 100000

// Define the size of each bucket in the hash table
#define BUCKET_SIZE 10

// Define the structure for each element in the database
typedef struct {
    int key;
    double value;
} Element;

// Define the structure for each bucket in the hash table
typedef struct {
    int count;
    Element elements[BUCKET_SIZE];
} Bucket;

// Define the structure for the hash table
typedef struct {
    Bucket *table;
    int size;
} HashTable;

// Initialize the hash table with the given size
HashTable *initHashTable(int size) {
    HashTable *hashTable = (HashTable *)malloc(sizeof(HashTable));
    hashTable->size = size;
    hashTable->table = (Bucket *)malloc(sizeof(Bucket) * size);
    for (int i = 0; i < size; i++) {
        hashTable->table[i].count = 0;
    }
    return hashTable;
}

// Calculate the hash code for a given key
int hashCode(int key, int size) {
    return key % size;
}

// Add an element to the hash table
void addElement(HashTable *hashTable, int key, double value) {
    int index = hashCode(key, hashTable->size);
    Bucket *bucket = &hashTable->table[index];
    for (int i = 0; i < bucket->count; i++) {
        if (bucket->elements[i].key == key) {
            bucket->elements[i].value += value;
            return;
        }
    }
    if (bucket->count == BUCKET_SIZE) {
        printf("Error: Bucket is full!\n");
        return;
    }
    bucket->elements[bucket->count] = (Element){key, value};
    bucket->count++;
}

// Retrieve the value for a given key from the hash table
double getValue(HashTable *hashTable, int key) {
    int index = hashCode(key, hashTable->size);
    Bucket *bucket = &hashTable->table[index];
    for (int i = 0; i < bucket->count; i++) {
        if (bucket->elements[i].key == key) {
            return bucket->elements[i].value;
        }
    }
    printf("Error: Key not found!\n");
    return -1;
}

// Main function to demonstrate the usage of the hash table
int main() {
    HashTable *hashTable = initHashTable(MAX_ELEMENTS);

    // Add some elements to the hash table
    addElement(hashTable, 1, 10.0);
    addElement(hashTable, 2, 20.0);
    addElement(hashTable, 3, 30.0);
    addElement(hashTable, 4, 40.0);
    addElement(hashTable, 5, 50.0);

    // Retrieve the values for some keys from the hash table
    printf("Value for key 1: %lf\n", getValue(hashTable, 1));
    printf("Value for key 2: %lf\n", getValue(hashTable, 2));
    printf("Value for key 3: %lf\n", getValue(hashTable, 3));
    printf("Value for key 4: %lf\n", getValue(hashTable, 4));
    printf("Value for key 5: %lf\n", getValue(hashTable, 5));

    // Free the memory allocated for the hash table
    free(hashTable->table);
    free(hashTable);

    return 0;
}