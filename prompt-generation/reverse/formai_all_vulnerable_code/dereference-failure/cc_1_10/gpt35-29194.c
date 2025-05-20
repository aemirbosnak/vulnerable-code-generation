//FormAI DATASET v1.0 Category: Database simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for database record
typedef struct {
    int id;
    char name[50];
    int age;
} Record;

// Define functions to interact with database
void insertRecord(FILE *file, Record record) {
    fseek(file, 0, SEEK_END);  // Move file pointer to end of file
    fwrite(&record, sizeof(Record), 1, file);  // Write record to file
}

Record* findRecord(FILE *file, int id) {
    Record *record = malloc(sizeof(Record));  // Allocate memory for record
    fseek(file, 0, SEEK_SET);  // Move file pointer to beginning of file

    // Loop through file and find record with matching ID
    while (fread(record, sizeof(Record), 1, file)) {
        if (record->id == id) {
            return record;
        }
    }

    free(record);  // Free memory if record not found
    return NULL;
}

void updateRecord(FILE *file, Record record) {
    Record *existingRecord = findRecord(file, record.id);  // Find existing record
    if (existingRecord != NULL) {
        fseek(file, -sizeof(Record), SEEK_CUR);  // Move file pointer back to beginning of record
        fwrite(&record, sizeof(Record), 1, file);  // Write updated record to file
    }
    free(existingRecord);  // Free memory used by existing record
}

// Main function to demonstrate database functionality
int main() {
    FILE *file = fopen("database.bin", "wb+");  // Open file for read/write in binary mode
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    // Insert records
    Record record1 = {1, "John Smith", 35};
    Record record2 = {2, "Anna Johnson", 27};
    Record record3 = {3, "Mike Davis", 45};
    insertRecord(file, record1);
    insertRecord(file, record2);
    insertRecord(file, record3);

    // Find and print record with ID 2
    Record *foundRecord = findRecord(file, 2);
    if (foundRecord != NULL) {
        printf("Record found: ID=%d, Name=%s, Age=%d\n", foundRecord->id, foundRecord->name, foundRecord->age);
    } else {
        printf("Record not found\n");
    }

    // Update record with ID 3
    Record updatedRecord = {3, "Mike Davis Jr.", 5};
    updateRecord(file, updatedRecord);

    // Find and print updated record with ID 3
    foundRecord = findRecord(file, 3);
    if (foundRecord != NULL) {
        printf("Record found: ID=%d, Name=%s, Age=%d\n", foundRecord->id, foundRecord->name, foundRecord->age);
    } else {
        printf("Record not found\n");
    }

    fclose(file);  // Close file
    return 0;
}