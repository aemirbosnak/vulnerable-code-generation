//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DB_NAME "thompsons_database"
#define MAX_RECORDS 100
#define RECORD_SIZE 50

// Structure to hold a single record
struct record {
    char name[50];
    int age;
    float salary;
};

// Function to read and write records to the database
void write_record(struct record *record) {
    // Open the database file in write mode
    FILE *db_file = fopen(DB_NAME, "w");

    // Write the record to the database file
    fwrite(record, sizeof(struct record), 1, db_file);

    // Close the database file
    fclose(db_file);
}

// Function to read records from the database
struct record *read_record() {
    // Open the database file in read mode
    FILE *db_file = fopen(DB_NAME, "r");

    // Read a record from the database file
    struct record record;
    fread(&record, sizeof(struct record), 1, db_file);

    // Close the database file
    fclose(db_file);

    return &record;
}

int main() {
    // Create some sample records
    struct record record1 = {
        .name = "Ken",
        .age = 42,
        .salary = 100000.0f
    };

    struct record record2 = {
        .name = "Ada",
        .age = 35,
        .salary = 75000.0f
    };

    // Write the records to the database
    write_record(&record1);
    write_record(&record2);

    // Read the records from the database
    struct record *record = read_record();
    printf("%s %d %f\n", record->name, record->age, record->salary);

    return 0;
}