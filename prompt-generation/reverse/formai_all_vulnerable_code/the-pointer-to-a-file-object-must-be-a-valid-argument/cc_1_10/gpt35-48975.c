//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_FIELD_LENGTH 100

int main() {

    // Open the CSV file in read mode
    FILE* csv_file = fopen("example.csv", "r");

    // Declare variables to hold CSV data
    char line[MAX_LINE_LENGTH];
    char *field;
    char fields[MAX_FIELD_LENGTH][MAX_FIELD_LENGTH];
    int field_count = 0;

    // Read the first line of the CSV file to get the headers
    fgets(line, MAX_LINE_LENGTH, csv_file);

    // Parse the headers
    field = strtok(line, ",");
    while (field != NULL) {
        strcpy(fields[field_count], field);
        field_count++;
        field = strtok(NULL, ",");
    }

    // Read the rest of the CSV file
    while (fgets(line, MAX_LINE_LENGTH, csv_file)) {

        // Parse the line into fields
        field = strtok(line, ",");
        field_count = 0;
        while (field != NULL) {
            strcpy(fields[field_count], field);
            field_count++;
            field = strtok(NULL, ",");
        }

        // Print out the data in CSV format
        for (int i = 0; i < field_count; i++) {
            printf("%s", fields[i]);
            if (i < field_count - 1) {
                printf(",");
            }
        }
        printf("\n");
    }

    // Close the CSV file
    fclose(csv_file);

    return 0;
}