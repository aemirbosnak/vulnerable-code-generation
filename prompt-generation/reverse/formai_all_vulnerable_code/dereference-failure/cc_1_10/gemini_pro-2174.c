//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a record in the database
typedef struct Record {
    int id;
    char *name;
    char *address;
    char *phone;
} Record;

// Structure to represent a database index
typedef struct Index {
    char *field;
    int *values;
    int *record_ids;
    int size;
} Index;

// Function to create a new database index
Index *create_index(char *field) {
    Index *index = malloc(sizeof(Index));
    index->field = field;
    index->values = malloc(sizeof(int));
    index->record_ids = malloc(sizeof(int));
    index->size = 0;
    return index;
}

// Function to add a new value to a database index
void add_index_value(Index *index, int value, int record_id) {
    index->values = realloc(index->values, (index->size + 1) * sizeof(int));
    index->record_ids = realloc(index->record_ids, (index->size + 1) * sizeof(int));
    index->values[index->size] = value;
    index->record_ids[index->size] = record_id;
    index->size++;
}

// Function to search a database index for a given value
int *search_index(Index *index, int value) {
    int *record_ids = malloc(sizeof(int));
    int record_count = 0;
    for (int i = 0; i < index->size; i++) {
        if (index->values[i] == value) {
            record_ids = realloc(record_ids, (record_count + 1) * sizeof(int));
            record_ids[record_count] = index->record_ids[i];
            record_count++;
        }
    }
    return record_ids;
}

// Function to create a new database record
Record *create_record(int id, char *name, char *address, char *phone) {
    Record *record = malloc(sizeof(Record));
    record->id = id;
    record->name = strdup(name);
    record->address = strdup(address);
    record->phone = strdup(phone);
    return record;
}

// Main function
int main() {
    // Create a database of records
    Record *records[] = {
        create_record(1, "John Doe", "123 Main Street", "555-1212"),
        create_record(2, "Jane Doe", "456 Elm Street", "555-1213"),
        create_record(3, "John Smith", "789 Oak Street", "555-1214")
    };

    // Create an index on the name field
    Index *name_index = create_index("name");

    // Add the records to the index
    for (int i = 0; i < 3; i++) {
        add_index_value(name_index, records[i]->id, i);
    }

    // Search the index for the name "John"
    int *record_ids = search_index(name_index, 1);

    // Print the records that match the search
    for (int i = 0; i < 2; i++) {
        printf("Record %d: %s\n", records[record_ids[i]]->id, records[record_ids[i]]->name);
    }

    // Free the memory allocated for the index and records
    free(name_index);
    for (int i = 0; i < 3; i++) {
        free(records[i]);
    }

    return 0;
}