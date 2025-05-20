//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Shape-shifting functions
int ConvertToInt(char* str) {
    // Convert a string to an integer
    return atoi(str);
}

double ConvertToDouble(char* str) {
    // Convert a string to a double precision floating-point number
    return atof(str);
}

// Data structure for storing CSV data
typedef struct {
    char** Rows;
    int NumRows;
    int NumCols;
} CSVData;

// Function to read CSV data from a file
CSVData ReadCSV(const char* filename) {
    // Open the file
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Unable to open CSV file!\n");
        exit(1);
    }

    // Allocate memory for the CSVData structure
    CSVData data;
    data.Rows = NULL;
    data.NumRows = 0;
    data.NumCols = 0;

    // Read the file line by line
    char line[1024];
    while (fgets(line, 1024, fp)) {
        // Remove the trailing newline character, if present
        char* end = strchr(line, '\n');
        if (end != NULL) {
            *end = '\0';
        }

        // Split the line into fields
        char* field = strtok(line, ",");
        int col = 0;
        while (field != NULL) {
            // If this is the first row, count the number of columns
            if (data.NumRows == 0) {
                data.NumCols++;
            }

            // Allocate memory for a new row, if necessary
            if (col == 0) {
                data.Rows = (char**)realloc(data.Rows, (data.NumRows + 1) * sizeof(char*));
                data.Rows[data.NumRows] = (char*)malloc(1024 * sizeof(char));
            }

            // Copy the field into the row
            strcpy(data.Rows[data.NumRows] + col * 16, field);

            // Move to the next field
            field = strtok(NULL, ",");
            col++;
        }

        // If this is not the first row, make sure it has the same number
        // of columns as the first row
        if (data.NumRows > 0 && col != data.NumCols) {
            printf("Error: CSV data has inconsistent number of columns!\n");
            exit(1);
        }

        // Move to the next row
        data.NumRows++;
    }

    // Close the file
    fclose(fp);

    // Return the CSV data
    return data;
}

// Example usage
int main() {
    // Read the CSV data
    CSVData data = ReadCSV("example.csv");

    // Print the data to the console
    for (int i = 0; i < data.NumRows; i++) {
        for (int j = 0; j < data.NumCols; j++) {
            // Shape-shift the data based on column type
            if (j == 0) {
                printf("%d", ConvertToInt(data.Rows[i] + j * 16));
            } else {
                printf("%.2f", ConvertToDouble(data.Rows[i] + j * 16));
            }

            // Print a comma, unless this is the last column
            if (j < data.NumCols - 1) {
                printf(",");
            }
        }

        // Print a newline
        printf("\n");
    }

    // Free the CSV data
    for (int i = 0; i < data.NumRows; i++) {
        free(data.Rows[i]);
    }
    free(data.Rows);

    return 0;
}