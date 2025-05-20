//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the hash table size
#define TABLE_SIZE 1000

// Define the hash function
unsigned int hash(const char* key, unsigned int size) {
    unsigned int hash = 5381;
    int c;
    while ((c = *key++)!= '\0') {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return hash % size;
}

// Define the hash table structure
typedef struct {
    char* key;
    char* value;
} HashEntry;

HashEntry table[TABLE_SIZE];

// Function to add a new item to the database
void add(char* key, char* value) {
    int index = hash(key, TABLE_SIZE);
    if (table[index].key == NULL) {
        table[index].key = (char*)malloc(strlen(key) + 1);
        strcpy(table[index].key, key);
        table[index].value = (char*)malloc(strlen(value) + 1);
        strcpy(table[index].value, value);
    } else {
        printf("Key already exists in the database\n");
    }
}

// Function to delete an item from the database
void delete(char* key) {
    int index = hash(key, TABLE_SIZE);
    if (table[index].key!= NULL) {
        free(table[index].key);
        free(table[index].value);
        table[index].key = NULL;
        table[index].value = NULL;
    } else {
        printf("Key not found in the database\n");
    }
}

// Function to search for an item in the database
char* search(char* key) {
    int index = hash(key, TABLE_SIZE);
    if (table[index].key!= NULL) {
        return table[index].value;
    } else {
        return NULL;
    }
}

int main() {
    char* key = "apple";
    char* value = "fruit";
    add(key, value);
    printf("%s -> %s\n", key, search(key));
    delete(key);
    return 0;
}