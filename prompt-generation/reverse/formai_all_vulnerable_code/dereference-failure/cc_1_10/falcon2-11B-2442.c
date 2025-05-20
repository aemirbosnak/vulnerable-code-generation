//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure used to store key-value pairs in the hash table
typedef struct {
    char* key;
    int value;
} Entry;

// Hash function used to calculate the index of a key in the hash table
unsigned int hash(const char* str) {
    unsigned int h = 0;
    while (*str++) h += *str;
    return h;
}

// Hash table used to store key-value pairs
Entry* table[100];

// Function to insert a key-value pair into the hash table
void insert(const char* key, int value) {
    // Calculate the index of the key in the hash table
    int index = hash(key) % 100;

    // If the entry already exists, update its value
    if (table[index]) {
        Entry* entry = table[index];
        entry->value = value;
    } else {
        // Otherwise, create a new entry
        Entry* newEntry = (Entry*) malloc(sizeof(Entry));
        strcpy(newEntry->key, key);
        newEntry->value = value;
        table[index] = newEntry;
    }
}

// Function to delete a key-value pair from the hash table
void delete(const char* key) {
    // Calculate the index of the key in the hash table
    int index = hash(key) % 100;

    // If the entry exists, free its memory
    if (table[index]) {
        Entry* entry = table[index];
        free(entry);
        table[index] = NULL;
    }
}

// Function to search for a key-value pair in the hash table
int search(const char* key) {
    // Calculate the index of the key in the hash table
    int index = hash(key) % 100;

    // If the entry exists, return its value
    if (table[index]) {
        Entry* entry = table[index];
        return entry->value;
    } else {
        return -1; // Key not found
    }
}

int main() {
    char* key;
    int value;

    printf("Enter key (or 'q' to quit): ");
    scanf("%s", key);
    while (*key!= 'q') {
        if (*key == 'i') {
            printf("Enter value: ");
            scanf("%d", &value);
            insert(key, value);
        } else if (*key == 'd') {
            delete(key);
        } else if (*key =='s') {
            printf("Value for key '%s': %d\n", key, search(key));
        }
        printf("Enter key (or 'q' to quit): ");
        scanf("%s", key);
    }
    return 0;
}