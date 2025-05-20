//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold CSV data
typedef struct {
    char **data;
    int rows;
    int cols;
} CSV;

// Function to read CSV file
CSV read_csv(FILE *fp) {
    CSV csv = {NULL, 0, 0};
    char line[1024];
    char *token;
    int row = 0;
    int col = 0;

    // Read first line to get column count
    fgets(line, sizeof(line), fp);
    token = strtok(line, ",");
    while (token!= NULL) {
        col++;
        token = strtok(NULL, ",");
    }
    csv.cols = col;

    // Allocate memory for CSV data
    csv.data = malloc(sizeof(char *) * csv.rows);
    for (int i = 0; i < csv.rows; i++) {
        csv.data[i] = malloc(sizeof(char) * csv.cols);
    }

    // Read remaining lines to fill CSV data
    rewind(fp);
    while (fgets(line, sizeof(line), fp)!= NULL) {
        token = strtok(line, ",");
        row = 0;
        while (token!= NULL) {
            strcpy(csv.data[row], token);
            row++;
            token = strtok(NULL, ",");
        }
        row++;
    }
    csv.rows = row;

    return csv;
}

// Function to print CSV data
void print_csv(CSV csv) {
    for (int i = 0; i < csv.rows; i++) {
        for (int j = 0; j < csv.cols; j++) {
            printf("%s ", csv.data[i][j]);
        }
        printf("\n");
    }
}

// Function to free CSV data memory
void free_csv(CSV csv) {
    for (int i = 0; i < csv.rows; i++) {
        free(csv.data[i]);
    }
    free(csv.data);
}

int main() {
    FILE *fp;
    CSV csv;

    // Open CSV file
    fp = fopen("example.csv", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read CSV data from file
    csv = read_csv(fp);

    // Print CSV data
    printf("CSV Data:\n");
    print_csv(csv);

    // Free CSV data memory
    free_csv(csv);

    // Close CSV file
    fclose(fp);

    return 0;
}