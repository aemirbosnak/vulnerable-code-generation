//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define MAX_RECORDS 1000
#define RECORD_SIZE 50

// Structure to hold a single record
typedef struct record {
    char name[50];
    int age;
} record_t;

// Function to allocate and initialize memory for records
record_t * allocate_records(int num_records) {
    record_t *records = (record_t *)malloc(num_records * sizeof(record_t));
    for (int i = 0; i < num_records; i++) {
        records[i].name[0] = '\0';
        records[i].age = 0;
    }
    return records;
}

// Function to insert a record into the database
int insert_record(record_t *records, int num_records, char *name, int age) {
    for (int i = 0; i < num_records; i++) {
        if (strcmp(records[i].name, name) == 0) {
            records[i].age = age;
            return 0; // Record already exists, return 0
        }
    }
    // Record does not exist, allocate a new record and insert it
    record_t new_record = { .name = name, .age = age };
    memcpy(&records[num_records], &new_record, sizeof(record_t));
    num_records++;
    return 1; // New record inserted, return 1
}

// Function to search for a record in the database
int search_record(record_t *records, int num_records, char *name) {
    for (int i = 0; i < num_records; i++) {
        if (strcmp(records[i].name, name) == 0) {
            return i; // Record found, return index
        }
    }
    return -1; // Record not found, return -1
}

// Function to update a record in the database
int update_record(record_t *records, int num_records, int index, char *name, int age) {
    if (index < 0 || index >= num_records) {
        return -1; // Invalid index, return -1
    }
    record_t *record = &records[index];
    strcpy(record->name, name);
    record->age = age;
    return 0; // Record updated successfully, return 0
}

// Function to delete a record from the database
int delete_record(record_t *records, int num_records, int index) {
    if (index < 0 || index >= num_records) {
        return -1; // Invalid index, return -1
    }
    memmove(&records[index], &records[index + 1], (num_records - index - 1) * sizeof(record_t));
    num_records--;
    return 0; // Record deleted successfully, return 0
}

int main() {
    record_t *records = allocate_records(MAX_RECORDS);
    int num_records = 0;

    // Insert some records
    insert_record(records, num_records, "Alice", 25);
    insert_record(records, num_records, "Bob", 30);
    insert_record(records, num_records, "Charlie", 35);

    // Search for a record
    int index = search_record(records, num_records, "Alice");
    if (index >= 0) {
        printf("Found record at index %d\n", index);
    } else {
        printf("Record not found\n");
    }

    // Update a record
    update_record(records, num_records, index, "Alice", 30);

    // Delete a record
    delete_record(records, num_records, index);

    // Print the remaining records
    for (int i = 0; i < num_records; i++) {
        printf("%d: %s, %d\n", i, records[i].name, records[i].age);
    }

    free(records);
    return 0;
}