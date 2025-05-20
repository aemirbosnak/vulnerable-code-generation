//FormAI DATASET v1.0 Category: Database Indexing System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a record in the database
typedef struct record {
    int id;
    char name[50];
    double salary;
} Record;

// Define a structure for an index entry
typedef struct index_entry {
    int id;
    long offset;
} IndexEntry;

// Define a structure for the index
typedef struct index {
    IndexEntry* entries;
    int num_entries;
} Index;

// Function to create an index for the database
Index create_index(FILE* fp) {
    // Count number of records in the file
    fseek(fp, 0, SEEK_END);
    long filesize = ftell(fp);
    int num_records = filesize / sizeof(Record);
    fseek(fp, 0, SEEK_SET);
    
    // Allocate memory for the index entries
    IndexEntry* entries = (IndexEntry*) malloc(sizeof(IndexEntry) * num_records);
    
    // Read each record and store its offset in the index
    for (int i = 0; i < num_records; i++) {
        Record rec;
        fread(&rec, sizeof(Record), 1, fp);
        entries[i].id = rec.id;
        entries[i].offset = ftell(fp) - sizeof(Record);
    }
    
    // Create the index and return it
    Index idx = {.entries = entries, .num_entries = num_records};
    return idx;
}

// Function to get the record with a given ID using the index
Record get_record_with_id(Index idx, FILE* fp, int id) {
    // Binary search through the index for the ID
    int lo = 0;
    int hi = idx.num_entries - 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (idx.entries[mid].id == id) {
            // Found the ID, seek to the offset and read the record
            fseek(fp, idx.entries[mid].offset, SEEK_SET);
            Record rec;
            fread(&rec, sizeof(Record), 1, fp);
            return rec;
        } else if (idx.entries[mid].id < id) {
            // ID is in the upper half of the range
            lo = mid + 1;
        } else {
            // ID is in the lower half of the range
            hi = mid - 1;
        }
    }
    
    // ID not found
    Record nullrec = {.id = -1, .name = "", .salary = 0.0};
    return nullrec;
}


int main() {
    // Open the database file
    FILE* fp = fopen("employees.dat", "rb");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    
    // Create the index
    Index idx = create_index(fp);
    
    // Get a record from the database using the index
    int id = 42;
    Record rec = get_record_with_id(idx, fp, id);
    if (rec.id == -1) {
        printf("Record with ID %d not found\n", id);
    } else {
        printf("Record with ID %d:\n", id);
        printf("Name: %s\n", rec.name);
        printf("Salary: $%.2f\n", rec.salary);
    }
    
    // Clean up
    fclose(fp);
    free(idx.entries);
    
    return 0;
}