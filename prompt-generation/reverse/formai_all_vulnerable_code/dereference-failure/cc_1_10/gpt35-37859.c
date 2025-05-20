//FormAI DATASET v1.0 Category: File handling ; Style: genious
#include <stdio.h>
#include <stdlib.h>

// Declare a struct to hold a record
struct Record {
    int id;
    char name[20];
    double balance;
};

// Function to create a new record
struct Record* createRecord(int id, char* name, double balance) {
    struct Record* record = (struct Record*) malloc(sizeof(struct Record));
    record->id = id;
    strcpy(record->name, name);
    record->balance = balance;
    return record;
}

int main() {
    FILE *file;

    struct Record* record;
    int id;
    char name[20];
    double balance;

    // Open the file for writing
    file = fopen("records.dat", "w");

    // Write some records to the file
    record = createRecord(12345, "John Smith", 1000.50);
    fwrite(record, sizeof(struct Record), 1, file);
    free(record);

    record = createRecord(23456, "Jane Doe", 500.25);
    fwrite(record, sizeof(struct Record), 1, file);
    free(record);

    // Close the file
    fclose(file);

    // Open the file for reading
    file = fopen("records.dat", "r");

    // Read the records from the file
    while (fread(record, sizeof(struct Record), 1, file) == 1) {
        printf("%d %s %.2f\n", record->id, record->name, record->balance);
    }

    // Close the file
    fclose(file);

    return 0;
}