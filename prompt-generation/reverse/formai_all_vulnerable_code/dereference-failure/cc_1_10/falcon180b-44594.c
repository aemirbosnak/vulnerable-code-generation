//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a record
typedef struct {
    int id;
    char name[50];
} Record;

// Define the structure of an index
typedef struct {
    int size;
    int count;
    Record *records;
} Index;

// Function to create a new index
Index *create_index(int size) {
    Index *index = (Index *) malloc(sizeof(Index));
    index->size = size;
    index->count = 0;
    index->records = (Record *) malloc(sizeof(Record) * size);
    return index;
}

// Function to insert a record into an index
void insert_record(Index *index, Record record) {
    if (index->count == index->size) {
        printf("Error: index is full\n");
        return;
    }
    index->records[index->count++] = record;
}

// Function to search for a record in an index
Record *search_record(Index *index, int id) {
    for (int i = 0; i < index->count; i++) {
        if (index->records[i].id == id) {
            return &index->records[i];
        }
    }
    return NULL;
}

// Function to delete a record from an index
void delete_record(Index *index, int id) {
    Record *record = search_record(index, id);
    if (record!= NULL) {
        for (int i = 0; i < index->count; i++) {
            if (i!= index->records[i].id) {
                index->records[i] = index->records[index->count - 1];
            }
            index->count--;
        }
    }
}

// Function to print the records in an index
void print_records(Index *index) {
    for (int i = 0; i < index->count; i++) {
        printf("%d: %s\n", index->records[i].id, index->records[i].name);
    }
}

int main() {
    // Create an index with a size of 10
    Index *index = create_index(10);

    // Insert some records
    insert_record(index, (Record) {1, "Alice"});
    insert_record(index, (Record) {2, "Bob"});
    insert_record(index, (Record) {3, "Charlie"});

    // Search for a record
    Record *record = search_record(index, 2);
    if (record!= NULL) {
        printf("Found record: %s\n", record->name);
    } else {
        printf("Record not found\n");
    }

    // Delete a record
    delete_record(index, 2);

    // Print the remaining records
    print_records(index);

    return 0;
}