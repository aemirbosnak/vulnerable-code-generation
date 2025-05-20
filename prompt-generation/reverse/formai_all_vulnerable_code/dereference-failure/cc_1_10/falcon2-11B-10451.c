//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure to hold the key and the value
struct Entry {
    char key[20];
    char value[100];
};

// Define the structure to hold the index
struct Index {
    int count;
    struct Entry *entries;
};

// Function to create a new index
struct Index* createIndex() {
    struct Index *index = (struct Index*)malloc(sizeof(struct Index));
    index->count = 0;
    index->entries = NULL;
    return index;
}

// Function to add a new entry to the index
void addEntry(struct Index *index, char *key, char *value) {
    struct Entry *newEntry = (struct Entry*)malloc(sizeof(struct Entry));
    strcpy(newEntry->key, key);
    strcpy(newEntry->value, value);
    index->entries = (struct Entry*)realloc(index->entries, (index->count + 1) * sizeof(struct Entry));
    index->entries[index->count] = *newEntry;
    index->count++;
}

// Function to search for a key in the index
int searchKey(struct Index *index, char *key) {
    int i;
    for (i = 0; i < index->count; i++) {
        if (strcmp(index->entries[i].key, key) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to delete an entry from the index
void deleteEntry(struct Index *index, int indexPosition) {
    index->entries = (struct Entry*)realloc(index->entries, (index->count - 1) * sizeof(struct Entry));
    for (int i = indexPosition; i < index->count - 1; i++) {
        index->entries[i] = index->entries[i + 1];
    }
    index->count--;
}

// Function to print the index
void printIndex(struct Index *index) {
    int i;
    printf("Index: %d\n", index->count);
    for (i = 0; i < index->count; i++) {
        printf("Key: %s, Value: %s\n", index->entries[i].key, index->entries[i].value);
    }
}

// Main function
int main() {
    struct Index *index = createIndex();
    addEntry(index, "apple", "red");
    addEntry(index, "banana", "yellow");
    addEntry(index, "cherry", "red");
    addEntry(index, "date", "yellow");
    addEntry(index, "elderberry", "purple");

    printf("Index: %d\n", index->count);
    printIndex(index);

    int indexPosition = searchKey(index, "elderberry");
    if (indexPosition!= -1) {
        deleteEntry(index, indexPosition);
    }

    printf("Index: %d\n", index->count);
    printIndex(index);

    return 0;
}