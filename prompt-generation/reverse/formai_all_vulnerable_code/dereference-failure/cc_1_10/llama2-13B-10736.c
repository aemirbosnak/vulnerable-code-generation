//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DB_NAME "mydatabase"
#define DB_SIZE 1000

// Structure to represent a record in the database
typedef struct {
    char name[50];
    int age;
} record_t;

// Function to insert a record into the database
void insert_record(record_t* rec) {
    // Open the database file in write mode
    FILE* db_file = fopen(DB_NAME, "wb");
    if (!db_file) {
        perror("Failed to open database file");
        return;
    }

    // Write the record to the database file
    fwrite(rec, sizeof(record_t), 1, db_file);

    // Close the database file
    fclose(db_file);
}

// Function to search for a record in the database
record_t* search_record(char* name) {
    // Open the database file in read mode
    FILE* db_file = fopen(DB_NAME, "rb");
    if (!db_file) {
        perror("Failed to open database file");
        return NULL;
    }

    // Read the record from the database file
    record_t rec;
    fread(&rec, sizeof(record_t), 1, db_file);

    // Check if the record matches the name
    if (strcmp(rec.name, name) == 0) {
        // Return the matching record
        return &rec;
    }

    // Close the database file
    fclose(db_file);
    return NULL;
}

// Function to update a record in the database
void update_record(char* name, int age) {
    // Find the record in the database
    record_t* rec = search_record(name);
    if (!rec) {
        printf("Record not found\n");
        return;
    }

    // Update the age of the record
    rec->age = age;

    // Overwrite the record in the database file
    insert_record(rec);
}

int main() {
    // Create some sample records
    record_t rec1 = {"Alice", 25};
    record_t rec2 = {"Bob", 30};
    record_t rec3 = {"Charlie", 35};

    // Insert the records into the database
    insert_record(&rec1);
    insert_record(&rec2);
    insert_record(&rec3);

    // Search for a record
    record_t* found_rec = search_record("Alice");
    if (found_rec) {
        printf("Found record: %s %d\n", found_rec->name, found_rec->age);
    } else {
        printf("Record not found\n");
    }

    // Update a record
    update_record("Bob", 35);

    // Search for the updated record
    found_rec = search_record("Bob");
    if (found_rec) {
        printf("Updated record: %s %d\n", found_rec->name, found_rec->age);
    } else {
        printf("Record not found\n");
    }

    return 0;
}