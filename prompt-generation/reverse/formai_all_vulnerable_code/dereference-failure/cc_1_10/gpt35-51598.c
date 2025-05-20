//FormAI DATASET v1.0 Category: Database Indexing System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 10000
#define MAX_NAME_LEN 50

typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    double score;
} Record;

// Index entry structure
typedef struct {
    char key[MAX_NAME_LEN];
    int record_idx;
} IndexEntry;

// Index structure
typedef struct {
    IndexEntry *entries;
    int num_entries;
} Index;

// Database structure
typedef struct {
    Record *records;
    int num_records;
    Index *index;
} Database;

// Function to create a new record
Record create_record(int id, char *name, double score) {
    Record record;
    record.id = id;
    strncpy(record.name, name, MAX_NAME_LEN);
    record.score = score;
    return record;
}

// Function to create a new index entry
IndexEntry create_index_entry(char *key, int record_idx) {
    IndexEntry index_entry;
    strncpy(index_entry.key, key, MAX_NAME_LEN);
    index_entry.record_idx = record_idx;
    return index_entry;
}

// Function to create a new index
Index *create_index() {
    Index *index = malloc(sizeof(Index));
    index->entries = NULL;
    index->num_entries = 0;
    return index;
}

// Function to insert a record into the database
void insert_record(Database *database, Record record) {
    // Increase the size of the records array
    database->records = realloc(database->records, (database->num_records + 1) * sizeof(Record));
    // Insert the record at the end of the array
    database->records[database->num_records] = record;
    // Update the number of records
    database->num_records++;

    // Insert an index entry for the record into the index
    char *key = record.name;
    Index *index = database->index;
    index->entries = realloc(index->entries, (index->num_entries + 1) * sizeof(IndexEntry));
    index->entries[index->num_entries] = create_index_entry(key, database->num_records - 1);
    index->num_entries++;
}

// Function to get the index entries for a given key
IndexEntry *get_index_entries_for_key(Database *database, char *key, int *num_entries) {
    Index *index = database->index;
    int count = 0;

    // Count the number of index entries with the given key
    for (int i = 0; i < index->num_entries; i++) {
        if (strcmp(index->entries[i].key, key) == 0) {
            count++;
        }
    }

    // Allocate memory for the index entry array
    IndexEntry *entries = malloc(count * sizeof(IndexEntry));
    int idx = 0;

    // Add each matching index entry to the array
    for (int i = 0; i < index->num_entries; i++) {
        if (strcmp(index->entries[i].key, key) == 0) {
            entries[idx] = index->entries[i];
            idx++;
        }
    }

    // Set the number of entries and return the array
    *num_entries = count;
    return entries;
}

// Function to print the records for a given array of index entries
void print_records(Database *database, IndexEntry *entries, int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        Record record = database->records[entries[i].record_idx];
        printf("ID: %d, Name: %s, Score: %.2f\n", record.id, record.name, record.score);
    }
}

int main() {
    // Create a new database and index
    Database database;
    database.records = malloc(MAX_RECORDS * sizeof(Record));
    database.num_records = 0;
    database.index = create_index();

    // Insert some test records
    insert_record(&database, create_record(1, "Alice", 84.3));
    insert_record(&database, create_record(2, "Bob", 76.8));
    insert_record(&database, create_record(3, "Charlie", 90.1));
    insert_record(&database, create_record(4, "Alice", 81.6));
    insert_record(&database, create_record(5, "David", 88.0));
    insert_record(&database, create_record(6, "Bob", 79.2));
    insert_record(&database, create_record(7, "Eve", 92.5));
    insert_record(&database, create_record(8, "Frank", 87.7));
    insert_record(&database, create_record(9, "Eve", 94.2));

    // Get index entries and print records for key "Alice"
    printf("Records for key 'Alice':\n");
    int num_entries;
    IndexEntry *entries = get_index_entries_for_key(&database, "Alice", &num_entries);
    print_records(&database, entries, num_entries);
    free(entries);

    // Get index entries and print records for key "Bob"
    printf("Records for key 'Bob':\n");
    entries = get_index_entries_for_key(&database, "Bob", &num_entries);
    print_records(&database, entries, num_entries);
    free(entries);

    // Get index entries and print records for key "Eve"
    printf("Records for key 'Eve':\n");
    entries = get_index_entries_for_key(&database, "Eve", &num_entries);
    print_records(&database, entries, num_entries);
    free(entries);

    // Free memory for records and index
    free(database.records);
    free(database.index->entries);
    free(database.index);

    return 0;
}