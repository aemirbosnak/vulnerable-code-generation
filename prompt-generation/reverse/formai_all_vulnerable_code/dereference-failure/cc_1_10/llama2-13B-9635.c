//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_RECORDS 1000
#define MAX_NAME_LENGTH 50
#define MAX_AGE 100

// Structure to store a single record
typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} record_t;

// Function to read a record from the database
record_t *read_record(int record_number) {
    record_t *record = (record_t *)malloc(sizeof(record_t));
    FILE *file = fopen("records.dat", "r");
    if (file == NULL) {
        printf("Error opening file records.dat\n");
        return NULL;
    }
    // Read the record number and name from the file
    fscanf(file, "%d%s", &record->age, record->name);
    // Check if the record number is valid
    if (record_number > MAX_RECORDS || record_number < 1) {
        printf("Invalid record number\n");
        return NULL;
    }
    // Return the record
    return record;
}

// Function to write a record to the database
void write_record(int record_number, record_t *record) {
    FILE *file = fopen("records.dat", "w");
    if (file == NULL) {
        printf("Error opening file records.dat\n");
        return;
    }
    // Write the record number and name to the file
    fprintf(file, "%d%s", record->age, record->name);
    // Check if the record was written successfully
    if (fwrite(record, sizeof(record_t), 1, file) != 1) {
        printf("Error writing record to file\n");
    }
    fclose(file);
}

// Function to search for a record in the database
record_t *search_record(int record_number) {
    record_t *record = NULL;
    FILE *file = fopen("records.dat", "r");
    if (file == NULL) {
        printf("Error opening file records.dat\n");
        return NULL;
    }
    // Search for the record number in the file
    while (fscanf(file, "%d%s", &record->age, record->name) == 2) {
        if (record->age == record_number) {
            // Found the record, return it
            return record;
        }
    }
    // Not found, return NULL
    return NULL;
}

int main() {
    srand(time(NULL));
    // Create 100 records and write them to the database
    for (int i = 0; i < 100; i++) {
        record_t *record = (record_t *)malloc(sizeof(record_t));
        record->age = rand() % MAX_AGE + 1;
        strcpy(record->name, "Person ");
        strcat(record->name, (char)('A' + i));
        write_record(i + 1, record);
    }
    // Search for a record and print its name
    record_t *found_record = search_record(5);
    if (found_record != NULL) {
        printf("Found record %d: %s\n", found_record->age, found_record->name);
    } else {
        printf("Record not found\n");
    }
    return 0;
}