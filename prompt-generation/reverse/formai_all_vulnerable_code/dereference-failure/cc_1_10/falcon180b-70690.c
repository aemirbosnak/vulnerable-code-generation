//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX 100

// Data structure for each entry in the index
typedef struct {
    char key[MAX_INDEX];
    int value;
} IndexEntry;

// Function to compare two keys for sorting purposes
int compareKeys(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

// Function to print the entire index
void printIndex(IndexEntry *index, int numEntries) {
    printf("Index:\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%s -> %d\n", index[i].key, index[i].value);
    }
}

// Function to search the index for a specific key and return its value
int searchIndex(IndexEntry *index, int numEntries, char *key) {
    IndexEntry entry = {.key = key };
    int result = bsearch(&entry, index, numEntries, sizeof(IndexEntry), compareKeys);
    if (result!= -1) {
        return index[result].value;
    } else {
        return -1;
    }
}

int main() {
    // Initialize the index with some sample data
    IndexEntry index[] = {
        {.key = "apple",.value = 1 },
        {.key = "banana",.value = 2 },
        {.key = "cherry",.value = 3 },
        {.key = "date",.value = 4 },
        {.key = "elderberry",.value = 5 }
    };
    int numEntries = sizeof(index) / sizeof(IndexEntry);

    // Print the initial index
    printf("Initial Index:\n");
    printIndex(index, numEntries);

    // Search for a key in the index
    char searchKey[] = "banana";
    int value = searchIndex(index, numEntries, searchKey);
    if (value == -1) {
        printf("Key not found.\n");
    } else {
        printf("Value for '%s': %d\n", searchKey, value);
    }

    // Add a new entry to the index
    IndexEntry newEntry = {.key = "fig",.value = 6 };
    numEntries++;
    IndexEntry *newIndex = realloc(index, numEntries * sizeof(IndexEntry));
    if (newIndex!= NULL) {
        memcpy(newIndex + numEntries - 1, &newEntry, sizeof(IndexEntry));
        qsort(newIndex, numEntries, sizeof(IndexEntry), compareKeys);
        printf("Updated Index:\n");
        printIndex(newIndex, numEntries);
    } else {
        printf("Error: Could not allocate memory for new index entry.\n");
    }

    return 0;
}