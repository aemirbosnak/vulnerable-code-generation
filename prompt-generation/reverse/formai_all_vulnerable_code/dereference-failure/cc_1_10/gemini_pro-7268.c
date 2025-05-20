//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 256
#define MAX_INDEX_SIZE 10000

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} Person;

typedef struct {
    char *name;
    int age;
} IndexEntry;

int compare_index_entries(const void *a, const void *b) {
    IndexEntry *entry1 = (IndexEntry *)a;
    IndexEntry *entry2 = (IndexEntry *)b;

    return strcmp(entry1->name, entry2->name);
}

int main() {
    // Initialize the database
    Person database[] = {
        {"John Doe", 30},
        {"Jane Doe", 25},
        {"Mark Smith", 40},
        {"Mary Smith", 35},
        {"Tom Jones", 20},
    };
    int database_size = sizeof(database) / sizeof(Person);

    // Create an index for the database
    IndexEntry index[MAX_INDEX_SIZE];
    for (int i = 0; i < database_size; i++) {
        index[i].name = database[i].name;
        index[i].age = database[i].age;
    }

    // Sort the index
    qsort(index, database_size, sizeof(IndexEntry), compare_index_entries);

    // Use the index to search for a person
    char *name = "John Doe";
    IndexEntry *result = bsearch(&name, index, database_size, sizeof(IndexEntry), compare_index_entries);

    if (result != NULL) {
        // The person was found
        printf("Found person: %s, age %d\n", result->name, result->age);
    } else {
        // The person was not found
        printf("Person not found\n");
    }

    return 0;
}