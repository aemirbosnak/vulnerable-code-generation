//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a key-value pair
typedef struct {
    char* key;
    int value;
} Pair;

// Structure to represent a database index
typedef struct {
    char* name;
    int size;
    Pair* data;
} Index;

// Function to initialize the database index
void initIndex(Index* index, char* name, int size) {
    index->name = name;
    index->size = size;
    index->data = (Pair*)malloc(size * sizeof(Pair));
}

// Function to insert a key-value pair into the database index
void insert(Index* index, char* key, int value) {
    if (index->size == index->size) {
        fprintf(stderr, "Database index is full!\n");
        exit(1);
    }

    Pair pair;
    pair.key = (char*)malloc(strlen(key) + 1);
    strcpy(pair.key, key);
    pair.value = value;

    index->data[index->size++] = pair;
}

// Function to find the index of a key in the database index
int find(Index* index, char* key) {
    for (int i = 0; i < index->size; i++) {
        if (strcmp(index->data[i].key, key) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to delete a key-value pair from the database index
void delete(Index* index, char* key) {
    int indexOfKey = find(index, key);
    if (indexOfKey == -1) {
        fprintf(stderr, "Key not found in database index!\n");
        exit(1);
    }

    Pair* pair = &index->data[indexOfKey];
    free(pair->key);
    free(pair);

    index->size--;
}

// Function to print the contents of the database index
void print(Index* index) {
    for (int i = 0; i < index->size; i++) {
        Pair pair = index->data[i];
        printf("Key: %s, Value: %d\n", pair.key, pair.value);
    }
}

int main() {
    Index index;
    initIndex(&index, "database", 5);

    insert(&index, "apple", 1);
    insert(&index, "banana", 2);
    insert(&index, "cherry", 3);
    insert(&index, "date", 4);

    printf("Database index:\n");
    print(&index);

    delete(&index, "banana");
    printf("Database index after deleting 'banana':\n");
    print(&index);

    return 0;
}