//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_CELL_SIZE 1024

// Struct to hold CSV data
typedef struct {
    char **rows;
    int num_rows;
    int num_cols;
} CSVData;

// Function to read CSV file
CSVData read_csv(FILE *fp) {
    CSVData csv_data;
    csv_data.num_rows = 0;
    csv_data.num_cols = 0;
    csv_data.rows = NULL;

    // Read first line to determine number of columns
    char line[MAX_CELL_SIZE];
    fgets(line, MAX_CELL_SIZE, fp);
    char *token = strtok(line, ",");
    while (token!= NULL) {
        csv_data.num_cols++;
        token = strtok(NULL, ",");
    }

    // Allocate memory for rows and read data
    csv_data.rows = malloc(csv_data.num_rows * sizeof(char *));
    for (int i = 0; i < csv_data.num_rows; i++) {
        csv_data.rows[i] = malloc(csv_data.num_cols * MAX_CELL_SIZE);
    }
    rewind(fp);
    int row = 0;
    while (fgets(line, MAX_CELL_SIZE, fp)!= NULL) {
        char *token = strtok(line, ",");
        int col = 0;
        while (token!= NULL) {
            strncpy(csv_data.rows[row][col], token, MAX_CELL_SIZE);
            col++;
            token = strtok(NULL, ",");
        }
        row++;
    }

    return csv_data;
}

// Function to print CSV data
void print_csv(CSVData csv_data) {
    for (int i = 0; i < csv_data.num_rows; i++) {
        for (int j = 0; j < csv_data.num_cols; j++) {
            printf("%s\t", csv_data.rows[i][j]);
        }
        printf("\n");
    }
}

// Function to free CSV data memory
void free_csv(CSVData csv_data) {
    for (int i = 0; i < csv_data.num_rows; i++) {
        free(csv_data.rows[i]);
    }
    free(csv_data.rows);
}

int main() {
    FILE *fp;
    fp = fopen("example.csv", "r");

    if (fp == NULL) {
        printf("Error: File not found or could not be opened.\n");
        exit(1);
    }

    CSVData csv_data = read_csv(fp);
    print_csv(csv_data);
    free_csv(csv_data);

    fclose(fp);
    return 0;
}