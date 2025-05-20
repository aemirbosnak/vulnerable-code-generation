//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_CELL_SIZE 1000

// Define a struct to hold the CSV data
typedef struct {
    char **rows;
    int num_rows;
    int num_cols;
} CSVData;

// Function to read in a CSV file and return the data as a 2D array
CSVData read_csv_file(FILE *fp) {
    CSVData data = {NULL, 0, 0};
    char line[MAX_CELL_SIZE];
    char *token;
    int row = 0;
    int col = 0;

    // Read in the first line to determine the number of columns
    fgets(line, MAX_CELL_SIZE, fp);
    token = strtok(line, ",");
    while (token!= NULL) {
        col++;
        token = strtok(NULL, ",");
    }

    // Allocate memory for the 2D array
    data.rows = (char **)malloc(row * sizeof(char *));
    for (int i = 0; i < row; i++) {
        data.rows[i] = (char *)malloc(col * sizeof(char));
    }

    // Read in the rest of the lines and populate the 2D array
    rewind(fp);
    while (fgets(line, MAX_CELL_SIZE, fp)!= NULL) {
        token = strtok(line, ",");
        for (int j = 0; j < col; j++) {
            strcpy(data.rows[row], token);
            row++;
            token = strtok(NULL, ",");
        }
        col = 0;
        row++;
    }

    data.num_rows = row;
    data.num_cols = col;

    return data;
}

// Function to print out the CSV data as a table
void print_csv_data(CSVData data) {
    for (int i = 0; i < data.num_rows; i++) {
        for (int j = 0; j < data.num_cols; j++) {
            printf("%s\t", data.rows[i]);
        }
        printf("\n");
    }
}

int main() {
    FILE *fp;
    CSVData data;

    // Open the CSV file
    fp = fopen("data.csv", "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    // Read in the CSV data
    data = read_csv_file(fp);

    // Print out the CSV data as a table
    printf("CSV Data:\n");
    print_csv_data(data);

    // Free the memory allocated for the 2D array
    for (int i = 0; i < data.num_rows; i++) {
        free(data.rows[i]);
    }
    free(data.rows);

    fclose(fp);

    return 0;
}