//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

// Create a bucket
struct Bucket {
    int value;
    struct Bucket *next;
};

// Create a hash table of buckets
struct HashTable {
    struct Bucket **buckets;
    int size;
};

// Create a new bucket
struct Bucket *createBucket(int value) {
    struct Bucket *bucket = (struct Bucket *)malloc(sizeof(struct Bucket));
    bucket->value = value;
    bucket->next = NULL;
    return bucket;
}

// Create a new hash table
struct HashTable *createHashTable(int size) {
    struct HashTable *hashTable = (struct HashTable *)malloc(sizeof(struct HashTable));
    hashTable->buckets = (struct Bucket **)malloc(sizeof(struct Bucket *) * size);
    hashTable->size = size;
    for (int i = 0; i < size; i++) {
        hashTable->buckets[i] = NULL;
    }
    return hashTable;
}

// Insert a value into the hash table
void insert(struct HashTable *hashTable, int value) {
    int index = value % hashTable->size;
    struct Bucket *bucket = hashTable->buckets[index];
    if (bucket == NULL) {
        hashTable->buckets[index] = createBucket(value);
    } else {
        while (bucket->next != NULL) {
            bucket = bucket->next;
        }
        bucket->next = createBucket(value);
    }
}

// Sort the values in the hash table
void sort(struct HashTable *hashTable) {
    for (int i = 0; i < hashTable->size; i++) {
        struct Bucket *bucket = hashTable->buckets[i];
        while (bucket != NULL) {
            printf("%d ", bucket->value);
            bucket = bucket->next;
        }
    }
}

// Free the memory allocated for the hash table
void freeHashTable(struct HashTable *hashTable) {
    for (int i = 0; i < hashTable->size; i++) {
        struct Bucket *bucket = hashTable->buckets[i];
        while (bucket != NULL) {
            struct Bucket *next = bucket->next;
            free(bucket);
            bucket = next;
        }
    }
    free(hashTable->buckets);
    free(hashTable);
}

int main() {
    int arr[] = {1, 4, 2, 3, 5, 7, 6, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Create a hash table with a size of 10
    struct HashTable *hashTable = createHashTable(10);

    // Insert the values into the hash table
    for (int i = 0; i < n; i++) {
        insert(hashTable, arr[i]);
    }

    // Sort the values in the hash table
    sort(hashTable);

    // Free the memory allocated for the hash table
    freeHashTable(hashTable);

    return 0;
}