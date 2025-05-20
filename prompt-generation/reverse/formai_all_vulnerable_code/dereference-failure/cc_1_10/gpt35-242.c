//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of columns in the CSV file
#define MAX_COLS 10

// Define the maximum number of rows in the CSV file
#define MAX_ROWS 1000

// Define the maximum length of a cell in the CSV file
#define MAX_CELL_LEN 100

// Define the delimiter character for the CSV file
#define DELIM ','

// Function to parse the CSV file and store the data in a 2D array
int parse_csv_file(char* filename, char*** data, int* num_rows, int* num_cols) {
    int i, j;

    // Open the CSV file for reading
    FILE* fp = fopen(filename, "r");
    if (!fp) {
        printf("Error: Failed to open file '%s'\n", filename);
        return -1;
    }

    // Allocate memory for the 2D array
    *data = (char**)malloc(MAX_ROWS * sizeof(char*));
    for (i = 0; i < MAX_ROWS; i++) {
        (*data)[i] = (char*)malloc(MAX_COLS * MAX_CELL_LEN * sizeof(char));
    }

    // Read the CSV file line by line
    char line[MAX_COLS * MAX_CELL_LEN];
    i = 0;
    while (fgets(line, sizeof(line), fp) != NULL) {
        // Split the line into cells based on the delimiter
        char* cell = strtok(line, ",");
        j = 0;
        while (cell != NULL && j < MAX_COLS) {
            // Copy the cell into the 2D array
            strcpy((*data)[i * MAX_COLS + j], cell);
            cell = strtok(NULL, ",");
            j++;
        }
        i++;
    }

    // Close the CSV file
    fclose(fp);

    // Set the number of rows and columns
    *num_rows = i;
    *num_cols = j;

    return 0;
}

int main() {
    char** csv_data;
    int num_rows, num_cols;
    int i, j;

    // Parse the CSV file
    if (parse_csv_file("data.csv", &csv_data, &num_rows, &num_cols) != 0) {
        return -1;
    }

    // Print the CSV data
    for (i = 0; i < num_rows; i++) {
        for (j = 0; j < num_cols; j++) {
            printf("%s\t", csv_data[i * MAX_COLS + j]);
        }
        printf("\n");
    }

    return 0;
}