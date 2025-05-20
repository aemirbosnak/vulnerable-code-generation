//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold the CSV data
typedef struct {
    char **fields;
    int num_fields;
} CSVRow;

// Function to read a CSV file and return a list of CSVRow structs
CSVRow *read_csv_file(const char *filename) {
    // Open the CSV file
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening CSV file");
        return NULL;
    }

    // Allocate memory for the list of CSVRow structs
    CSVRow *rows = malloc(sizeof(CSVRow));
    if (rows == NULL) {
        perror("Error allocating memory for CSV rows");
        fclose(fp);
        return NULL;
    }

    // Read the first line of the CSV file to get the number of fields
    char line[1024];
    if (fgets(line, sizeof(line), fp) == NULL) {
        perror("Error reading first line of CSV file");
        free(rows);
        fclose(fp);
        return NULL;
    }

    // Split the first line into fields
    char *fields[100];
    int num_fields = 0;
    char *field = strtok(line, ",");
    while (field != NULL) {
        fields[num_fields++] = field;
        field = strtok(NULL, ",");
    }

    // Allocate memory for the fields in each CSVRow struct
    for (int i = 0; i < num_fields; i++) {
        rows->fields[i] = malloc(strlen(fields[i]) + 1);
        if (rows->fields[i] == NULL) {
            perror("Error allocating memory for CSV fields");
            for (int j = 0; j < i; j++) {
                free(rows->fields[j]);
            }
            free(rows);
            fclose(fp);
            return NULL;
        }
    }

    // Read the rest of the lines in the CSV file
    int row_count = 0;
    while (fgets(line, sizeof(line), fp) != NULL) {
        // Split the line into fields
        field = strtok(line, ",");
        for (int i = 0; i < num_fields; i++) {
            strcpy(rows[row_count].fields[i], field);
            field = strtok(NULL, ",");
        }

        // Increment the row count
        row_count++;
    }

    // Close the CSV file
    fclose(fp);

    // Return the list of CSVRow structs
    return rows;
}

// Function to free the memory allocated for the CSVRow structs
void free_csv_rows(CSVRow *rows, int num_rows) {
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < rows[i].num_fields; j++) {
            free(rows[i].fields[j]);
        }
        free(rows[i].fields);
    }
    free(rows);
}

// Main function
int main() {
    // Read the CSV file
    CSVRow *rows = read_csv_file("data.csv");
    if (rows == NULL) {
        return EXIT_FAILURE;
    }

    // Print the CSV data
    for (int i = 0; i < rows[0].num_fields; i++) {
        printf("%s", rows[0].fields[i]);
    }
    printf("\n");
    for (int i = 1; i < rows[0].num_fields; i++) {
        for (int j = 0; j < rows[i].num_fields; j++) {
            printf("%s", rows[i].fields[j]);
        }
        printf("\n");
    }

    // Free the memory allocated for the CSVRow structs
    free_csv_rows(rows, 3);

    return EXIT_SUCCESS;
}