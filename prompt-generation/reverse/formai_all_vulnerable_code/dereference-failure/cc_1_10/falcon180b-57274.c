//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char **data;
    int rows;
    int cols;
} CSV;

// Function to create a new CSV object
CSV *csv_create() {
    CSV *csv = malloc(sizeof(CSV));
    csv->data = NULL;
    csv->rows = 0;
    csv->cols = 0;
    return csv;
}

// Function to read a CSV file and populate the CSV object
void csv_read(CSV *csv, FILE *file) {
    char line[1024];
    char *token = NULL;
    int i = 0, j = 0;

    // Count the number of rows and columns
    while (fgets(line, sizeof(line), file)) {
        csv->rows++;

        token = strtok(line, ",");
        while (token!= NULL) {
            csv->cols = j + 1;
            j++;
            token = strtok(NULL, ",");
        }
        i++;
    }

    csv->data = malloc(csv->rows * sizeof(char *));
    for (int k = 0; k < csv->rows; k++) {
        csv->data[k] = malloc(csv->cols * sizeof(char));
    }

    rewind(file);
    i = 0;
    while (fgets(line, sizeof(line), file)) {
        token = strtok(line, ",");
        j = 0;
        while (token!= NULL) {
            strcpy(csv->data[i][j], token);
            j++;
            token = strtok(NULL, ",");
        }
        i++;
    }
}

// Function to print the CSV data
void csv_print(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            printf("%s ", csv->data[i][j]);
        }
        printf("\n");
    }
}

// Function to free the memory allocated for the CSV object
void csv_destroy(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int main() {
    FILE *file = fopen("example.csv", "r");
    CSV *csv = csv_create();
    csv_read(csv, file);
    csv_print(csv);
    csv_destroy(csv);
    return 0;
}