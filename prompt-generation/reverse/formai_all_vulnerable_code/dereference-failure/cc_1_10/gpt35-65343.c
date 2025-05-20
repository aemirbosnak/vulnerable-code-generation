//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

// Define a struct to hold each record in the CSV file
typedef struct {
    char* name;
    int age;
    float salary;
} Record;

// Function to read a CSV file and return an array of records
Record* read_csv_file(const char* filename, int* num_records) {
    FILE* fp;
    char buffer[BUFFER_SIZE];
    char* token;
    char* name;
    int age;
    float salary;
    int record_count = 0;
    Record* records = NULL;
    
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Failed to open file %s\n", filename);
        return NULL;
    }
    
    // Read the file line by line
    while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
        // Parse each line into fields using strtok
        name = strtok(buffer, ",");
        age = atoi(strtok(NULL, ","));
        salary = atof(strtok(NULL, ","));

        // Allocate space for a new record
        Record* new_record = (Record*)malloc(sizeof(Record));
        new_record->name = strdup(name);
        new_record->age = age;
        new_record->salary = salary;

        // Add the new record to the array
        record_count++;
        records = (Record*)realloc(records, record_count * sizeof(Record));
        records[record_count-1] = *new_record;
    }

    // Close the file
    fclose(fp);

    // Set the output parameter num_records
    *num_records = record_count;

    // Return the array of records
    return records;
}

// Example usage
int main() {
    int num_records;
    Record* records = read_csv_file("example.csv", &num_records);
    if (records == NULL) {
        return 1;
    }

    // Print the records
    for (int i = 0; i < num_records; i++) {
        printf("%s,%d,%.2f\n", records[i].name, records[i].age, records[i].salary);
    }

    // Free the records
    for (int i = 0; i < num_records; i++) {
        free(records[i].name);
    }
    free(records);

    return 0;
}