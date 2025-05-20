//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a record in the database
typedef struct record {
    char name[50];
    int age;
} Record;

// Function to add a new record to the database
void add_record(Record *record) {
    // Create a new file for the database
    FILE *db_file = fopen("database.db", "w");

    // Write the record to the database
    fprintf(db_file, "%s,%d\n", record->name, record->age);
    fclose(db_file);
}

// Function to search for a record in the database
int search_record(Record *record) {
    // Create a new file for the database
    FILE *db_file = fopen("database.db", "r");

    // Search for the record in the database
    char name[50];
    fgets(name, sizeof(name), db_file);
    fclose(db_file);

    // Compare the name of the record with the input name
    if (strcmp(record->name, name) == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    // Create a new record
    Record record;
    strcpy(record.name, "John Doe");
    record.age = 30;

    // Add the record to the database
    add_record(&record);

    // Search for the record in the database
    if (search_record(&record)) {
        printf("Record found!\n");
    } else {
        printf("Record not found.\n");
    }

    return 0;
}