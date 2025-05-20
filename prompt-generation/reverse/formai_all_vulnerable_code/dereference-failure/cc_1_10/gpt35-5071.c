//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for holding CSV data
typedef struct {
    char name[50];
    int age;
    char email[50];
} CSVRow;

// Define a function for parsing a CSV row
CSVRow *parse_csv_row(char *row) {
    // Allocate memory for a new CSVRow struct
    CSVRow *csv_row = (CSVRow *) malloc(sizeof(CSVRow));

    // Initialize variables for parsing
    char *field = strtok(row, ",");
    int field_num = 0;

    // Iterate through fields in the row
    while (field != NULL) {
        switch (field_num) {
            case 0:
                // Copy the name field into the CSVRow struct
                strcpy(csv_row->name, field);
                break;
            case 1:
                // Convert the age field to an integer and copy it into the CSVRow struct
                csv_row->age = atoi(field);
                break;
            case 2:
                // Copy the email field into the CSVRow struct
                strcpy(csv_row->email, field);
                break;
            default:
                // Ignore any extra fields
                break;
        }

        // Move on to the next field
        field = strtok(NULL, ",");
        field_num++;
    }

    return csv_row;
}

int main() {
    // Open the CSV file for reading
    FILE *csv_file = fopen("people.csv", "r");

    // Check that the file opened successfully
    if (csv_file == NULL) {
        printf("Error: could not open CSV file\n");
        return 1;
    }

    // Initialize the header row
    char header_row[50];
    fgets(header_row, 50, csv_file);

    // Read through the rest of the CSV rows
    char row[50];
    while (fgets(row, 50, csv_file)) {
        // Parse the current row
        CSVRow *csv_row = parse_csv_row(row);

        // Print out the CSVRow data
        printf("%s (%d years old) - %s\n", csv_row->name, csv_row->age, csv_row->email);

        // Free the memory used by the CSVRow struct
        free(csv_row);
    }

    // Close the CSV file
    fclose(csv_file);

    return 0;
}