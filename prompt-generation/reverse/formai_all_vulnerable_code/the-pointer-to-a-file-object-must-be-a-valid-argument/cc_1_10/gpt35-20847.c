//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024 // Assumes longest line will be less than 1024 characters
#define MAX_NUM_FIELDS 50 // Assumes each row has less than 50 fields

// Define a struct to hold the CSV data
struct CSVRecord {
    char **fields;
    int numFields;
};

// Function to parse a CSV line into an array of strings
char **parseCSVLine(char *line, int *numFields) {
    char **fields = malloc(sizeof(char *) * MAX_NUM_FIELDS); // Allocate memory for fields

    char *token = strtok(line, ","); // Get first token using comma as delimiter

    int fieldCount = 0;
    while (token != NULL) {
        fields[fieldCount] = strdup(token); // Duplicate the token and store it in fields array
        fieldCount++;

        token = strtok(NULL, ","); // Get next token using comma as delimiter
    }

    *numFields = fieldCount;

    return fields;
}

// Function to read a CSV file and return an array of CSV records
struct CSVRecord *readCSVFile(char *filename, int *numRecords) {
    FILE *file = fopen(filename, "r"); // Open the file in read-only mode

    struct CSVRecord *records = malloc(sizeof(struct CSVRecord) * MAX_NUM_FIELDS); // Allocate memory for CSV records

    char line[MAX_LINE_LENGTH]; // Buffer to hold each line of the file

    int recordCount = 0;

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) { // Read until end of file
        int numFields;
        char **fields = parseCSVLine(line, &numFields); // Parse the line into an array of strings

        struct CSVRecord record = {fields, numFields}; // Create a CSV record struct from the parsed data
        records[recordCount] = record; // Add the record to the array of records

        recordCount++;
    }

    *numRecords = recordCount;

    fclose(file); // Close the file

    return records;
}

// Function to free memory allocated for CSV records
void freeCSVRecords(struct CSVRecord *records, int numRecords) {
    for (int i = 0; i < numRecords; i++) {
        for (int j = 0; j < records[i].numFields; j++) {
            free(records[i].fields[j]); // Free memory for each field in the record
        }

        free(records[i].fields); // Free memory for the fields array in the record
    }

    free(records); // Free memory for the records array
}

int main() {
    int numRecords;
    struct CSVRecord *records = readCSVFile("example.csv", &numRecords); // Read the CSV file

    for (int i = 0; i < numRecords; i++) {
        for (int j = 0; j < records[i].numFields; j++) {
            printf("%s\t", records[i].fields[j]); // Print each field in the record
        }
        printf("\n");
    }

    freeCSVRecords(records, numRecords); // Free memory allocated for CSV records

    return 0; // Exit the program with status code 0
}