//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_CELL_SIZE 1000

// Struct to hold CSV data
typedef struct {
    int num_rows;
    int num_cols;
    char **data;
} CSV;

// Function to read CSV file and store data in CSV struct
CSV read_csv(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    CSV csv = {0};
    char line[MAX_CELL_SIZE];
    char delimiter = ',';

    // Read first line to determine number of columns
    fgets(line, MAX_CELL_SIZE, fp);
    int num_cols = 1;
    char *token = strtok(line, ",");
    while (token!= NULL) {
        num_cols++;
        token = strtok(NULL, ",");
    }
    csv.num_cols = num_cols;

    // Allocate memory for CSV data
    csv.data = malloc(sizeof(char *) * csv.num_rows);
    for (int i = 0; i < csv.num_rows; i++) {
        csv.data[i] = malloc(sizeof(char) * MAX_CELL_SIZE);
    }

    // Read remaining lines and store data in CSV struct
    rewind(fp);
    int num_rows = 0;
    while (fgets(line, MAX_CELL_SIZE, fp)!= NULL) {
        char *token = strtok(line, ",");
        for (int j = 0; j < csv.num_cols; j++) {
            strcpy(csv.data[num_rows][j], token);
            token = strtok(NULL, ",");
        }
        num_rows++;
    }
    csv.num_rows = num_rows;

    fclose(fp);
    return csv;
}

// Function to print CSV data
void print_csv(CSV csv) {
    for (int i = 0; i < csv.num_rows; i++) {
        for (int j = 0; j < csv.num_cols; j++) {
            printf("%s ", csv.data[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    CSV csv = read_csv(argv[1]);
    print_csv(csv);

    for (int i = 0; i < csv.num_rows; i++) {
        for (int j = 0; j < csv.num_cols; j++) {
            free(csv.data[i][j]);
        }
        free(csv.data[i]);
    }
    free(csv.data);

    return 0;
}