//FormAI DATASET v1.0 Category: Database Indexing System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of the database entry
typedef struct DatabaseEntry {
    int id;
    char *name;
    char *email;
    struct DatabaseEntry *next;
} DatabaseEntry;

// Define the structure of the index entry
typedef struct IndexEntry {
    int key;
    DatabaseEntry *value;
} IndexEntry;

// Define the structure of the index
typedef struct Index {
    int size;
    IndexEntry *entries;
} Index;

// Function to add an entry to the database
void addEntry(int id, char *name, char *email, DatabaseEntry **database) {
    DatabaseEntry *newEntry = malloc(sizeof(DatabaseEntry));
    newEntry->id = id;
    newEntry->name = malloc(strlen(name) + 1);
    strcpy(newEntry->name, name);
    newEntry->email = malloc(strlen(email) + 1);
    strcpy(newEntry->email, email);
    newEntry->next = *database;
    *database = newEntry;
}

// Function to create an index entry
IndexEntry createIndexEntry(int key, DatabaseEntry *value) {
    IndexEntry newEntry;
    newEntry.key = key;
    newEntry.value = value;
    return newEntry;
}

// Function to add an index entry to the index
void addIndexEntry(int key, DatabaseEntry *value, Index *index) {
    // Check if the index already contains an entry for the key
    for (int i = 0; i < index->size; i++) {
        if (index->entries[i].key == key) {
            // Key already exists, add entry to linked list
            value->next = index->entries[i].value;
            index->entries[i].value = value;
            return;
        }
    }

    // Key does not exist, create a new index entry
    IndexEntry newEntry = createIndexEntry(key, value);

    index->size++;
    index->entries = realloc(index->entries, index->size * sizeof(IndexEntry));
    index->entries[index->size - 1] = newEntry;
}

// Function to retrieve entries from the database by their id
DatabaseEntry *getById(int id, Index *index) {
    // Find the index entry that corresponds to the id
    for (int i = 0; i < index->size; i++) {
        if (index->entries[i].key == id) {
            return index->entries[i].value;
        }
    }

    // If no entry is found, return NULL
    return NULL;
}

int main() {
    DatabaseEntry *database = NULL;
    Index index;
    index.size = 0;
    index.entries = NULL;

    // Add some entries to the database
    addEntry(1, "John Doe", "john@example.com", &database);
    addEntry(2, "Jane Smith", "jane@example.com", &database);
    addEntry(3, "Bob Johnson", "bob@example.com", &database);
    addEntry(4, "Alice Brown", "alice@example.com", &database);
    addEntry(5, "Joe Black", "joe@example.com", &database);

    // Create an index for the database
    for (DatabaseEntry *current = database; current != NULL; current = current->next) {
        addIndexEntry(current->id, current, &index);
    }

    // Retrieve an entry from the database by id
    DatabaseEntry *entry = getById(3, &index);

    // Print the entry's information
    if (entry != NULL) {
        printf("Entry found:\n");
        printf("Id: %d\n", entry->id);
        printf("Name: %s\n", entry->name);
        printf("Email: %s\n", entry->email);
    } else {
        printf("Entry not found\n");
    }

    // Free memory allocated for the database and index
    for (DatabaseEntry *current = database; current != NULL;) {
        DatabaseEntry *temp = current;
        current = current->next;
        free(temp->name);
        free(temp->email);
        free(temp);
    }
    free(index.entries);

    return 0;
}