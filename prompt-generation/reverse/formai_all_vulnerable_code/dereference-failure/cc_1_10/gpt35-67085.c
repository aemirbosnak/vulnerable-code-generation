//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1024

// Define a struct to store CSV records
typedef struct {
    char **fields; // Array of fields
    int num_fields; // Number of fields
} CSVRecord;

// Define a function to create a new CSV record
CSVRecord *newCSVRecord() {
    CSVRecord *record = malloc(sizeof(CSVRecord));
    record->fields = NULL;
    record->num_fields = 0;
    return record;
}

// Define a function to free memory used by a CSV record
void freeCSVRecord(CSVRecord *record) {
    for (int i=0; i<record->num_fields; i++) {
        free(record->fields[i]);
    }
    free(record->fields);
    free(record);
}

// Define a function to read a CSV file and return an array of records
CSVRecord **readCSVFile(const char *filename, int *num_records) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file\n");
        return NULL;
    }

    // Allocate memory for records array
    CSVRecord **records = malloc(sizeof(CSVRecord *) * MAX_LENGTH);
    *num_records = 0;

    char line[MAX_LENGTH];
    while (fgets(line, MAX_LENGTH, fp) != NULL) {
        CSVRecord *record = newCSVRecord();
        record->fields = malloc(sizeof(char *) * MAX_LENGTH);

        char *field = strtok(line, ",\n");
        while (field != NULL) {
            record->fields[record->num_fields++] = strdup(field);
            field = strtok(NULL, ",\n");
        }

        records[(*num_records)++] = record;
    }

    fclose(fp);
    return records;
}

int main() {
    int num_records = 0;
    CSVRecord **records = readCSVFile("example.csv", &num_records);

    for (int i=0; i<num_records; i++) {
        for (int j=0; j<records[i]->num_fields; j++) {
            printf("%s\n", records[i]->fields[j]);
        }
        printf("\n");
    }

    for (int i=0; i<num_records; i++) {
        freeCSVRecord(records[i]);
    }
    free(records);

    return 0;
}