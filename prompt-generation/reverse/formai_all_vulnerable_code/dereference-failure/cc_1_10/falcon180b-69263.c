//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_CELL_SIZE 1000

// Structure to hold CSV data
typedef struct {
    int num_rows;
    int num_cols;
    char **data;
} csv_data;

// Function to read CSV file
csv_data *read_csv(const char *filename) {
    FILE *fp;
    char line[MAX_CELL_SIZE];
    char *token;
    csv_data *csv;

    // Open file for reading
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file '%s'.\n", filename);
        exit(1);
    }

    // Read header row
    csv = malloc(sizeof(csv_data));
    csv->num_rows = 0;
    csv->num_cols = 0;
    csv->data = NULL;
    if (fgets(line, MAX_CELL_SIZE, fp) == NULL) {
        printf("Error: empty file '%s'.\n", filename);
        exit(1);
    }
    token = strtok(line, ",");
    while (token!= NULL) {
        csv->num_cols++;
        token = strtok(NULL, ",");
    }
    csv->data = malloc(csv->num_cols * sizeof(char *));
    rewind(fp);

    // Read data rows
    while (fgets(line, MAX_CELL_SIZE, fp)!= NULL) {
        csv->num_rows++;
        token = strtok(line, ",");
        int i = 0;
        while (token!= NULL && i < csv->num_cols) {
            csv->data[i] = malloc(strlen(token) + 1);
            strcpy(csv->data[i], token);
            token = strtok(NULL, ",");
            i++;
        }
    }

    fclose(fp);
    return csv;
}

// Function to print CSV data
void print_csv(csv_data *csv) {
    int i, j;
    for (i = 0; i < csv->num_rows; i++) {
        for (j = 0; j < csv->num_cols; j++) {
            printf("%s\t", csv->data[j * csv->num_rows + i]);
        }
        printf("\n");
    }
}

// Function to free CSV data
void free_csv(csv_data *csv) {
    int i;
    for (i = 0; i < csv->num_cols; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int main(int argc, char *argv[]) {
    csv_data *csv;

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    csv = read_csv(argv[1]);
    print_csv(csv);
    free_csv(csv);

    return 0;
}