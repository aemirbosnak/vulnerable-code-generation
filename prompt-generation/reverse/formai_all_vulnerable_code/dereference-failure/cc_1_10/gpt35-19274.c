//FormAI DATASET v1.0 Category: Database Indexing System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#define MAX_RECORDS 5000
#define MAX_NAME_SIZE 100

// Define the record structure
typedef struct {
    int id;
    char name[MAX_NAME_SIZE];
    float score;
} Record;

// Define the index structure
typedef struct {
    int id;
    int offset;
} Index;

// Define the database structure
typedef struct {
    FILE* data_file;
    Index* index;
    int num_records;
} Database;

// Function to add a record to the database
void add_record(Database* db, Record r) {
    // Write the record to the data file
    fseek(db->data_file, 0, SEEK_END);
    fwrite(&r, sizeof(Record), 1, db->data_file);
    
    // Add an index entry for the record
    db->num_records++;
    db->index = realloc(db->index, db->num_records * sizeof(Index));
    db->index[db->num_records-1].id = r.id;
    db->index[db->num_records-1].offset = ftell(db->data_file) - sizeof(Record);
}

// Function to find a record by ID
Record find_record(Database* db, int id) {
    // Binary search on the index array
    int low = 0;
    int high = db->num_records - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (db->index[mid].id < id) {
            low = mid + 1;
        } else if (db->index[mid].id > id) {
            high = mid - 1;
        } else {
            // Found the record, so read it from the data file
            Record r;
            fseek(db->data_file, db->index[mid].offset, SEEK_SET);
            fread(&r, sizeof(Record), 1, db->data_file);
            return r;
        }
    }
    // Record not found
    Record not_found = {-1, "", -1};
    return not_found;
}

int main() {
    // Open the data file and create an empty index
    FILE* data_file = fopen("data.bin", "wb+");
    Index* index = malloc(MAX_RECORDS * sizeof(Index));
    int num_records = 0;
    
    // Create the database object
    Database db = {data_file, index, num_records};
    
    // Add some sample records to the database
    Record r1 = {1, "Alice", 85.6};
    Record r2 = {2, "Bob", 92.3};
    Record r3 = {3, "Charlie", 78.4};
    Record r4 = {4, "Dave", 80.1};
    add_record(&db, r1);
    add_record(&db, r2);
    add_record(&db, r3);
    add_record(&db, r4);
    
    // Find a record by ID
    Record found = find_record(&db, 2);
    printf("Record %d: %s (%.1f)\n", found.id, found.name, found.score);
    
    // Clean up
    fclose(data_file);
    free(index);
    return 0;
}