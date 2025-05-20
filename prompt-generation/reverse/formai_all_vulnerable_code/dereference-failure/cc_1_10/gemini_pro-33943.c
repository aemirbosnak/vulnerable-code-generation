//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structure for database records
typedef struct {
    int id;
    char name[256];
    int age;
    // ... Other fields
} Record;

// Data structure for index entries
typedef struct {
    int id;
    int record_offset;
} IndexEntry;

// Database file structure
typedef struct {
    int num_records;
    int num_index_entries;
    Record *records;
    IndexEntry *index;
} Database;

// Open a database file
Database *database_open(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        return NULL;
    }

    // Read the database header
    Database *db = malloc(sizeof(Database));
    fread(&db->num_records, sizeof(int), 1, fp);
    fread(&db->num_index_entries, sizeof(int), 1, fp);

    // Allocate memory for the records and index entries
    db->records = malloc(sizeof(Record) * db->num_records);
    db->index = malloc(sizeof(IndexEntry) * db->num_index_entries);

    // Read the records and index entries from the file
    fread(db->records, sizeof(Record), db->num_records, fp);
    fread(db->index, sizeof(IndexEntry), db->num_index_entries, fp);

    fclose(fp);

    return db;
}

// Close a database file
void database_close(Database *db) {
    free(db->records);
    free(db->index);
    free(db);
}

// Get a record by its ID
Record *database_get_record(Database *db, int id) {
    // Binary search the index for the record's offset
    int low = 0;
    int high = db->num_index_entries - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (db->index[mid].id == id) {
            return &db->records[db->index[mid].record_offset];
        } else if (db->index[mid].id < id) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return NULL;
}

// Insert a new record into the database
void database_insert_record(Database *db, Record *record) {
    // Append the record to the end of the file
    FILE *fp = fopen("database.db", "ab");
    fwrite(record, sizeof(Record), 1, fp);
    fclose(fp);

    // Update the database header
    db->num_records++;

    // Create a new index entry for the record
    IndexEntry index_entry;
    index_entry.id = record->id;
    index_entry.record_offset = db->num_records - 1;

    // Insert the index entry into the index
    int i;
    for (i = db->num_index_entries - 1; i >= 0; i--) {
        if (db->index[i].id > index_entry.id) {
            db->index[i + 1] = db->index[i];
        } else {
            break;
        }
    }
    db->index[i + 1] = index_entry;

    // Update the database header
    db->num_index_entries++;
}

// Delete a record from the database
void database_delete_record(Database *db, int id) {
    // Get the record's offset
    int offset = -1;
    int i;
    for (i = 0; i < db->num_index_entries; i++) {
        if (db->index[i].id == id) {
            offset = db->index[i].record_offset;
            break;
        }
    }

    if (offset == -1) {
        return;
    }

    // Shift the records down to fill the gap
    for (i = offset + 1; i < db->num_records; i++) {
        db->records[i - 1] = db->records[i];
    }

    // Update the database header
    db->num_records--;

    // Shift the index entries down to fill the gap
    for (i = db->num_index_entries - 1; i >= 0; i--) {
        if (db->index[i].record_offset > offset) {
            db->index[i].record_offset--;
        }
    }

    // Update the database header
    db->num_index_entries--;
}

// Print the database to the console
void database_print(Database *db) {
    int i;
    for (i = 0; i < db->num_records; i++) {
        printf("Record %d: %s, %d\n", db->records[i].id, db->records[i].name, db->records[i].age);
    }
}

int main() {
    // Open the database file
    Database *db = database_open("database.db");

    // Insert a new record into the database
    Record record;
    record.id = 10;
    strcpy(record.name, "John Doe");
    record.age = 30;
    database_insert_record(db, &record);

    // Get a record from the database by its ID
    Record *record2 = database_get_record(db, 10);

    // Print the record to the console
    printf("Record: %s, %d\n", record2->name, record2->age);

    // Delete the record from the database
    database_delete_record(db, 10);

    // Close the database file
    database_close(db);

    return 0;
}