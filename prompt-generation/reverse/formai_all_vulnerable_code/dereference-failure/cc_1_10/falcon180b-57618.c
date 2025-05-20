//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define DELIM ","

// Struct to hold CSV data
typedef struct {
    int num_rows;
    int num_cols;
    char **data;
} CSV;

// Function to create a new CSV object
CSV *csv_create() {
    CSV *csv = malloc(sizeof(CSV));
    csv->num_rows = 0;
    csv->num_cols = 0;
    csv->data = NULL;
    return csv;
}

// Function to free a CSV object
void csv_free(CSV *csv) {
    if (csv!= NULL) {
        for (int i = 0; i < csv->num_rows; i++) {
            free(csv->data[i]);
        }
        free(csv->data);
        free(csv);
    }
}

// Function to read a CSV file into a CSV object
CSV *csv_read(FILE *fp) {
    CSV *csv = csv_create();
    char line[MAX_ROWS];
    char *token;
    int row = 0;
    int col = 0;

    // Count the number of columns in the first row
    while (fgets(line, MAX_ROWS, fp)!= NULL && row == 0) {
        token = strtok(line, DELIM);
        while (token!= NULL) {
            col++;
            token = strtok(NULL, DELIM);
        }
        row++;
    }

    // Allocate memory for the CSV data
    csv->num_rows = row;
    csv->num_cols = col;
    csv->data = malloc(sizeof(char *) * row);

    // Read the CSV data
    rewind(fp);
    row = 0;
    while (fgets(line, MAX_ROWS, fp)!= NULL) {
        csv->data[row] = malloc(MAX_ROWS * sizeof(char));
        token = strtok(line, DELIM);
        col = 0;
        while (token!= NULL) {
            strcpy(csv->data[row] + col * MAX_ROWS, token);
            col++;
            token = strtok(NULL, DELIM);
        }
        row++;
    }

    return csv;
}

// Function to print a CSV object
void csv_print(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->num_cols; j++) {
            printf("%s ", csv->data[i] + j * MAX_ROWS);
        }
        printf("\n");
    }
}

// Main function
int main() {
    FILE *fp;
    CSV *csv;

    // Open the CSV file
    fp = fopen("data.csv", "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    // Read the CSV data
    csv = csv_read(fp);

    // Print the CSV data
    printf("CSV data:\n");
    csv_print(csv);

    // Free the CSV object
    csv_free(csv);

    // Close the CSV file
    fclose(fp);

    return 0;
}