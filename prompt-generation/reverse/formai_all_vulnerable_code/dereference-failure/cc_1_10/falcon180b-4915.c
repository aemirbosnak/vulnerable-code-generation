//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Struct to hold CSV data
typedef struct {
    char **data;
    int rows;
    int cols;
} CSV;

// Function to create a new CSV object
CSV *csv_create(void) {
    CSV *csv = (CSV *) malloc(sizeof(CSV));
    csv->data = NULL;
    csv->rows = 0;
    csv->cols = 0;
    return csv;
}

// Function to free a CSV object
void csv_free(CSV *csv) {
    int i;
    for (i = 0; i < csv->rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

// Function to read a CSV file
CSV *csv_read(const char *filename) {
    FILE *fp;
    char line[1024];
    char *token;
    CSV *csv = csv_create();

    fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        exit(1);
    }

    // Read header row
    fgets(line, sizeof(line), fp);
    csv->cols = count_tokens(line);
    csv->data = (char **) malloc(csv->cols * sizeof(char *));
    csv->rows = 0;

    // Read data rows
    while (fgets(line, sizeof(line), fp)!= NULL) {
        csv->rows++;
        csv->data = (char **) realloc(csv->data, csv->rows * csv->cols * sizeof(char *));
        token = strtok(line, ",");
        int i = 0;
        while (token!= NULL) {
            csv->data[csv->rows - 1][i] = strdup(token);
            i++;
            token = strtok(NULL, ",");
        }
    }

    fclose(fp);
    return csv;
}

// Function to count the number of tokens in a string
int count_tokens(const char *str) {
    int count = 0;
    char *token = strtok(str, ",");
    while (token!= NULL) {
        count++;
        token = strtok(NULL, ",");
    }
    return count;
}

// Function to print a CSV object
void csv_print(CSV *csv) {
    int i, j;
    for (i = 0; i < csv->rows; i++) {
        for (j = 0; j < csv->cols; j++) {
            printf("%s ", csv->data[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main(int argc, char *argv[]) {
    CSV *csv = csv_read("data.csv");
    csv_print(csv);
    csv_free(csv);
    return 0;
}