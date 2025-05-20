//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for the data entries
typedef struct {
    int id;
    char name[100];
} Entry;

// Define a structure for the index
typedef struct {
    int id;
    int position; // position of the entry in the file
} Index;

// Function declarations
void createDatabase(const char *filename, int entryCount);
void createIndex(const char *dbFile, const char *indexFile, int entryCount);
void searchIndex(const char *indexFile, int searchId);
void readDatabase(const char *filename, int position);

int main() {
    const char *dbFile = "database.dat";
    const char *indexFile = "index.dat";
    int entryCount = 5;

    // Step 1: Create the database
    createDatabase(dbFile, entryCount);

    // Step 2: Create the index
    createIndex(dbFile, indexFile, entryCount);

    // Step 3: Search the index
    int searchId = 3; // Example search ID
    searchIndex(indexFile, searchId);

    return 0;
}

// Function to create a simple database of entries
void createDatabase(const char *filename, int entryCount) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Failed to create the database");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < entryCount; i++) {
        Entry entry;
        entry.id = i + 1;
        sprintf(entry.name, "Name_%d", entry.id);
        fwrite(&entry, sizeof(Entry), 1, file);
    }

    fclose(file);
    printf("Database created successfully with %d entries.\n", entryCount);
}

// Function to create an index for the entries in the database
void createIndex(const char *dbFile, const char *indexFile, int entryCount) {
    FILE *db = fopen(dbFile, "rb");
    FILE *index = fopen(indexFile, "wb");
    if (db == NULL || index == NULL) {
        perror("Failed to create the index");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < entryCount; i++) {
        Entry entry;
        fread(&entry, sizeof(Entry), 1, db);
        Index indexEntry;
        indexEntry.id = entry.id;
        indexEntry.position = i * sizeof(Entry);
        fwrite(&indexEntry, sizeof(Index), 1, index);
    }

    fclose(db);
    fclose(index);
    printf("Index created successfully for the database.\n");
}

// Function to search for an entry in the index and read from the database
void searchIndex(const char *indexFile, int searchId) {
    FILE *index = fopen(indexFile, "rb");
    if (index == NULL) {
        perror("Failed to open the index file");
        exit(EXIT_FAILURE);
    }

    Index indexEntry;
    int found = 0;
    while (fread(&indexEntry, sizeof(Index), 1, index)) {
        if (indexEntry.id == searchId) {
            found = 1;
            printf("Found Entry ID: %d at Position: %d\n", indexEntry.id, indexEntry.position);
            readDatabase("database.dat", indexEntry.position);
            break;
        }
    }

    if (!found) {
        printf("Entry ID: %d not found in the index.\n", searchId);
    }

    fclose(index);
}

// Function to read an entry from the database given its position
void readDatabase(const char *filename, int position) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Failed to open the database file");
        exit(EXIT_FAILURE);
    }

    fseek(file, position, SEEK_SET);
    Entry entry;
    fread(&entry, sizeof(Entry), 1, file);
    printf("Entry - ID: %d, Name: %s\n", entry.id, entry.name);

    fclose(file);
}