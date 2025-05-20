//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char **data;
    int rows;
    int cols;
} CSV;

// Function to split a string by delimiter
char *strsplit(char *str, char delimiter) {
    char *token = strtok(str, delimiter);
    return token;
}

// Function to read CSV file and store data in 2D array
CSV read_csv(FILE *fp) {
    CSV csv;
    char line[1024];
    int rows = 0;
    int cols = 0;

    // Read first line to determine number of columns
    fgets(line, sizeof(line), fp);
    char *token = strsplit(line, ',');
    cols = strlen(token);

    // Allocate memory for 2D array
    csv.data = (char **)malloc(rows * sizeof(char *));
    for (int i = 0; i < rows; i++) {
        csv.data[i] = (char *)malloc(cols * sizeof(char));
    }

    // Read remaining lines and store data in 2D array
    while (fgets(line, sizeof(line), fp)) {
        rows++;
        token = strsplit(line, ',');
        for (int j = 0; j < cols; j++) {
            strcpy(csv.data[rows - 1][j], token);
        }
    }

    csv.rows = rows;
    csv.cols = cols;

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

int main() {
    FILE *fp = fopen("example.csv", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    CSV csv = read_csv(fp);
    fclose(fp);

    print_csv(csv);

    for (int i = 0; i < csv.rows; i++) {
        for (int j = 0; j < csv.cols; j++) {
            free(csv.data[i][j]);
        }
        free(csv.data[i]);
    }
    free(csv.data);

    return 0;
}