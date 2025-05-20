//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: visionary
// Welcome to the ArcaneDB, a visionary simulation of a futuristic database system.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a database record
typedef struct {
    char *key;
    char *value;
} Record;

// Define the structure of a database
typedef struct {
    int numRecords;
    Record *records;
} Database;

// Create a new database
Database *createDatabase() {
    Database *db = malloc(sizeof(Database));
    db->numRecords = 0;
    db->records = NULL;
    return db;
}

// Insert a record into a database
void insertRecord(Database *db, char *key, char *value) {
    // Allocate memory for the new record
    Record *record = malloc(sizeof(Record));
    record->key = strdup(key);
    record->value = strdup(value);

    // Add the new record to the database
    db->records = realloc(db->records, (db->numRecords + 1) * sizeof(Record));
    db->records[db->numRecords++] = *record;
}

// Get a record from a database
char *getRecord(Database *db, char *key) {
    // Search for the record with the specified key
    for (int i = 0; i < db->numRecords; i++) {
        if (strcmp(db->records[i].key, key) == 0) {
            return db->records[i].value;
        }
    }

    // Return NULL if the record is not found
    return NULL;
}

// Delete a record from a database
void deleteRecord(Database *db, char *key) {
    // Search for the record with the specified key
    for (int i = 0; i < db->numRecords; i++) {
        if (strcmp(db->records[i].key, key) == 0) {
            // Free the memory allocated for the record
            free(db->records[i].key);
            free(db->records[i].value);

            // Shift the remaining records down one position
            for (int j = i + 1; j < db->numRecords; j++) {
                db->records[j - 1] = db->records[j];
            }

            // Decrement the number of records in the database
            db->numRecords--;

            // Reallocate the memory for the records
            db->records = realloc(db->records, db->numRecords * sizeof(Record));

            // Break out of the loop
            break;
        }
    }
}

// Print the contents of a database
void printDatabase(Database *db) {
    printf("Database:\n");
    for (int i = 0; i < db->numRecords; i++) {
        printf("  %s: %s\n", db->records[i].key, db->records[i].value);
    }
}

// Destroy a database
void destroyDatabase(Database *db) {
    // Free the memory allocated for each record
    for (int i = 0; i < db->numRecords; i++) {
        free(db->records[i].key);
        free(db->records[i].value);
    }

    // Free the memory allocated for the records array
    free(db->records);

    // Free the memory allocated for the database
    free(db);
}

// Main function
int main() {
    // Create a new database
    Database *db = createDatabase();

    // Insert some records into the database
    insertRecord(db, "key1", "value1");
    insertRecord(db, "key2", "value2");
    insertRecord(db, "key3", "value3");

    // Print the contents of the database
    printDatabase(db);

    // Get a record from the database
    char *value = getRecord(db, "key2");
    printf("The value for key2 is: %s\n", value);

    // Delete a record from the database
    deleteRecord(db, "key3");

    // Print the contents of the database
    printDatabase(db);

    // Destroy the database
    destroyDatabase(db);

    return 0;
}